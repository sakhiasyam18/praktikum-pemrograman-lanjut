# // optimized_rk.py
import os
import pandas as pd
import time
import kagglehub

# --- 1. Fungsi Pemuat Data (Dataset TOXIC) ---

def load_toxic_corpus(dataset_path: str) -> str:
    """Memuat dataset Jigsaw Toxic Comment dan menggabungkannya"""
    print(f"Memuat data dari: {dataset_path}...")
    all_comments = []
    try:
        # File utamanya adalah train.csv
        file_path = os.path.join(dataset_path, "train.csv")
        df = pd.read_csv(file_path)
        
        # Kolomnya bernama 'comment_text'
        if 'comment_text' in df.columns:
            all_comments = list(df['comment_text'].dropna().astype(str))
            print(f"Total komentar dimuat: {len(all_comments):,}")
            # Gabung semua jadi 1 teks besar dan ubah ke huruf kecil
            corpus = " ".join(all_comments).lower()
            print(f"Total karakter dalam corpus: {len(corpus):,}")
            return corpus
        else:
            print("Error: Kolom 'comment_text' tidak ditemukan.")
            return ""
        
    except Exception as e:
        print(f"Error saat memuat data: {e}")
        return ""

# --- 2. Fungsi Inti Rabin-Karp Multi-Pattern ---

def rabin_karp_multi_search(text: str, patterns: list[str]) -> dict:
    """
    Mencari SEMUA pola dalam teks menggunakan Rabin-Karp 
    dengan mengelompokkan pola berdasarkan panjangnya.
    """
    n = len(text)
    results = {p: [] for p in patterns}
    
    # 1. Kelompokkan pola berdasarkan panjangnya
    patterns_by_length = {}
    for p in patterns:
        m = len(p)
        if m == 0 or m > n: continue
        if m not in patterns_by_length:
            patterns_by_length[m] = set()
        patterns_by_length[m].add(p)

    # Konstanta untuk hash
    RADIX = 256  # Jumlah kemungkinan karakter (ASCII)
    PRIME = 1000000007 # Bilangan prima besar untuk modulus

    # 2. Iterasi untuk setiap PANJANG pola yang unik
    for m, pattern_set in patterns_by_length.items():
        
        print(f"  -> Memproses {len(pattern_set)} pola dengan panjang {m}...")
        
        # --- Pre-calculation ---
        pattern_hashes = {} # {hash_value: [pattern1, pattern2_dst]}
        h_pow = pow(RADIX, m - 1, PRIME) # (RADIX^(m-1)) % PRIME

        # Hitung hash untuk setiap pola di grup ini
        for pattern in pattern_set:
            pattern_hash = 0
            for char in pattern:
                pattern_hash = (pattern_hash * RADIX + ord(char)) % PRIME
            
            if pattern_hash not in pattern_hashes:
                pattern_hashes[pattern_hash] = []
            pattern_hashes[pattern_hash].append(pattern) # Simpan di hash map

        # --- Rolling Hash Search (Satu kali pass per 'm') ---
        text_hash = 0
        # Hitung hash untuk window teks pertama
        for i in range(m):
            text_hash = (text_hash * RADIX + ord(text[i])) % PRIME
            
        # Geser window di sepanjang teks
        for i in range(n - m + 1):
            # Cek jika hash cocok
            if text_hash in pattern_hashes:
                # Hash cocok! Ini bisa jadi temuan atau collision.
                # Lakukan verifikasi (mitigasi collision)
                current_text_window = text[i : i+m]
                for pattern in pattern_hashes[text_hash]:
                    if current_text_window == pattern:
                        results[pattern].append(i) # Ditemukan!

            # Hitung rolling hash untuk window berikutnya
            if i < n - m:
                hash_to_remove = (ord(text[i]) * h_pow) % PRIME
                text_hash = (text_hash - hash_to_remove + PRIME) % PRIME
                text_hash = (text_hash * RADIX + ord(text[i + m])) % PRIME
                
    return results

# --- 3. Eksekusi Utama Optimized ---

print("Mulai eksekusi Optimized (Rabin-Karp Multi-Pattern)...")

# Download dataset (otomatis mencari token API Anda)
print("Mengunduh dataset 'jigsaw-toxic-comment-classification-challenge'...")
try:
    # Ganti handle dataset ke dataset Jigsaw
    path_to_dataset = kagglehub.dataset_download("jigsaw-toxic-comment-classification-challenge", "data")
    print(f"Dataset ada di: {path_to_dataset}")

    # Daftar pola baru yang relevan dengan dataset toxic
    patterns = [
        "fuck",
        "stupid",
        "suck",
        "idiot",
        "nigger",
        "asshole",
        "die",
        "go away",
        "shut up",
        "you are gay"
    ]

    # Muat Teks
    text_corpus = load_toxic_corpus(path_to_dataset)

    if text_corpus:
        print("\n--- Memulai Pencarian Optimized (Rabin-Karp) ---")
        
        start_time = time.time()
        
        # Logika Optimized: Cukup panggil fungsi multi-search SATU KALI
        all_results = rabin_karp_multi_search(text_corpus, patterns)
            
        end_time = time.time()
        total_time = end_time - start_time
        corpus_length = len(text_corpus)
        throughput = (corpus_length / total_time) if total_time > 0 else 0
        
        print("\n--- Ringkasan Kinerja (Optimized) ---")
        print(f"Total Waktu Eksekusi: {total_time:.4f} detik")
        print(f"Total Karakter Diproses: {corpus_length:,}")
        print(f"Throughput: {throughput:,.2f} karakter/detik")

        # Ini adalah output untuk "tabel/grafik ringkas"
        print("\n--- Hasil Temuan (Tabel per Pola) ---")
        print("="*40)
        print(f"{'Pola':<25} | {'Total Temuan':<15}")
        print("="*40)
        
        for pattern, positions in all_results.items():
            count = len(positions)
            print(f"{pattern:<25} | {count:<15}")
            
            # (Opsional) Tampilkan beberapa indeks temuan
            # if count > 0:
            #     print(f"  -> Posisi: {positions[:5]} {'...' if count > 5 else ''}")

    else:
        print("Gagal memuat corpus. Eksekusi dihentikan.")

except Exception as e:
    print(f"Error saat mengunduh dataset: {e}")
    print("Pastikan token Kaggle API Anda sudah benar.")