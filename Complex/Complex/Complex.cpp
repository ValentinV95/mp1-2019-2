#include <iostream>
using namespace std;

class Complex {

public:
	friend void printer(Complex a);
	Complex() {
		re = 0;
		im = 0;
	}
	Complex(double a, double b) {
		re = a;
		im = b;
	}
	Complex operator-()
	{
		return Complex(-re, -im);
	}
	Complex& operator--()//--a
	{
		re--;
		return*this;
	}
	Complex operator--(int)//a--
	{
		Complex res(*this);
		--(*this);
		return res;
	}
	Complex& operator++()//++a
	{
		re++;
		return*this;
	}
	Complex operator++(int)//a++
	{
		Complex res(*this);
		++(*this);
		return res;
	}
	//!
	Complex operator=(const Complex& other)
	{
		re = other.re;
		im = other.im;
		return *this;
	}
	Complex operator+(const Complex& other)
	{
		return Complex(re + other.re, im + other.im);
	}
	Complex operator-(const Complex& other)
	{
		return Complex(re - other.re, im - other.im);
	}
	Complex operator*(const Complex& other)
	{
		return Complex(re * other.re - im * other.im, im * other.re + re * other.im);
	}
	Complex operator/(const Complex& other)
	{
		return Complex((re * other.re + im * other.im) / (pow(other.re, 2) + pow(other.im, 2)), (other.re * im - re * other.im) / (pow(other.re, 2) + pow(other.im, 2)));
	}
private:
    double re, im;
};

void printer(Complex a) {
	cout << a.re << " " << a.im << "\n";
}

int main()
{
	double re1, re2, im1, im2;
	cout << "Input Real and Imagine numbers: RE IM\n";
	cin >> re1 >> im1;
	Complex a(re1, im1);
	Complex b(2, 30);
	Complex c = a/b;
	printer(c);
}

