#include <iostream>
#include <vector>
#include <cstdlib>     // Library untuk fungsi random (rand)
#include <ctime>       // Library untuk fungsi waktu (agar hasil random beda tiap run)
#include "Perangkat.h" // Import model data aset
#include "Jadwal.h"    // Import logika memori & jadwal

using namespace std;

// ============================================================================
// FUNGSI 1: GENERATE DATA DUMMY
// Tujuannya: Membuat 10-20 alat secara otomatis biar kita gak capek input manual.
// ============================================================================
void generateData(vector<Perangkat *> &database, int jumlah)
{
    for (int i = 0; i < jumlah; i++)
    {
        // Membuat ID biar rapi, misal "01", "02", dst.
        string id = (i < 9 ? "0" : "") + to_string(i + 1);

        // Logika Random:
        // Jika angka random genap -> Bikin PC (Durasi 30 menit)
        // Jika angka random ganjil -> Bikin Server (Durasi 120 menit)
        if (rand() % 2 == 0)
        {
            database.push_back(new PC("PC-" + id));
        }
        else
        {
            database.push_back(new Server("SVR-" + id));
        }
    }
}

// ============================================================================
// FUNGSI 2: ALGORITMA TABU SEARCH (INTI PROGRAM)
// Tujuannya: Mencari urutan servis terbaik dengan cara tukar-tukar posisi (Swap).
// ============================================================================
Jadwal jalankanTabuSearch(Jadwal jadwalAwal)
{
    // 1. Inisialisasi Solusi
    // Kita simpan jadwal awal sebagai 'Rekor Terbaik' sementara.
    // Disini Copy Constructor bekerja membuat duplikat memori yang aman.
    Jadwal solusiTerbaik = jadwalAwal;
    Jadwal solusiSekarang = jadwalAwal;

    // 2. Setting Batasan Algoritma (Agar program tidak hang/lama)

    // HARD LIMIT (Sabuk Pengaman):
    // Batasi loop maksimal 100 kali. Ini menjamin program selesai < 1 detik.
    int maxIterasi = 100;

    // STAGNATION COUNTER (Rem Otomatis):
    // Kalau sudah 20 kali muter tapi skornya gak nambah bagus, STOP aja.
    // Artinya kita sudah nemu solusi mentok (sudah optimal).
    int maxStagnansi = 20;
    int counterStagnan = 0; // Menghitung berapa kali kita gagal improve

    cout << "--- MEMULAI PROSES OPTIMASI ---" << endl;
    cout << "Skor Awal (Total Waktu): " << solusiTerbaik.getCost() << " menit." << endl;

    // 3. MULAI LOOPING (Proses Coba-Coba)
    for (int i = 0; i < maxIterasi; i++)
    {

        // A. Generate Tetangga (Simulasi)
        // Kita copy jadwal sekarang ke variabel baru bernama 'tetangga'.
        // Disini kita akan utak-atik 'tetangga' tanpa merusak jadwal asli.
        Jadwal tetangga = solusiSekarang;

        // B. Mutasi (Tukar Posisi)
        // Pilih 2 nomor urut secara acak (0 sampai 9)
        int idx1 = rand() % 10; // Asumsi jumlah data 10
        int idx2 = rand() % 10;

        // Pastikan komputer tidak menukar barang yang sama (misal tukar 1 dengan 1)
        // Kalau sama, cari angka lain buat idx2.
        while (idx1 == idx2)
        {
            idx2 = rand() % 10;
        }

        // Lakukan Pertukaran (Swap)
        // Misal: Tukar urutan PC-01 dengan Server-05
        tetangga.swap(idx1, idx2);

        // C. Evaluasi (Cek Rapor)
        // Apakah hasil tukar-tukar tadi bikin waktu makin cepat?

        // KONDISI 1: PECAH REKOR!
        // Jika waktu 'tetangga' lebih kecil (cepat) dari rekor terbaik sejauh ini.
        if (tetangga.getCost() < solusiTerbaik.getCost())
        {

            solusiTerbaik = tetangga;  // Simpan rekor baru (Operator= jalan disini)
            solusiSekarang = tetangga; // Kita pindah ke posisi ini
            counterStagnan = 0;        // Reset counter dosa karena berhasil improve

            cout << "Iterasi " << i << ": REKOR BARU! (" << solusiTerbaik.getCost() << " menit)" << endl;
        }
        // KONDISI 2: TIDAK PECAH REKOR, TAPI LEBIH BAIK DARI SEKARANG
        // Misal rekor 500, sekarang 600, tetangga 550.
        // Kita ambil 550 biar ada pergerakan maju.
        else if (tetangga.getCost() < solusiSekarang.getCost())
        {
            solusiSekarang = tetangga; // Pindah aja biar gak diem di tempat
            counterStagnan++;          // Tetap dihitung stagnan karena rekor global belum pecah
        }
        // KONDISI 3: LEBIH JELEK
        // Hasil swap malah bikin makin lama.
        else
        {
            counterStagnan++; // Nambah dosa
            // Kita diam saja, jangan pindah ke tetangga yang jelek ini.
            // (Loop akan mengulang generate tetangga baru di iterasi berikutnya)
        }

        // D. Cek Kondisi Berhenti (Early Exit)
        // Kalau dosa (kegagalan) sudah menumpuk sebanyak 'maxStagnansi'
        if (counterStagnan >= maxStagnansi)
        {
            cout << "\n>> STOP OTOMATIS!" << endl;
            cout << ">> Sudah " << maxStagnansi << " kali muter hasil mentok (tidak ada perbaikan)." << endl;
            cout << ">> Berhenti di iterasi ke-" << i << " untuk hemat waktu." << endl;
            break; // Keluar paksa dari loop for
        }
    }

    return solusiTerbaik; // Kembalikan hasil terbaik yang ditemukan
}

