#pragma once
#include <iostream>
using namespace std;
class Complex{
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
	friend Complex operator + (const double& lhs, const Complex& rhs);
	friend Complex operator - (const double& lhs, const Complex& rhs);
	friend Complex operator * (const double& lhs, const Complex& rhs);
	friend Complex operator / (const double& lhs, const Complex& rhs);
	friend void cmp_printer(Complex a);
	friend class Vector;
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

class Vector {
public:
	Vector& operator=(const Vector& other);
	Vector operator+(const Vector& other);
	Vector() {
		arr = new Complex[3];
		memset(arr, 0, sizeof(arr));
		this->size = 3;
	};
	Vector(int _size, Complex *_value) {
		arr = new Complex[_size];
		arr = _value;
		this->size = _size;
	};
	~Vector() {
		delete(arr);
	};
	void print() {
		cout << "( ";
		for (int i = 0; i < size; i++)
		{
			cmp_printer(arr[i]);
		}
		cout << " )\n";
	}
	
	Complex& operator[](int index) {
		if (index >= size) {
			cout << "Incorrect index";
			exit(0);
		}
		return arr[index];
	}
private:
	Complex* arr; //array of comlex
	int size; //dimension
};