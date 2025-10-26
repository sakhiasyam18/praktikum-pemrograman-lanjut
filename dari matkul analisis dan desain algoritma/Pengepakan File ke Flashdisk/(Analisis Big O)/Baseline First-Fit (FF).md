1. Baseline: Algoritma First-Fit (FF)

Berdasarkan pseudocode dalam file Baseline Algoritma First-Fit (FF).md.

Analisis Kompleksitas Waktu (Big-O)

Mari kita definisikan:

    n = jumlah item (durasi iklan/lagu) di DaftarItem.

    m = jumlah loop (bins) yang telah dibuat.

    Loop Luar: Algoritma memiliki satu loop utama yang beriterasi "UNTUK SETIAP 'item' DI 'DaftarItem'". Loop ini akan berjalan sebanyak n kali.

    Loop Internal: Di dalam loop luar, ada loop internal yang mencari "LOOP 'i' DARI 0 SAMPAI (Panjang(DaftarLoop) - 1)". Loop ini mencari bin yang muat.

    Kasus Terburuk (Worst-Case): Dalam kasus terburuk, setiap item baru mungkin tidak muat di m−1 bin pertama dan baru muat di bin ke-m. Atau, lebih buruk lagi, setiap item membutuhkan bin baru. Ini berarti jumlah bin, m, bisa bertambah hingga n (setiap item di bin terpisah).

    Total: Untuk item pertama, kita cek 0 bin. Untuk item kedua, kita cek 1 bin. Untuk item ke-n, kita mungkin harus mengecek hingga n−1 bin. Ini mengarah pada kompleksitas O(1+2+...+n), yang merupakan O(n2).

Secara sederhana, algoritma ini memiliki n (loop luar) dikalikan m (loop internal). Karena m≤n, kompleksitas waktu terburuknya adalah O(n2).

Analisis Kompleksitas Ruang (Big-O)

    Penempatan: Kita perlu menyimpan lokasi setiap item. Ini akan menyimpan n item. Oleh karena itu, memerlukan ruang O(n).

    DaftarLoop: Kita menyimpan daftar sisa kapasitas untuk setiap loop yang dibuat. Dalam kasus terburuk, kita memiliki m loop, di mana m≤n. Ini memerlukan ruang O(m) atau O(n).

Kompleksitas ruang totalnya adalah O(n) untuk menyimpan data penempatan dan status loop.