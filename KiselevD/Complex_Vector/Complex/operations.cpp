#include "header.h"
//unary operations
Complex Complex::operator-()
{
	return Complex(-re, -im);
}
Complex& Complex::operator--()//--a
{
	re--;
	return*this;
}
Complex Complex::operator--(int)//a--
{
	Complex res(*this);
	--(*this);
	return res;
}
Complex& Complex::operator++()//++a
{
	re++;
	return*this;
}
Complex Complex::operator++(int)//a++
{
	Complex res(*this);
	++(*this);
	return res;
}
//binary operations
Complex& Complex::operator=(const Complex& other)
{
	re = other.re;
	im = other.im;
	return *this;
}
Complex Complex::operator+(const Complex& other)
{
	return Complex(re + other.re, im + other.im);
}
Complex Complex::operator-(const Complex& other)
{
	return Complex(re - other.re, im - other.im);
}
Complex Complex::operator*(const Complex& other)
{
	return Complex(re * other.re - im * other.im, im * other.re + re * other.im);
}
Complex Complex::operator/(const Complex& other)
{
	return Complex((re * other.re + im * other.im) / (pow(other.re, 2) + pow(other.im, 2)), (other.re * im - re * other.im) / (pow(other.re, 2) + pow(other.im, 2)));
}
Complex& Complex::operator+=(const Complex& other) {
	re += other.re;
	im += other.im;
	return*this;
}
Complex& Complex::operator-=(const Complex& other) {
	re -= other.re;
	im -= other.im;
	return*this;
}
Complex& Complex::operator*=(const Complex& other) {
	double _re, _im;
	_re = re * other.re - im * other.im;
	_im = im * other.re + re * other.im;
	re = _re;
	im = _im;
	return*this;
}
Complex& Complex::operator/=(const Complex& other) {
	double _re, _im;
	_re = (re * other.re + im * other.im) / (pow(other.re, 2) + pow(other.im, 2));
	_im = (other.re * im - re * other.im) / (pow(other.re, 2) + pow(other.im, 2));
	re = _re;
	im = _im;
	return*this;
}
bool Complex::operator==(const Complex& other) {
	return ((re == other.re) && (im == other.im));
}
bool Complex::operator!=(const Complex& other) {
	return ((re != other.re) || (im != other.im));
}
//absolute value comparsion
bool Complex::operator<(const Complex& other) {
	return (sqrt(pow(re, 2) + pow(im, 2)) < sqrt(pow(other.re, 2) + pow(other.im, 2)));
}
bool Complex::operator<=(const Complex& other) {
	return ((*this < other) || (*this == other));
}
bool Complex::operator>(const Complex& other) {
	return (sqrt(pow(re, 2) + pow(im, 2)) > sqrt(pow(other.re, 2) + pow(other.im, 2)));
}
bool Complex::operator>=(const Complex& other) {
	return ((*this > other) || (*this == other));
}
//double operations 
Complex Complex::operator+(const double&a) {
	return Complex(this->re + a, this->im);
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

//vector operations
Vector Vector::operator-()
{
	Complex* tmp = new Complex[this->size];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = -arr[i];
	}
	return Vector(this->size, tmp);
	delete[] tmp;
}

Vector& Vector::operator=(const Vector& other) {
	delete(this->arr);
	this->size = other.size;
	this->arr = new Complex[other.size];
	for (int i = 0; i < other.size; i++)
	{
		this->arr[i] = other.arr[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& other)
{
	if (other.size == this->size)
	{
		Complex* tmp = new Complex[this->size];
		for (int i = 0; i < this->size; i++)
		{
			tmp[i]=other.arr[i] + this->arr[i];
		}
		return Vector(other.size, tmp);
		delete[] tmp;
	}
	{
		cout << "Dimensions don't match(+)\n";
		exit(0);
	}
}

Vector Vector::operator-(const Vector& other)
{
	if (other.size == this->size)
	{
		Complex* tmp = new Complex[this->size];
		for (int i = 0; i < this->size; i++)
		{
			tmp[i] = this->arr[i] - other.arr[i];
		}
		return Vector(other.size, tmp);
		delete[] tmp;
	}
	{
		cout << "Dimensions don't match(-)\n";
		exit(0);
	}
}

Complex operator*(const Vector& other1, const Vector& other2) {
	if (other1.size == other2.size)
	{
		Complex scalar;
		for (int i = 0; i < other1.size; i++)
		{
			scalar = scalar + (other1.arr[i] * other2.arr[i]);
		}
		return scalar;
	}
	{
		cout << "Dimensions don't match(*)\n";
		exit(0);
	}
}

Vector Vector::operator*(const double& a) {
	Complex* tmp = new Complex[this->size];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i] * a;
	}
	return Vector(this->size, tmp);
	delete[] tmp;
}

Vector operator * (const double& lhs, const Vector& rhs) {
	Complex* tmp = new Complex[rhs.size];
	for (int i = 0; i < rhs.size; i++)
	{
		tmp[i] = rhs.arr[i] * lhs;
	}
	return Vector(rhs.size, tmp);
	delete[] tmp;
}

Vector Vector::operator/(const double& a) {
	Complex* tmp = new Complex[this->size];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i] / a;
	}
	return Vector(this->size, tmp);
	delete[] tmp;
}