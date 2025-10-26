## 2. Optimized: Rabin-Karp Multi-Pattern

Strategi *optimized* mengelompokkan berdasarkan panjang dan menggunakan *rolling hash* untuk memindai teks hanya **satu kali per kelompok panjang**, hal ini paling efisien.

### Pseudocode (Optimized)

```plaintext
FUNCTION Main_Optimized_RK(Text, DaftarPola):
  1.  Inisialisasi `HasilTotal` -> Peta (Map) kosong
  2.  Inisialisasi `PolaPerPanjang` -> Peta (Map) kosong
  3.  Tentukan konstanta `RADIX` dan `PRIME`
  4.
  5.  // 1. Kelompokkan pola berdasarkan panjangnya
  6.  LOOP UNTUK SETIAP 'pola' DI 'DaftarPola':
  7.      m = Panjang(pola)
  8.      Tambahkan 'pola' ke List di `PolaPerPanjang[m]`
  9.  AKHIR LOOP
  10.
  11. Mulai Timer
  12. n = Panjang(Text)
  13.
  14. // 2. Iterasi untuk setiap PANJANG pola yang unik
  15. LOOP UNTUK SETIAP 'm' DAN 'SetPola' DI `PolaPerPanjang`:
  16.     
  17.     // 3. Preprocessing: Hitung hash untuk semua pola di kelompok ini
  18.     Inisialisasi `PetaHashPola` -> Peta (Map) kosong
  19.     h_pow = (RADIX ^ (m - 1)) % PRIME
  20.     LOOP UNTUK SETIAP 'pola' DI 'SetPola':
  21.         Hitung `HashPola` untuk 'pola'
  22.         Tambahkan 'pola' ke List di `PetaHashPola[HashPola]`
  23.     AKHIR LOOP
  24.
  25.     // 4. Pencarian (Rolling Hash)
  26.     Hitung `HashTeks` untuk window Text[0...m-1]
  27.
  28.     LOOP i DARI 0 SAMPAI (n - m):
  29.         // Cek jika hash cocok
  30.         IF `HashTeks` ADA DI `PetaHashPola`:
  31.             // Mitigasi Collision: Cek string aslinya
  32.             WindowTeks = Text[i ... i+m-1]
  33.             LOOP UNTUK SETIAP 'pola' DI `PetaHashPola[HashTeks]`:
  34.                 IF WindowTeks == pola:
  35.                     Tambahkan 'i' ke `HasilTotal[pola]`
  36.             AKHIR LOOP
  37.
  38.         // 5. Hitung rolling hash untuk window berikutnya
  39.         IF i < n - m:
  40.             Hitung ulang `HashTeks` untuk Text[i+1...i+m]
  41.
  42.     AKHIR LOOP (Pencarian)
  43. AKHIR LOOP (Kelompok Panjang)
  44.
  45. Hentikan Timer
  46. RETURN `HasilTotal` dan Waktu Timer
```
---