## 1. Baseline: Algoritma First-Fit (FF)

Strategi ini solusi *naive*. Kita mengambil setiap iklan (item) sesuai urutan aslinya mencoba memasukkannya ke *loop* (bin) pertama yang kita temukan yang masih memiliki sisa kapasitas.

### Pseudocode (FF)
```plaintext
FUNCTION First_Fit(DaftarItem, KapasitasLoop):
  1.  Inisialisasi `DaftarLoop` (misal, list berisi sisa kapasitas) -> []
  2.  Inisialisasi `Penempatan` (untuk melacak item di tiap loop) -> {}
  
  3.  LOOP UNTUK SETIAP 'item' DI 'DaftarItem':
  4.      DitemukanTempat = FALSE
  5.      
  6.      // Loop invarian berlaku di sini (Loop internal)
  7.      LOOP 'i' DARI 0 SAMPAI (Panjang(DaftarLoop) - 1):
  8.          JIKA sisa kapasitas di DaftarLoop[i] >= ukuran 'item':
  9.              Kurangi sisa kapasitas DaftarLoop[i] dengan ukuran 'item'
 10.             Catat 'item' ke Penempatan[i]
 11.             DitemukanTempat = TRUE
 12.             BREAK // Hentikan pencarian, lanjut ke item berikutnya
 13.     
 14.     // Jika tidak ada loop yang muat, buat loop baru
 15.     JIKA TIDAK DitemukanTempat:
 16.         Buat loop baru dengan sisa kapasitas = KapasitasLoop - ukuran 'item'
 17.         Tambahkan loop baru ini ke `DaftarLoop`
 18.         Catat 'item' di `Penempatan` untuk loop baru ini
 19. 
 20. RETURN `Penempatan`