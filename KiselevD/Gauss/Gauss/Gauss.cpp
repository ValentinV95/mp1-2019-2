using namespace std;
#include <iostream>
#include "vector.h"
#include "matrix.h"
#include "slae.h"

int main()
{
    int size;
    cout << "Input matrix size:" << endl;
    cin >> size;
    SLAE<double>m(size);
    m.fill();
    m.s_print();
    m.swap(0, 2);
    m.s_print();
}
