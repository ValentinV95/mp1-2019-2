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
	Vector() {
		arr = new Complex[3];
		Complex _default;
		for (int i = 0; i < 3; i++)
		{
			arr[i] = _default;
		}
		this->size = 3;
		this->value = _default;
	};

	Vector(int _size, Complex _value) {
		arr = new Complex[_size];
		for (int i = 0; i < _size; i++)
		{
			arr[i] = _value;
		}
		this->size = _size;
		this->value = _value;
	};

	~Vector() {
		delete(arr);
	};

	/*Complex& operator[](int index) {
		if (index >= size) {
			cout << "Incorrect index";
			exit(0);
		}
		return arr[index];
	}*/
	void print() {
		cout << "( ";
		for (int i = 0; i < size; i++)
		{
			cmp_printer(arr[i]);
		}
		cout << " )\n";
	}
	Vector& operator=(const Vector& other);
	Vector operator+(const Vector& other);
private:
	Complex* arr; //array
	int size; //dimension
	Complex value;
};