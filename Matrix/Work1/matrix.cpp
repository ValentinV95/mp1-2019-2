// Work1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ClassVector.h"
#include "module.h"
#include "Matrix.h"
#include "SoHAE.h"

template <typename T>
void inputRV(T *arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "Print " << i << " right value: " << endl;
		std::cin >> arr[i]; 
	}
}

int main() {
	int size;
	cout << "Input matrix size:" << endl;
	cin >> size;
	double* arr = new double[size];

	inputRV(arr, size);
	SoHAE<double> k(size);
	k.fill();
	k.gauss(arr);


	double* arr2 = new double[size];
	inputRV(arr2, size);
	k.gauss(arr2);
}





/*k[0][0] = 1.0;
k[1][0] = 3.1;
k[2][0] = 0.1;
k[3][0] = 5.0;
k[0][1] = 2.0;
k[1][1] = 6.1;
k[2][1] = 5.4;
k[3][1] = 7.2;
k[0][2] = 1.5;
k[1][2] = 3.6;
k[2][2] = 4.1;
k[3][2] = 2.5;
k[0][3] = 7.3;
k[1][3] = 3.2;
k[2][3] = 0.0;
k[3][3] = 2.8;*/

/*k[0][0] = 2;
k[1][0] = 1;
k[2][0] = 2;
k[3][0] = 3;
k[0][1] = 5;
k[1][1] = 3;
k[2][1] = 10;
k[3][1] = 8;
k[0][2] = 4;
k[1][2] = 2;
k[2][2] = 9;
k[3][2] = 9;
k[0][3] = 1;
k[1][3] = 1;
k[2][3] = 7;
k[3][3] = 2;*/


