#pragma once
#include <iostream>

#include "complex.h"


class vector
{
public:

    vector()
    {
        size = 10;
        a = nullptr;
    }

    vector(int size, Complex value)
    {
        a = new Complex[size];
        this->size = size;
        for (int i = 0; i < size; i++)
            a[i] = value;

    }

    vector(int size) : vector(size,Complex(0,0))
    {

    }

    vector(const vector& _copy)
    {
        size = _copy.size;
        a = new Complex[size];
        for (int i = 0; i < size; i++)
            a[i] = _copy.a[i];

    }

  

    void itpoz(int poz, Complex zn)
    {
        a[poz] = zn;
    }
    

    void sum(vector v2, int size);
    void scalumn(vector v2);
    void prov(vector v2);
    void print();
    

    ~vector()
    {
        delete a;
        size = 0;

    }

    



    Complex& operator[](int index) 
    {
        if (index >= size) {
            std::cout << "Incorrect index";
            exit(0);
        }
        return a[index];
    }


    friend std::ostream& operator << (std::ostream& os, const vector& dt);



private:
   int size;
   Complex* a;




};

