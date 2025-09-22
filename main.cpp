// main.cpp
#include "Regtangle.h"
#include <iostream>
using namespace std;

int main()
{
    // nahh ini
    int panjang, lebar;

    cout << "hitung luas yang pertama " << endl;

    cout << "masukan panjang nya ";
    cin >> panjang;
    cout << "masukan lebar nya ";
    cin >> lebar;

    // bikin objek dulu
    Regtangle r1(panjang, lebar);
    cout << "luasnya adalah " << r1.luas() << endl;

    // coba lagi yang kedua

    cout << "masukan yang kedua hehe" << endl;

    // isikan
    cout << "masukan panjang nya ";
    cin >> panjang;
    cout << "masukan lebar nya ";
    cin >> lebar;

    // ingat habis bikin file bikin objek dulu
    Regtangle r2(panjang, lebar);
    cout << "ini luas nya untuk yang kedua " << r2.luas() << endl;

    cin.get();
    cin.get();
    return 0;
}