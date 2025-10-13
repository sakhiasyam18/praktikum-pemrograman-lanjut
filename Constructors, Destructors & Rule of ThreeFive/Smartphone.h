#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <iostream>
#include <string>
using namespace std;

class Smartphone
{
private:
    string merek;
    int baterai;

public:
    /* data ini default*/
    // dipanggilnya saat objek dibuat tanpa argumen
    Smartphone();

    // sekarang tak kasih nilai awal tertentu
    // ini istilahnya parameterized constructor
    Smartphone(string, int);

    // kalau ini copy construktor
    // aku akan bikin objek baru dari objek yang sudah aku buat dengan sama persis
    // aku berikan smarphone s2
    Smartphone(const Smartphone &);

    // ✅ Destructor
    // Dipanggil otomatis saat objek dihapus / keluar dari scope
    ~Smartphone();

    // Fungsi untuk menampilkan informasi smartphone
    void showInfo() const;
};

#endif