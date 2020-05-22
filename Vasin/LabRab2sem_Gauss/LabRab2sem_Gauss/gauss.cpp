#include <iostream>
#include "My_vector.h"
#include "My_matrix.h"
#include "SLAE.h"
using namespace std;

int main()
{
	int size;
	cout << "Input matrix size:" << endl;
	cin >> size;
	SLAE<double>sl(size);
	My_vector<double>sol(size);
	sl.InputMat();
	cout << "Original matrix:" << endl;
	sl.s_print();
	sol = sl.gauss();
	cout << "Triangular matrix:" << endl;
	sl.s_print();
	cout << "Solution vector:" << endl;
	sol.v_print();
}

