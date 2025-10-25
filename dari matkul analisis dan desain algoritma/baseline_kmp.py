import os
import pandas as pd
import time
import kagglehub

# --- 1. Fungsi Inti KMP (Sesuai Notulensi) ---

def compute_lps_array(pattern: str) -> list[int]:
    """Menghitung LPS (Longest Proper Prefix which is also Suffix)"""
    m = len(pattern)
    lps = [0] * m
    length = 0
    i = 1

    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps


def kmp_search(text: str, pattern: str) -> list[int]:
    """Mencari pattern di text menggunakan KMP"""
    n = len(text)
    m = len(pattern)
    if m == 0: return []

    lps = compute_lps_array(pattern)
    positions = []
    i = 0  # index untuk text
    j = 0  # index untuk pattern

    while i < n:
        if pattern[j] == text[i]:
            i += 1
            j += 1
        
        if j == m:
            positions.append(i - j)
            j = lps[j - 1]
        elif i < n and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
                
    return positions

# --- 2. Fungsi Pemuat Data ---

def load_text_corpus(dataset_path: str) -> str:
    """Memuat dan menggabungkan semua file CSV komentar menjadi 1 string"""
    print(f"Memuat data dari: {dataset_path}...")
    all_comments = []
    try:
        for filename in os.listdir(dataset_path):
            if filename.endswith(".csv"):
                file_path = os.path.join(dataset_path, filename)
                df = pd.read_csv(file_path)
                # Ambil kolom komentar (biasanya 'CONTENT')
                if 'CONTENT' in df.columns:
                    all_comments.extend(list(df['CONTENT'].dropna().astype(str)))
        
        print(f"Total komentar dimuat: {len(all_comments)}")
        # Gabung semua jadi 1 teks besar dan ubah ke huruf kecil
        corpus = " ".join(all_comments).lower()
        print(f"Total karakter dalam corpus: {len(corpus):,}")
        return corpus
        
    except Exception as e:
        print(f"Error saat memuat data: {e}")
        return ""

# --- 3. Eksekusi Utama Baseline ---

print("Mulai eksekusi Baseline (KMP)...")

# Download dataset (otomatis mencari token API Anda)
print("Mengunduh dataset...")
try:
    path_to_dataset = kagglehub.dataset_download("ahsenwaheed/youtube-comments-spam-dataset")
    print(f"Dataset ada di: {path_to_dataset}")

    # Daftar pola yang dicari (sesuai tugas)
    patterns = [
        "subscribe",
        "check out my channel",
        "free",
        "win",
        "money",
        "giveaway",
        "click here",
        "spam",
        "promotion"
    ]

    # Muat Teks
    text_corpus = load_text_corpus(path_to_dataset)

    if text_corpus:
        print("\n--- Memulai Pencarian Baseline (KMP Satu-per-Satu) ---")
        
        all_results = {}
        start_time = time.time()
        
        # Logika Baseline: Loop KMP satu per satu
        for pattern in patterns:
            print(f"Mencari: '{pattern}'...")
            positions = kmp_search(text_corpus, pattern)
            all_results[pattern] = positions
            
        end_time = time.time()
        total_time = end_time - start_time
        corpus_length = len(text_corpus)
        throughput = (corpus_length / total_time) if total_time > 0 else 0
        
        print("\n--- Ringkasan Kinerja (Baseline) ---")
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