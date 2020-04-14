#include "Complex.h"


Complex operator+ (const double& a, const Complex& rhs)
{
	return Complex(rhs.re + a, rhs.im + a);
}

Complex operator- (const double& a, const Complex& rhs)
{
	return Complex(a - rhs.re, a- rhs.im);
}

Complex operator* (const double& a, const Complex& rhs)
{
	return Complex(a * rhs.re, a * rhs.im);
}

Complex operator/ (const double& a, const Complex& rhs)
{
	return Complex((a * a) / (a * a + rhs.re * rhs.re), (a * rhs.im * (-1)) / (a * a + rhs.im * rhs.im));
}
