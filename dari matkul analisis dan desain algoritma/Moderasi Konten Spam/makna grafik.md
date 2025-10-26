Makna Grafik (Kasus 3: KMP vs Rabin-Karp)

Grafik membandingkan (seberapa cepat) antara algoritma Baseline (KMP) dan Optimized (RK) pada dua dataset kaggle yang berbeda.

Pada Dataset Kecil (YouTube Spam)

    waktu eksekusi kedua algoritma terlihat hampir mirip.

    Baseline (KMP) (bar biru muda) mungkin akan lebih cepat.

    Alasannya: Teksnya pendek. Optimized (RK) (bar biru tua) memiliki (waktu persiapan) awal untuk menghitung hash dari setiap pola. Pada teks pendek, ini bisa membuatnya lebih lambat daripada KMP yang langsung jalan.

Pada Dataset Sedang (Toxic Comment)

    Di sinilah perbedaan kinerja.

    Bar Baseline (KMP) (biru muda) akan (jauh lebih lambat) daripada bar Optimized (RK) (biru tua).

    Alasannya:

        KMP (Baseline) membaca seluruh teks besar berulang kali (misalnya, 9 kali jika ada 9 pola).

        RK (Optimized) Ia hanya membaca teks besar (satu kali untuk setiap panjang pola, misal 3-4 kali).Disinilah yang membuatnya lebih baik

Kesimpulan

Grafik membuktikan Rabin-Karp Multi-Pattern adalah paling "Optimized".