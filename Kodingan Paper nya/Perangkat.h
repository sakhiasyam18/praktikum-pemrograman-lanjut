#ifndef PERANGKAT_H
#define PERANGKAT_H
#include <string>
#include <iostream>
using namespace std;

// ==========================================
// KELAS INDUK (ABSTRACT BASE CLASS)
// ==========================================
class Perangkat
{
protected:
    string id;    // ID Unik (Misal: PC-01, SVR-A)
    string jenis; // Jenis alat

public:
    // Constructor
    Perangkat(string id, string j) : id(id), jenis(j) {}

    // Virtual Destructor (PENTING!)
    // Agar saat objek dihapus, memori anak-anaknya juga bersih sempurna.
    virtual ~Perangkat() {}

    // PURE VIRTUAL FUNCTION (Polymorphism)
    // Fungsi ini "wajib" diisi ulang (override) oleh kelas anaknya (PC/Server).
    // "= 0" artinya kelas Perangkat ini abstrak, tidak bisa dibuat objek langsung.
    virtual int getDurasi() const = 0;

    // Getter standar
    string getID() const { return id; }
    string getJenis() const { return jenis; }
};

// ==========================================
// KELAS ANAK 1: PC
// ==========================================
class PC : public Perangkat
{
public:
    PC(string id) : Perangkat(id, "PC Workstation") {}

    // Override: Menentukan durasi khusus PC
    int getDurasi() const override
    {
        return 30; // 30 menit
    }
};

// ==========================================
// KELAS ANAK 2: SERVER
// ==========================================
class Server : public Perangkat
{
public:
    Server(string id) : Perangkat(id, "Server Lab") {}

    // Override: Menentukan durasi khusus Server
    int getDurasi() const override
    {
        return 120; // 2 jam (120 menit)
    }
};

#endif
