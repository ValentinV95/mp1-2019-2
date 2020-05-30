#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Linear_Sistem.h"

using namespace std;

int SIZE;
	cout << "Gauss method of solving systems of linear equations." << endl;
	cout << "Enter vector size: " << endl;
	cin >> SIZE;

	Vector <double> matrixVector(SIZE);
	Linear_System<double>matrix(SIZE);

	matrix.FillMatrix();
	
	matrix.FillRight();
	cout << "Initial Matrix: " << endl;
	matrix.printMatrix();

	matrixVector = matrix.Gauss();
	cout << "Triangular Matrix: " << endl;
	matrix.printMatrix();
	cout << "System solution: " << endl;
	matrixVector.printVector();
	matrix.Check();
	int raz;
	cout << "Matriza tazhe, right chast' drygaya!" << endl;
	cout << "Vvedite how many raz right chast' will be drygoy: ";
	cin >> raz;
	cout << endl;
	for (int i = 0; i < raz; i++)
	{
		cout << "New right values: " << endl;
		matrix.FillRight();
		cout << "Initial Matrix: " << endl;
		matrix.printMatrix();

		matrixVector = matrix.Gauss();
		cout << "Triangular Matrix: " << endl;
		matrix.printMatrix();

		cout << "System solution: " << endl;
		matrixVector.printVector();
		matrix.Check();
	}

	

}

