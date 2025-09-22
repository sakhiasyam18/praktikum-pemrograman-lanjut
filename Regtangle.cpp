#include "Regtangle.h"
#include <iostream>

// constuktornya
Regtangle::Regtangle(int panjang, int lebar)
{
    this->panjang = panjang;
    this->lebar = lebar;
    std::cout << "objek regtangle yang dibuat " << std::endl;
}

// destuctor
Regtangle::~Regtangle()
{
    std::cout << "objek regtangle yang dihancurkan " << std ::endl;
}

// ini luas
int Regtangle::luas() const
{
    return this->panjang * this->lebar;
}

// ini bagian display nya
void Regtangle::display() const
{
    std::cout << "panjang: " << this->panjang
    << ",lebar " << this->lebar
    << ",luas " << this->luas()
    << std::endl;
}