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
	//unary
	Vector operator-();
	//binary
	Vector& operator=(const Vector& other);
	Vector operator+(const Vector& other);
	Vector operator-(const Vector& other);
	friend Complex operator*(const Vector& other1, const Vector& other2);//for scalar product
	//operations with double
	Vector operator*(const double& a);//for multiply on double
	friend Vector operator*(const double& lhs, const Vector& rhs);
	Vector operator/(const double& a);//for dividing on double
	//change value operations
	friend void change_value(Vector& _v, Complex a);
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

	int get_size() {
		return(size);
	}

	void print() {
		cout << "( ";
		for (int i = 0; i < size; i++)
		{
			cmp_printer(arr[i]);
		}
		cout << " )\n";
	}
private:
	Complex* arr; //array of comlex
	int size; //dimension
};

void cmp_printer(Complex a);
Complex* set_values(int _dim, Complex _value);
void change_value(Vector& _v, Complex a);