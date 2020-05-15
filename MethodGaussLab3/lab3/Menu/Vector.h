#pragma once

#include "iostream"
#include <iomanip>

#include "Func_massive_for_creating_vector.h"

template <class T>
class Vector
{
public:
	Vector(int _nsize = 0)
	{
		this->nsize = _nsize;

		a = new T[_nsize];
		for (int i = 0; i < _nsize; i++)
		{
			this->a[i] = 0;
		}
	}

	Vector(int _nsize, T* _a);

	Vector(const Vector& _copy);

	int getsize();

	void create_massive_vector();

	void print_coord();						

	Vector<T>& operator= (const Vector<T>& rhs);

	Vector<T> operator+ (const Vector<T>& rhs);
	Vector<T> operator- (const Vector<T>& rhs);
	Vector<T> operator* (const Vector<T>& rhs);
	Vector<T> operator/ (const Vector<T>& rhs);

	T& operator[](int index)
	{
		return a[(index)];
	}

	~Vector();
	
private:
	int nsize;

private:
	T *a;
};

template <class T>
Vector<T>::Vector(int _nsize, T* _a)
{
	this->nsize = _nsize;

	this->a = new T[_nsize];
	for (int i = 0; i < _nsize; i++)
	{
		this->a[i] = _a[i];
	}
}

template <class T>
Vector<T>::Vector(const Vector<T>& _copy)
{
	this->nsize = _copy.nsize;

	this->a = new T[nsize];
	for (int i = 0; i < nsize; i++)
	{
		this->a[i] = _copy.a[i];
	}
}

template <class T>
int Vector<T>::getsize()
{
	return nsize;
}

template <class T>
void Vector<T>::print_coord()
{
	std::cout << std::fixed;

	std::cout.precision(4);
	for (int i = 0; i < nsize; i++)
	{
		std::cout << std::setw(4) << a[i] << "\t\t";
	}
}

template <class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& rhs)
{
	if (this != &rhs)
	{
		T* _v = new T[rhs.nsize];

		for (int i = 0; i < rhs.nsize; i++)
		{
			_v[i] = rhs.a[i];
		}

		delete[]this->a;

		this->a = _v;
		this->nsize = rhs.nsize;
	}

	return *this;
}

template <class T>
Vector<T> Vector<T>::operator+ (const Vector<T>& rhs)
{
	Vector<T> temp(rhs.nsize);

	for (int i = 0; i < nsize; i++)
	{
		temp[i] = this->a[i] + rhs.a[i];
	}

	return temp;
}

template <class T>
Vector<T> Vector<T>::operator- (const Vector<T>& rhs)
{
	Vector<T> temp(rhs.nsize);

	for (int i = 0; i < nsize; i++)
	{
		temp[i] = this->a[i] - rhs.a[i];
	}

	return temp;
}

template <class T>
Vector<T> Vector<T>::operator* (const Vector<T>& rhs)
{
	Vector<T> temp(rhs.nsize);

	for (int i = 0; i < rhs.nsize; i++)
	{
		temp[i] = this->a[i] * rhs.a[i];
	}

	return temp;
}

template <class T>
Vector<T> Vector<T>::operator/ (const Vector<T>& rhs)
{
	Vector<T> temp(rhs.nsize);

	for (int i = 0; i < nsize; i++)
	{
		temp[i] = this->a[i] / rhs.a[i];
	}

	return temp;
}

template <class T>
Vector<T>::~Vector()
{
	delete []a;
}





