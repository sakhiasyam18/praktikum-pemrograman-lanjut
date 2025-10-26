## 1. Baseline: KMP Satu-per-Satu

Strategi *baseline* menjalankan algoritma KMP berulang, satu kali untuk  pola (kata terlarang) yang ada di dalam daftar.

### Pseudocode (Baseline)

Ini alur nya.
```plaintext
FUNCTION Main_Baseline_KMP(Text, DaftarPola):
  1.  Inisialisasi `HasilTotal` -> Peta (Map) kosong
  2.  Mulai Timer
  3.
  4.  LOOP UNTUK SETIAP 'pola' DI 'DaftarPola':
  5.      // Panggil fungsi KMP_Search untuk setiap pola
  6.      `HasilPola` = Panggil KMP_Search(Text, pola)
  7.      Simpan `HasilPola` ke `HasilTotal[pola]`
  8.  AKHIR LOOP
  9.
  10. Hentikan Timer
  11. RETURN `HasilTotal` dan Waktu Timer
```

Ini adalah fungsi `KMP_Search` yang dipanggil di dalam loop.
```plaintext
FUNCTION KMP_Search(Text, Pattern):
  1.  Inisialisasi `PosisiTemuan` -> List (Array) kosong
  2.  n = Panjang(Text)
  3.  m = Panjang(Pattern)
  4.  
  5.  // 1. Preprocessing: Buat tabel LPS
  6.  `LPS` = Panggil Compute_LPS(Pattern)
  7.  
  8.  // 2. Pencarian
  9.  i = 0  // pointer untuk Text
  10. j = 0  // pointer untuk Pattern
  11.
  12. LOOP (selama i < n):
  13.     IF Pattern[j] == Text[i]:
  14.         i = i + 1
  15.         j = j + 1
  16.
  17.     // Pola ditemukan
  18.     IF j == m:
  19.         Tambahkan (i - j) ke `PosisiTemuan`
  20.         j = LPS[j - 1] // Lompat ke posisi prefix-suffix
  21.
  22.     // Mismatch (tidak cocok)
  23.     ELSE IF (i < n DAN Pattern[j] != Text[i]):
  24.         IF j != 0:
  25.             j = LPS[j - 1] // Lompat (tanpa mundurkan i)
  26.         ELSE:
  27.             i = i + 1 // Geser pointer Text
  28.
  29. AKHIR LOOP
  30. RETURN `PosisiTemuan`
```

Ini fungsi `Compute_LPS` (dari KMP).
```plaintext
FUNCTION Compute_LPS(Pattern):
  1.  m = Panjang(Pattern)
  2.  Inisialisasi `LPS` -> Array[m] berisi angka 0
  3.  length = 0 // panjang prefix-suffix sebelumnya
  4.  i = 1
  5.
  6.  LOOP (selama i < m):
  7.      IF Pattern[i] == Pattern[length]:
  8.          length = length + 1
  9.          LPS[i] = length
  10.         i = i + 1
  11.     ELSE:
  12.         IF length != 0:
  13.             length = LPS[length - 1]
  14.         ELSE:
  15.             LPS[i] = 0
  16.             i = i + 1
  17.
  18. AKHIR LOOP
  19. RETURN `LPS`
```

---