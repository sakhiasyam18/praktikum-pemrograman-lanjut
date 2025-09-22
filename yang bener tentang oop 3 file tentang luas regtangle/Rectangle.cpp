#include "Rectangle.h"
#include <iostream>

// Constructor
Rectangle::Rectangle(int panjang, int lebar)
{
    this->panjang = panjang; // gunakan this pointer
    this->lebar = lebar;
    std::cout << "Object Rectangle dibuat." << std::endl;
}

// Destructor
Rectangle::~Rectangle()
{
    std::cout << "Object Rectangle dihancurkan." << std::endl;
}

// Method luas
int Rectangle::getLuas() const
{
    return this->panjang * this->lebar;
}

// Method display
void Rectangle::display() const
{
    std::cout << "Panjang: " << this->panjang
              << ", Lebar: " << this->lebar
              << ", Luas: " << this->getLuas()
              << std::endl;
}
