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
	double* el = new double[size];

	slae.InputMat();

	int x = 1;
	int choose;
	for (int y = 0; y < x; y++)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "\nEnter the right side " << i + 1 << " of the equation" << endl;
			cin >> el[i];
		}

		cout << "Original matrix:" << endl;
		slae.s_print(el);

		sol = slae.gauss(el);
		cout << "Triangular matrix:" << endl;
		slae.s_print(el);

		cout << "Solution vector:" << endl;
		sol.v_print();

		slae.Verification(el);

		cout << "If you want to repeat the same for the other right side, press 1 \n";
		cin >> choose;
		if (choose == 1)
			x = x + 1;
	}
	system("pause");
}