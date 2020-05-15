#include <iostream>

#include "Func_massive_for_creating_vector.h"
#include "Vector.h"
#include "Square_Matrix.h"
#include "Linear_equation_system.h"


int main()
{
	int size;
	
	std::cout << "Gausse`s method:" << std::endl;
	std::cout << "Choose vector`s lenght. The square matrix`s line and column will have this size" << std::endl;
	std::cin >> size;
	std::cout << "Vector`s size:" << size << std::endl;

	double* a0 = new double[size];
	double* a1 = new double[size];
	create_random_massive(size, a1);
	create_null_massive(size, a0);

	Vector<double> v0(size, a0);
	Vector<double> v1(size, a1);
	
	Matrix<double> m1(size);

	Linear_equation_system<double> l1(size);
	l1.print_linear_equation_system();
	l1.method_Gauss();
	std::cout << std::endl;
	l1.print_linear_equation_system();
	
	delete[]a1;
	delete[]a0;
}