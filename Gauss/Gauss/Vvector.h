#pragma once

template < typename T >

class  Vvector{
public:
    
    Vvector() 
    {
        vec = new T[10];
        size = 10;
    }

    Vvector(int size, T value = T()) 
    {
        vec = new T[size];
        for (int i = 0; i < size; i++) {
            vec[i] = value;
        }
        this->size = size;
    }
   
   void print();
   void sum(Vvector vec, int size);



private:
    T* vec;
   int size;
};


