#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Linear_Sistem.h"

using namespace std;

int main()
{
	int SIZE;
	cout << "Gauss method of solving systems of linear equations." << endl;
	cout << "Enter vector size: " << endl;
	cin >> SIZE;
	

	Linear_System<double>matrix(SIZE);
	Vector <double> matrixVector(SIZE);
	
	double* ptr = new double[SIZE];
	
	matrix.FillMatrix();
	
	int raz;
	cout << "Enter how many raz you will enter the right part: ";
	cin >> raz;
	cout << endl;

	for (int n = 0; n < raz; n++)
	{

	

		for (int i = 0; i < SIZE; i++)
		{
			cout << "Enter " << i + 1 << " right values" << endl;
			cin >> ptr[i];
		}


		cout << "Initial Matrix: " << endl;
		matrix.printMatrix(ptr);

		matrixVector = matrix.Gauss(ptr);
		cout << "Triangular Matrix: " << endl;
		matrix.printMatrix(ptr);

		cout << "System solution: " << endl;
		matrixVector.printVector();

		matrix.Check(ptr);
		
	}
	
		
}
