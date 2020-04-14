#pragma once
#include <iostream>
using namespace std;
class Complex {
public:
	Complex operator-();
	Complex& operator--();
	Complex operator--(int);
	Complex& operator++();
	Complex operator++(int);
	Complex& operator=(const Complex& other);
	Complex operator+(const Complex& other);
	Complex operator-(const Complex& other);
	Complex operator*(const Complex& other);
	Complex operator/(const Complex& other);
	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);
	bool operator==(const Complex& other);
	bool operator!=(const Complex& other);
	bool operator<(const Complex& other);
	bool operator<=(const Complex& other);
	bool operator>(const Complex& other);
	bool operator>=(const Complex& other);
	Complex operator+(const double& a);
	Complex operator-(const double& a);
	Complex operator*(const double& a);
	Complex operator/(const double& a);
	friend void printer(Complex a);
	Complex() {
		re = 0;
		im = 0;
	}
	Complex(double a, double b) {
		re = a;
		im = b;
	}
private:
	double re, im;
};