#include <math.h>

#include "Complex.h"

Complex& Complex::operator= (const Complex& rhs)
{
	re = rhs.re;
	im = rhs.im;
	return *this;
}

Complex Complex::operator+ (const Complex& rhs)
{
	return Complex(re + rhs.re, im + rhs.im);
}

Complex Complex::operator- (const Complex& rhs)
{
	return Complex(re - rhs.re, im - rhs.im);
}

Complex Complex::operator* (const Complex& rhs)
{
	return Complex(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re);
}

Complex Complex::operator/ (const Complex& rhs)
{
return Complex((re * rhs.re + im * rhs.im)/(rhs.im * rhs.im + rhs.re * rhs.re), (-re * rhs.im + im * rhs.re)/(rhs.im * rhs.im + rhs.re * rhs.re));
}

									//Complex operator% (const Complex& rhs);
Complex& Complex::operator+= (const Complex& rhs)
{
double _re = re + rhs.re;
double _im = im + rhs.im;
re = _re;
im = _im;
return *this;
}
Complex& Complex::operator-= (const Complex& rhs)
{
double _re = re - rhs.re;
double _im = im - rhs.im;
re = _re;
im = _im;
return *this;
}
Complex& Complex::operator*= (const Complex& rhs)
{
double _re = re * rhs.re - im * rhs.im;
double _im = re * rhs.im + im * rhs.re;
re = _re;
im = _im;
return *this;
}
Complex& Complex::operator/= (const Complex& rhs)
{
double _re = (re * rhs.re + im * rhs.im)/(rhs.im * rhs.im + rhs.re * rhs.re);
double _im = (-re * rhs.im + im * rhs.re)/(rhs.im * rhs.im + rhs.re * rhs.re);
re = _re;
im = _im;
return *this;
}

bool Complex::operator== (const Complex& rhs)
{
if ((re == rhs.re) && (im == rhs.im))
{
return true;
}
return false;
}

bool Complex::operator!= (const Complex& rhs)
{
return !(*this == rhs);
}

bool Complex::operator< (const Complex& rhs)
{
	double mod1 = sqrt(re * re + im * im);
	double mod2 = sqrt(rhs.re * rhs.re + rhs.im * rhs.im);
	return (mod1 < mod2);
}

bool Complex::operator<= (const Complex& rhs)
{
	double mod1 = sqrt(re * re + im * im);
	double mod2 = sqrt(rhs.re * rhs.re + rhs.im * rhs.im);
	return (mod1 <= mod2);
}

bool Complex::operator> (const Complex& rhs)
{
	double mod1 = sqrt(re * re + im * im);
	double mod2 = sqrt(rhs.re * rhs.re + rhs.im * rhs.im);
	return (mod1 > mod2);
}

bool Complex::operator>= (const Complex& rhs)
{
	double mod1 = sqrt(re * re + im * im);
	double mod2 = sqrt(rhs.re * rhs.re + rhs.im * rhs.im);
	return (mod1 >= mod2);
}
