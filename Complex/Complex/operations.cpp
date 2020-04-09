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

