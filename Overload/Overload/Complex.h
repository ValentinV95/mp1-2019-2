#pragma once

class Complex
{
public:
	Complex(double _re = 0, double _im = 0) : re(_re), im(_im) {};
	
	Complex(const Complex& other) : re(other.re), im(other.im) {};

	Complex operator+ ();
	Complex operator- ();
	Complex& operator++ ();						//++re
	Complex operator-- ();						//--re
	Complex operator++ (int);					//re++
	Complex operator-- (int);					//re--
	bool operator! ();							//!re

	Complex& operator= (const Complex& rhs);
	Complex operator+ (const Complex& rhs);
	Complex operator- (const Complex& rhs);
	Complex operator* (const Complex& rhs);
	Complex operator/ (const Complex& rhs);
										//Complex operator% (const Complex& rhs);
	Complex& operator+= (const Complex& rhs);
	Complex& operator-= (const Complex& rhs);
	Complex& operator*= (const Complex& rhs);
	Complex& operator/= (const Complex& rhs);
	bool operator== (const Complex& rhs);
	bool operator!= (const Complex& rhs);
	bool operator< (const Complex& rhs);
	bool operator<= (const Complex& rhs);
	bool operator> (const Complex& rhs);
	bool operator>= (const Complex& rhs);

	Complex operator+ (const double& rhs);
	Complex operator- (const double& rhs);
	Complex operator* (const double& rhs);
	Complex operator/ (const double& rhs);
	Complex& operator+= (const double& rhs);
	Complex& operator-= (const double& rhs);
	Complex& operator*= (const double& rhs);
	Complex& operator/= (const double& rhs);

	friend Complex operator+ (const double& a, const Complex& rhs);
	friend Complex operator- (const double& a, const Complex& rhs);
	friend Complex operator* (const double& a, const Complex& rhs);
	friend Complex operator/ (const double& a, const Complex& rhs);


	






	void printE();
	void print();

private:
	double re;
	double im;
};
