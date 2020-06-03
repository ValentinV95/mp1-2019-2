#pragma once

class Complex {
public:
	Complex(double _real, double _imag) : re(_real), im(_imag) {};

	double getReal() { return re; };
	double getImag() { return im; };

	//Unary
	Complex operator- ();
	Complex& operator++ ();
	Complex operator++ (int);
	Complex& operator-- ();
	Complex operator-- (int);
	//Binary
	Complex operator =(const Complex& other);
	Complex operator +(const Complex& other);
	Complex operator-(const Complex& other);
	Complex operator* (const Complex& other);
	Complex operator/ (const Complex& other);
	//operations with assignment
	Complex& operator+= (const Complex& other);
	Complex& operator-= (const Complex& other);
	Complex& operator*= (const Complex& other);
	Complex& operator/= (const Complex& other);
	bool operator ==(const Complex& other);
	bool operator !=(const Complex& other);
	//double operations 
	Complex operator+(const double& a);
	Complex operator-(const double& a);
	Complex operator*(const double& a);
	Complex operator/(const double& a);
	friend Complex operator + (const double& lhs, const Complex& rhs);
	friend Complex operator - (const double& lhs, const Complex& rhs);
	friend Complex operator * (const double& lhs, const Complex& rhs);
	friend Complex operator / (const double& lhs, const Complex& rhs);


private: 
	double re;
	double im;
};