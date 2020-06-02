#pragma once
#include <iostream>

class Complex
{
public:

    Complex(double imm, double ree)
    {
        im = imm;
        re = ree;
    }

    Complex()
    {
        re = 0;
        im = 0;
    }

    Complex& operator=(const Complex& other)
    {
        re = other.re; im = other.im;
        return *this;
    }


    Complex operator + (const Complex& ch)
    {
        return Complex(re + ch.re, im + ch.im);
    }

    Complex operator-(const Complex& ch)
    {
        return Complex(re - ch.re, im - ch.im);
    }


    Complex operator*(const Complex& ch)
    {
        return Complex(re * ch.re - im * ch.im, 2 * im * ch.re);
    }

    Complex operator/(const Complex& ch)
    {
        double d1, d2;
        d1 = (re * ch.re + im * ch.im) / (ch.re * ch.re + ch.im * ch.im);
        d2 = (ch.im * im - re * ch.im) / (ch.re * ch.re + ch.im * ch.im);
        re = d1;
        im = d2;
        return *this;
        //Complex c(d1, d2);
        //return c;
    }

    Complex& operator+=(const Complex& ch)
    {
        double _re = re + ch.re, _im = im + ch.im;
        re = _re; im = _im;
        return *this;
    }

    Complex& operator*=(const Complex& rhs)
    {
        double _re = re * rhs.re - im * rhs.im;
        double _im = im * rhs.re + re * rhs.im;
        re = _re; im = _im;
        return *this;
    }

    bool operator ==(const Complex& ch)
    {
        if ((re == ch.re) && (im == ch.im))
            return true;
        return false;
    }

    bool operator !=(const Complex& ch)
    {
        return !(*this == ch);
    }





    void print();

    friend Complex operator+(const double& lhs, const Complex& rhs);
    friend Complex operator*(const double& a, const Complex& ch);
    friend Complex operator*(const Complex& ch, const double& a);


private:


    double re;
    double im;



};
