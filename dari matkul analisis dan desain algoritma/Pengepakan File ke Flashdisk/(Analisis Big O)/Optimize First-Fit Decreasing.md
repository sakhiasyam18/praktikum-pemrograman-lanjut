2. Optimized: Algoritma First-Fit Decreasing (FFD)

Berdasarkan pseudocode dalam file Optimized Algoritma First-Fit Decreasing (FFD).md.

Analisis Kompleksitas Waktu (Big-O)

Algoritma FFD terdiri dari dua langkah utama:

    Langkah 1: Sorting (Decreasing)

        Langkah pertama adalah "Urutkan 'DaftarItem' dari terbesar ke terkecil".

        Kompleksitas waktu standar untuk algoritma pengurutan yang efisien (seperti Merge Sort atau Timsort/Python sort) pada n item adalah O(nlogn).

    Langkah 2: First-Fit (Panggil Baseline)

        Langkah kedua adalah "Panggil First_Fit('DaftarUrut', KapasitasLoop)".

        Seperti yang telah kita analisis di atas, kompleksitas waktu untuk First_Fit adalah O(n2).

    Total: Kompleksitas waktu total adalah penjumlahan dari kedua langkah tersebut: O(nlogn)+O(n2).

    Faktor Dominan: Dalam notasi Big-O, kita mengambil faktor yang dominan. Karena n2 tumbuh lebih cepat daripada nlogn, O(n2) adalah faktor dominan.

Kompleksitas waktu totalnya adalah O(n2).

Analisis Kompleksitas Ruang (Big-O)

    Sorting: Jika pengurutan membuat daftar baru (DaftarUrut), ini memerlukan ruang tambahan O(n). Jika dilakukan in-place, bisa O(1) atau O(logn) (tergantung algoritma sorting-nya). Asumsikan O(n) untuk DaftarUrut baru.

    First-Fit: Panggilan fungsi First_Fit itu sendiri, seperti yang dianalisis sebelumnya, memerlukan ruang O(n) untuk Penempatan dan DaftarLoop.

Kompleksitas ruang totalnya tetap O(n).