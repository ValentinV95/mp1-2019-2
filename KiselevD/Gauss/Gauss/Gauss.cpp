using namespace std;
#include <iostream>
#include "abs.h"
#include "vector.h"
#include "matrix.h"
#include "slae.h"

int main()
{
    int size;
    cout << "Input matrix size:" << endl;
    cin >> size;
    SLAE<double>m(size);
    Vector<double>sol(size);
    m.fill();
    cout << "Original matrix:" << endl;
    m.s_print();
    sol = m.gauss();
    cout << "Triangular matrix:" << endl;
    m.s_print();
    cout << "Solution vector:" << endl;
    sol.v_print();
}
