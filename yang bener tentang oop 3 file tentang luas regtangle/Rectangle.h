#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    int panjang;
    int lebar;

public:
    // Constructor
    Rectangle(int panjang, int lebar);

    // Destructor
    ~Rectangle();

    // Method untuk menghitung luas
    int getLuas() const;

    // Method untuk menampilkan info
    void display() const;
};

#endif // RECTANGLE_H
