#include "Smartphone.h"

int main()
{
    cout << "=== Program Demo Smartphone ===" << endl;

    // output dari objek pertama
    // Default Constructor
    Smartphone s1;
    s1.showInfo();

    cout << endl;

    // objek kedua
    // parameter constuctor
    Smartphone s2("HP APIK (Iphone)", 30);
    s2.showInfo();

    cout << endl;

    // objek ketiga
    // copy persis sama sebelum nya
    Smartphone s3 = s2;
    s3.showInfo();

    cout << endl
         << "=== Program Selesai ===" << endl;

    system("pause");
    return 0;
}

//  output secara formal
// // === Program Demo Smartphone ===
// [Default Constructor] Smartphone created: Unknown (100%)
// Smartphone Info -> Brand: Unknown, Battery: 100%

// [Parameterized Constructor] Smartphone created: Samsung (85%)
// Smartphone Info -> Brand: Samsung, Battery: 85%

// [Copy Constructor] Copied Smartphone: Samsung (85%)
// Smartphone Info -> Brand: Samsung, Battery: 85%

// === Program Selesai ===
// [Destructor] Smartphone destroyed: Samsung
// [Destructor] Smartphone destroyed: Samsung
// [Destructor] Smartphone destroyed: Unknown