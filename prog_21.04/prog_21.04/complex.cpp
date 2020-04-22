#include "complex.h"
#include "vector.h"

void Complex::print()
{
	if (im != 0)
		std::cout << re << " + " << im << "i";
	else
		std::cout << re;
}



Complex operator+(const double& a, const Complex& ch)
{
	return Complex(a + ch.re, ch.im);
}

Complex operator*(const double& a, const Complex& ch)
{
	return Complex(ch.re * a, ch.im * a);
}

Complex operator*(const Complex& ch, const double& a)
{
	return Complex(ch.im * a, ch.re * a);
}

std::ostream& operator << (std::ostream& os, const Complex& dt)
{
	if (dt.im != 0)
		os<<dt.re << " + " << dt.im << "i";
	else
		os << dt.re;

	return os;
}
