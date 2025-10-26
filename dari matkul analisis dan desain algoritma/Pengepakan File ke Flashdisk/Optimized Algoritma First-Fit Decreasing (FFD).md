## 2. Optimized: Algoritma First-Fit Decreasing (FFD)

Strategi *optimized* optimasi dari *baseline*.Melakukan satu langkah: mengurutkan semua iklan (item) dari yang terpanjang (*decreasing*) ke terpendek. Setelah itu, menjalankan algoritma First-Fit yang sama persis.

### Pseudocode (FFD)
```plaintext
FUNCTION First_Fit_Decreasing(DaftarItem, KapasitasLoop):
  1.  // Langkah 1: Decreasing (Optimasi)
  2.  Urutkan 'DaftarItem' dari terbesar ke terkecil -> 'DaftarUrut'
  3.  
  4.  // Langkah 2: First-Fit (Panggil algoritma baseline)
  5.  HASIL = Panggil First_Fit('DaftarUrut', KapasitasLoop)
  6.  
  7.  RETURN HASIL
```

> "Pada awal setiap iterasi *k* dari loop luar (di dalam fungsi `First_Fit` yang dipanggil), semua *k-1* item sebelumnya (yang **merupakan *k-1* item terbesar**) berhasil ditempatkan. Karena item diurutkan, item-item terbesar selalu 'diprioritaskan' untuk ditempatkan dahulu, yang kemudian nanti akan mengurangi sisa ruang dari hasil."