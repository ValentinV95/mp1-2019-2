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
    Vector<double>rv(size);
    m.fill(rv);
    sol = m.gauss(rv);
    sol.v_print();
}
