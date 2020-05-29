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

    Vector <double> matrixVector(SIZE);
    Linear_System<double>matrix(SIZE);

    matrix.Fill();  
    cout << "Initial Matrix: " << endl;  
    matrix.printMatrix();

    matrixVector = matrix.Gauss(); 

    cout << "Triangular Matrix: " << endl;
    matrix.printMatrix();

    cout << "System solution: " << endl;
    matrixVector.printVector();

    matrix.Check();

}


