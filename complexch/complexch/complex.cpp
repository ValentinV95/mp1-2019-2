#include "compexh.h"


void Complex::print()
{
	std::cout << re << " + " << im << "i";
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
