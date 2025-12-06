#ifndef JADWAL_H
#define JADWAL_H
#include "Perangkat.h"
#include <iostream>
using namespace std;

class Jadwal
{
private:
    Perangkat **urutan; // Array of Pointers (Wadah Jadwal)
    int kapasitas;      // Jumlah maksimal alat
    int totalDurasi;    // Total waktu pengerjaan

public:
    // ---------------------------------------------------------
    // 1. CONSTRUCTOR NORMAL
    // Dipanggil saat pertama kali bikin jadwal kosong.
    // ---------------------------------------------------------
    Jadwal(int kap) : kapasitas(kap), totalDurasi(0)
    {
        urutan = new Perangkat *[kapasitas]; // Minta memori ke RAM
        for (int i = 0; i < kapasitas; i++)
            urutan[i] = nullptr;
    }

    // ---------------------------------------------------------
    // 2. DESTRUCTOR (Pembersih Sampah)
    // Dipanggil otomatis saat jadwal tidak terpakai/dihapus.
    // ---------------------------------------------------------
    ~Jadwal()
    {
        delete[] urutan; // Hapus wadah array-nya agar RAM tidak penuh
        // Catatan: Kita TIDAK men-delete isinya (objek Perangkat*),
        // karena objek Perangkat adalah data master yang dipakai bersama.
    }

    // ---------------------------------------------------------
    // 3a. COPY CONSTRUCTOR (Mesin Fotokopi)
    // Dipanggil saat: "Jadwal tetangga = solusiSekarang;"
    // Fungsinya: Membuat duplikat jadwal yang terpisah memorinya.
    // ---------------------------------------------------------
    Jadwal(const Jadwal &sumber)
    {
        kapasitas = sumber.kapasitas;
        totalDurasi = sumber.totalDurasi;

        // Deep Copy: Bikin wadah baru, lalu salin isinya satu per satu
        urutan = new Perangkat *[kapasitas];
        for (int i = 0; i < kapasitas; i++)
        {
            urutan[i] = sumber.urutan[i];
        }
    }

    // ---------------------------------------------------------
    // 3b. COPY ASSIGNMENT OPERATOR (Operasi Sama Dengan '=')
    // Dipanggil saat: "solusiTerbaik = solusiSekarang;"
    // Fungsinya: Menimpa jadwal lama dengan jadwal baru yang lebih bagus.
    // ---------------------------------------------------------
    Jadwal &operator=(const Jadwal &sumber)
    {
        // Cek: Jangan sampai copy diri sendiri (misal a = a)
        if (this == &sumber)
            return *this;

        // 1. Buang jadwal lama dulu (bersih-bersih)
        delete[] urutan;

        // 2. Salin info dasar
        kapasitas = sumber.kapasitas;
        totalDurasi = sumber.totalDurasi;

        // 3. Bikin wadah baru & salin isinya (Deep Copy)
        urutan = new Perangkat *[kapasitas];
        for (int i = 0; i < kapasitas; i++)
        {
            urutan[i] = sumber.urutan[i];
        }

        return *this; // Kembalikan hasil copy
    }

    // --- METHOD OPERASIONAL ---

    // Memasukkan alat ke slot nomor sekian
    void setPerangkat(int index, Perangkat *p)
    {
        if (index >= 0 && index < kapasitas)
        {
            urutan[index] = p;
        }
    }

    // Fungsi Mutasi: Menukar posisi dua alat
    void swap(int i, int j)
    {
        if (i >= 0 && i < kapasitas && j >= 0 && j < kapasitas)
        {
            Perangkat *temp = urutan[i];
            urutan[i] = urutan[j];
            urutan[j] = temp;
            updateTotalWaktu(); // Wajib hitung ulang skor setelah tukar
        }
    }

    // Menghitung skor (Cost Function)
    void updateTotalWaktu()
    {
        totalDurasi = 0;
        for (int i = 0; i < kapasitas; i++)
        {
            if (urutan[i] != nullptr)
            {
                // Disini Polymorphism bekerja!
                // .getDurasi() akan otomatis beda untuk PC vs Server
                totalDurasi += urutan[i]->getDurasi();
            }
        }
    }

    int getCost() const { return totalDurasi; }

    // Visualisasi Gantt Chart Sederhana
    void printGanttChart()
    {
        cout << "[START] ";
        for (int i = 0; i < kapasitas; i++)
        {
            if (urutan[i])
            {
                cout << "-> |" << urutan[i]->getID()
                     << " (" << urutan[i]->getDurasi() << "m)| ";
            }
        }
        cout << "-> [FINISH]" << endl;
        cout << "Total Waktu: " << totalDurasi << " menit.\n"
             << endl;
    }
};
#endif
