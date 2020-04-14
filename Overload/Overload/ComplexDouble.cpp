#include "Complex.h"

Complex Complex::operator+ (const double& rhs)
{
	return Complex(re + rhs, im);
}

Complex Complex::operator- (const double& rhs)
{
	return Complex(re - rhs, im);
}

Complex Complex::operator* (const double& rhs)
{
	return Complex(re * rhs, im * rhs);
}

Complex Complex::operator/ (const double& rhs)
{
	return Complex(re / rhs, im / rhs);
}

Complex& Complex::operator+= (const double& rhs)
{
	double _re = re + rhs;
	double _im = im;
	re = _re;
	im = _im;
	return *this;
}

Complex& Complex::operator-= (const double& rhs)
{
	double _re = re - rhs;
	double _im = im;
	re = _re;
	im = _im;
	return *this;
}

Complex& Complex::operator*= (const double& rhs)
{
	double _re = re * rhs;
	double _im = im * rhs;
	re = _re;
	im = _im;
	return *this;

}

Complex& Complex::operator/= (const double& rhs)
{
	double _re = re / rhs;
	double _im = im / rhs;
	re = _re;
	im = _im;
	return *this;
}
