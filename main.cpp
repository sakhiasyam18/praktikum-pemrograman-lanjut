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

    cout << "ini luas nya untuk yang kedua " << r1.luas() << endl;

    // cout<<"coba lagi dengan nilai lain"
    // Regtangle r2(7, 3);
    // r2.display();
    cin.get();
    cin.get();
    return 0;
}