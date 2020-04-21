#include <iostream>

#include "Complex.h"
#include "ComplexVector.h"

int main()
{
	Complex c1{10.0, 10.0};
	Complex c2{ 11, 11 };
	Complex c3 = {};
	Complex c4 = {};

	Vector v1 = {Complex(10.0, 10.0)};
	Vector v2 = { Complex(11.0, 11.0) };
	Vector v3;

	v3 = v1 + v2;
	v3.printV();
	




}
