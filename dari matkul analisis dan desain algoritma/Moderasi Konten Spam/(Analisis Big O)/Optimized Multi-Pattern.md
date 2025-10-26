2. Optimized: Analisis Rabin-Karp Multi-Pattern

kompleknya algoritma ini ia mengelompokkan pola berdasarkan panjangnya dan memindai satu kali per kelompok panjang.

L sebagai jumlah panjang (misalnya, jika polanya "cat", "dog", "help", "spam", maka L=2 untuk panjang 3 dan 4).

Analisis Waktu

    Preprocessing (Menghitung Hash Pola):

        Algoritma mengelompokkan P dan menghitung hash untuk P pola tersebut.

        Menghitung satu hash untuk pola M membutuhkan waktu O(M).

        Total Waktu Preprocessing: O(P⋅M)

    Searching (Rolling Hash):

        Algoritma melakukan loop L kali (untuk setiap kelompok panjang).

        Di dalam setiap loop, ia memindai teks berukuran N.

        Menghitung rolling hash di langkah (pergeseran window) butuh waktu O(1).

Sekarang, analisis berdasarkan collision:

    Average Case (dan Best Case):

        Asumsi menggunakan hash yang baik, hash (tabrakan) jarang terjadi.

        Pengecekan di dalam loop (membandingkan HashTeks dengan PetaHashPola) adalah O(1) (rata-rata untuk hash map).

        Waktu pencarian adalah O(N) (untuk memindai teks) dikali L.

        Total Waktu (Average): O(P⋅M)+O(L⋅N)

        Inilah RK lebih cepat di Dataset Sedang: O(L⋅N) baik daripada O(P⋅N) milik KMP, terutama L (misal: 5 kelompok panjang) lebih kecil dari P (misal: 1000 pola).

    Worst Case :

        Ini terjadi jika fungsi hash buruk, collision di pergeseran window.

        Jika terjadi, setiap langkah i dari N, hash cocok secara salah.

        Ini memicu "Mitigasi Collision", memaksa perbandingan string karakter-demi-karakter, yang memakan waktu O(M).

        Waktu pencarian menjadi O(L⋅N⋅M).

        Total Waktu (Worst): O(P⋅M)+O(L⋅N⋅M)

Analisis Ruang

    Kita menyimpan pola di PolaPerPanjang.Membutuhkan ruang O(P⋅M).

    Kita juga perlu menyimpan PetaHashPola untuk setiap kelompok. Dalam kasus terburuk, ini menyimpan P hash.

    Kompleksitas Ruang: O(P⋅M) (untuk menyimpan semua pola yang dikelompokkan dan hash-nya).
