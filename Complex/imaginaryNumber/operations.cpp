 
#include "classComplex.h"

//Unary

Complex Complex::operator- () {
	return Complex(-re, -im);
}

Complex& Complex::operator++ () {
	re++;
	return *this;
}

Complex Complex::operator++ (int) {
	Complex res(*this);
	++(*this);
	return res;
}

Complex& Complex::operator-- () {
	re--;
	return *this;
}

Complex Complex::operator-- (int) {
	Complex res(*this);
	--(*this);
	return res;
}


//Binary

Complex Complex::operator =(const Complex& other) {
	re = other.re, im = other.im;
	return *this;
}

Complex Complex::operator +(const Complex& other) {
	return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) {
	return Complex(re - other.re, im - other.im);
}

Complex Complex::operator* (const Complex& other) {
	return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
}

Complex Complex::operator/ (const Complex& other) {
	return Complex((re * other.re + im * other.im) / (other.re * other.re + other.im * other.im), (im * other.re - re * other.im) / (other.re * other.re + other.im * other.im));
}


//operations with assignment

Complex& Complex::operator+= (const Complex& other) {
	re += other.re;
	im += other.im;
	return*this;
}

Complex& Complex::operator-= (const Complex& other) {
	re -= other.re;
	im -= other.im;
	return*this;
}

Complex& Complex::operator*= (const Complex& other) {
	*this = *this * other;
	return*this;
}

Complex& Complex::operator/= (const Complex& other) {
	*this = *this / other;
	return*this;
}


//Bool operations

bool Complex::operator ==(const Complex& other) {
	if ((re == other.re) && (im == other.im))
		return true;
	return false;
}

bool Complex::operator !=(const Complex& other) {
	return !(*this == other);
}

//double operations 

Complex Complex::operator+(const double& a) {
	return Complex(this->re*a, this->im);
}

Complex Complex::operator-(const double& a) {
	return Complex(this->re - a, this->im);
}

Complex Complex::operator*(const double& a) {
	return Complex(this->re * a, this->im * a);
}

Complex Complex::operator/(const double& a) {
	return Complex(this->re / a, this->im / a);
}

Complex operator + (const double& lhs, const Complex& rhs) {
	return Complex(lhs + rhs.re, rhs.im);
}

Complex operator - (const double& lhs, const Complex& rhs) {
	return Complex(lhs - rhs.re, rhs.im);
}

Complex operator * (const double& lhs, const Complex& rhs) {
	return Complex(lhs * rhs.re, lhs * rhs.im);
}

Complex operator / (const double& lhs, const Complex& rhs) {
	Complex lhsComplex(lhs, 0);
	return lhsComplex / rhs;
}