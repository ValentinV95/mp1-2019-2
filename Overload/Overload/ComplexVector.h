#pragma once

#include "iostream"

#include "Complex.h"

class Vector
{
public:
	Vector()
	{
		a = new Complex[size];

		Complex c0 = { 0, 0 };
		for (int i = 0; i < size; i++)
		{
			a[i] = c0;
		}
	}

	Vector(Complex c)
	{
		a = new Complex[size];

		for (int i = 0; i < size; i++)
		{
			a[i] = c;
		}
	}

	Vector(const Vector& _copy)
	{
		
		a = new Complex[size];

		for (int i = 0; i < size; i++)
		{
			a[i] = _copy.a[i];
		}
	}
	
	Vector operator+ ();
	Vector operator- ();
	Vector& operator++ ();						//++re
	Vector operator-- ();						//--re
	Vector operator++ (int);					//re++
	Vector operator-- (int);					//re--
	bool operator! ();							//!re

	Vector& operator= (const Vector& rhs);
	Vector operator+ (const Vector& rhs);
	Vector operator- (const Vector& rhs);
	Vector operator* (const Vector& rhs);
	Vector operator/ (const Vector& rhs);
	Vector& operator+= (const Vector& rhs);
	Vector& operator-= (const Vector& rhs);
	Vector& operator*= (const Vector& rhs);
	Vector& operator/= (const Vector& rhs);

	bool operator== (const Vector& rhs);
	bool operator!= (const Vector& rhs);


	Complex& operator[](int index)
	{
		return a[index];
	}

	void printV();

	~Vector()
	{
		delete[]a;
	}

private:
	Complex* a;
	static int size;
};
