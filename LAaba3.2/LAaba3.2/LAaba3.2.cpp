#include "pch.h"
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Gauss.h"
using namespace std;

int main()
{
	int size;
	cout << "Input matrix size:" << endl;
	cin >> size;
	Gauss<double>slae(size);
	Vector<double>sol(size);
	slae.InputMat();
	cout << "Original matrix:" << endl;
	slae.s_print();

	sol = slae.gauss();
	cout << "Triangular matrix:" << endl;
	slae.s_print();

	cout << "Solution vector:" << endl;
	sol.v_print();

	slae.Verification();

	system("pause");
	//int a;
	//cin >> a;
}