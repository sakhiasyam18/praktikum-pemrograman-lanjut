// Smartphone.cpp
// Implementasi fungsi-fungsi class Smartphone

#include "Smartphone.h"

Smartphone::Smartphone()
{
    merek = "Default";
    baterai = 100;
    // "[Default Constructor] Smartphone created: "
    cout << merek << " (" << baterai << "%)" << endl;
}

// yang parameter
Smartphone::Smartphone(string nilaipertamamerek, int nilaipertamabaterai)
{
    merek = nilaipertamamerek;
    baterai = nilaipertamabaterai;
    // "[Parameterized Constructor] Smartphone created: "
    cout << merek << " (" << baterai << "%)" << endl;
}

// yang copy construktonya
Smartphone::Smartphone(const Smartphone &other)
{
    merek = other.merek;
    baterai = other.baterai;
    // "[Copy Constructor] Copied Smartphone: "
    cout << merek << " (" << baterai << "%)" << endl;
}

// yang destruktor
Smartphone::~Smartphone()
{
    // "[Destructor] Smartphone destroyed: "
    cout << merek << endl;
}

// ini untuk menampilkan informasi
void Smartphone::showInfo() const
{
    cout << merek
         << baterai << "%" << endl;
}