1. Baseline: Analisis KMP Satu-per-Satu

        N: Panjang total Teks.
        P: Jumlah total Pola (kata terlarang) di DaftarPola.
        M: Panjang rata-rata dari satu pola.

Algoritma ini memanggil KMP_Search berulang dalam loop setiap pola.

Analisis Waktu (Best/Average/Worst Case)

    Analisis KMP_Search (Satu Pola):

        Preprocessing: Fungsi Compute_LPS berjalan sekali melintasi pola  M. Kompleksitasnya adalah O(M).

        Searching: Fungsi KMP_Search sekali melintasi teks N.Tabel LPS, pointer teks i tidak pernah mundur. Kompleksitasnya adalah O(N).

        Total per Pola: O(N)+O(M)=O(N+M).

    Analisis Main_Baseline_KMP (Semua P Pola):

        Fungsi utama mengulangi proses O(N+M) ini sebanyak P kali (untuk setiap pola).

        Oleh karena itu, kompleksitas totalnya adalah P×(O(N+M)).

Kompleksitas Waktu: O(P⋅(N+M)) atau O(PN+PM)

    Kinerja algoritma KMP (baik preprocessing O(M) maupun search O(N)) tidak bergantung pada isi data (misalnya, jumlah kecocokan). Ia selalu memproses seluruh teks dan seluruh pola.

    Oleh karena itu, Best Case, Average Case, dan Worst Case untuk strategi baseline ini semuanya sama, yaitu O(P(N+M)). Inilah mengapa kinerjanya akan lambat pada dataset besar, seperti yang terlihat di grafik Anda.

Analisis Ruang

    Setiap pemanggilan KMP_Search perlu membuat tabel LPS berukuran M.

    Kompleksitas Ruang (Auxiliary): O(M) (untuk menyimpan tabel LPS dari pola terpanjang) + O(K) (di mana K adalah total jumlah temuan yang disimpan di HasilTotal).
