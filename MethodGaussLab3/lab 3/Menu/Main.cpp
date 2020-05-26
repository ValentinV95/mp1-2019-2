#include "iostream"

#include "Vector.h"
#include "Square_matrix.h"
#include "linear_equation_system.h"

int main()
{
	int size = 0;

	std::cout << "Gausse`s method:" << std::endl;

	std::cout << "Choose vector`s lenght. The square matrix`s line and column will have this size" << std::endl;
	std::cin >> size;
	std::cout << "Vector`s size:" << size << std::endl;

	Vector<double> v1(size);
	v1.fill_v();

	Matrix<double> m1(size);
	m1.fill_m();

	//Matrix<double> m2(size);
	//m2.fill_m();

	//m1 = m2;
	//m1.print_m();

	Linear_equation_system<double> l1(size, m1);
	l1.print_m();
	l1.method_Gauss(v1);
	l1.Check(v1);
}