// ============================================================================
// FUNGSI UTAMA (MAIN)
// Tempat program dimulai.
// ============================================================================
int main()
{
    // Reset fungsi random berdasarkan jam komputer.
    // Supaya tiap kali program di-run, hasil acaknya beda-beda.
    srand(time(0));

    cout << "=== SISTEM PENJADWALAN MAINTENANCE LAB ===" << endl;

    // 1. Siapkan Database Aset
    // Kita pakai vector untuk menyimpan master data pointers.
    vector<Perangkat *> databaseAset;
    generateData(databaseAset, 10); // Minta komputer bikin 10 alat acak

    // 2. Masukkan ke Jadwal Awal (Default)
    // Urutannya masih sesuai generate (PC-01, PC-02, dst...)
    Jadwal jadwalKerja(10);
    for (int i = 0; i < 10; i++)
    {
        jadwalKerja.setPerangkat(i, databaseAset[i]);
    }
    jadwalKerja.updateTotalWaktu(); // Hitung skor awal

    // Tampilkan Jadwal Sebelum Diapa-apain
    cout << "\n[1] JADWAL AWAL (SEBELUM OPTIMASI):" << endl;
    jadwalKerja.printGanttChart();

    // 3. Jalankan Algoritma Tabu Search
    // Ini proses utamanya. Komputer akan mikir keras disini.
    Jadwal hasilOptimasi = jalankanTabuSearch(jadwalKerja);

    // Tampilkan Hasil Akhir
    cout << "\n----------------------------------------" << endl;
    cout << "[2] HASIL AKHIR OPTIMASI TERBAIK:" << endl;
    // Gantt Chart akan menampilkan urutan baru yang lebih efisien
    hasilOptimasi.printGanttChart();
    cout << "----------------------------------------" << endl;

    // 4. Bersih-bersih Memori Master (Penting!)
    // Karena di fungsi generateData kita pakai 'new', kita wajib 'delete'.
    // Ini Good Practice di C++ agar RAM tidak bocor.
    for (auto p : databaseAset)
        delete p;

    // TAMBAHAN: Tahan layar biar gak langsung close
    cout << "\nTekan Enter untuk keluar...";
    cin.get();

    return 0;
}
