// FILE: Regtangle.h
#ifndef REGTANGLE_H
#define REGTANGLE_H

class Regtangle
{
private:
    int panjang;
    int lebar;

public:
    // ini constructor
    Regtangle( int panjang,  int lebar);
    // ini destructor nya
    ~Regtangle();

    // ini member function method
    // atau istilahnya untuk menghitung luas
    int luas() const;

    //kalau ini untuk menampilkan infonyua 
    void display() const;
};



#endif // REGTANGLA_H