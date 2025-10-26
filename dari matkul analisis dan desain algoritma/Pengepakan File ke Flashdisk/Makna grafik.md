Makna grafik

Grafik dan tabel tersebut bukti perbandingan kinerja antara dua  pengepakan (Bin Packing) yang dimplementasikan, yaitu Baseline (FF) dan Optimized (FFD)

Analisis Hasil menggunakan data durasi lagu dari Spotify.

Grafik menunjukkan temuan:

    Pada Dataset Kecil (n=50): Ketiga bar (Baseline, Optimized, dan Lower Bound) semuanya berada di angka 4 bins. Ini berarti, bahkan dengan strategi "asal-asalan" (FF), hasilnya sudah optimal (mencapai batas minimum teoretis).

    Pada Dataset Sedang (n=500): Fenomena yang sama persis terjadi. Baseline (FF) menggunakan 29 bins, dan Optimized (FFD) juga menggunakan 29 bins.

Kesimpulan eksperimen adalah:

    Baseline (FF) Sudah Optimal: Untuk dataset (durasi lagu Spotify), algoritma First-Fit (FF) ternyata sudah bekerja dengan efisien. Ia berhasil menemukan pengepakan yang paling optimal (29 CD untuk 500 lagu) tanpa perlu langkah tambahan.

    Optimized (FFD) Tidak Memberi Peningkatan: Strategi Optimized (FFD) tidak memberikan tambahan karena algoritma (FF) suda optimal. Hasilnya sama baiknya, sebab (FF) telah mencapai batas minimum teoretis, sehingga tidak ada lagi ruang untuk perbaikan.

Kita telah membuktikan bahwa FFD secara dianggap lebih baik, ada kasus data (seperti data lagu ini) di mana FF sudah cukup untuk mencapai hasil yang sempurna.