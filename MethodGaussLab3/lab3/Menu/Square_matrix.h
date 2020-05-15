#pragma once

#include "Vector.h"
#include "Func_massive_for_creating_vector.h"


template <class T>
class Matrix
{
public:
	Matrix(int _nsize) : nsize(_nsize), m(_nsize)
	{
		for (int i = 0; i < _nsize; i++)
		{
			T* a = new T[_nsize];
			create_random_massive(_nsize, a);
			Vector<T> tmp(nsize, a);
			m[i] = tmp;
			delete[]a;
		}
	}

	Matrix(int _nsize, int value) : nsize(_nsize), m(_nsize)
	{
		for (int i = 0; i < _nsize; i++)
		{
			T* a = new T[_nsize];
			create_null_massive(_nsize, a);
			Vector<T> tmp(nsize, a);
			m[i] = tmp;
			delete[]a;
		}
	}

	Matrix(const Matrix& _copy);

	Vector<T> get_vector(int index)
	{
		return m[index];
	}

	void print_Matrix();

	Matrix<T>& operator= (const Matrix<T>& rhs)
	{
		for (int i = 0; i < this->nsize; i++)
		{
			this->m[i] = rhs.m[i];
		}
	}


	Vector<Vector<T>> m;
	int nsize;	
};

template <class T>
Matrix<T>::Matrix(const Matrix& _copy)
{
	this->_size = _copy.nsize;
	
	for (int i = 0; i < nsize; i++)
	{
		this->v = _copy.v;
	}
}

template <class T>
void Matrix<T>::print_Matrix()
{
	for (int i = 0; i < nsize; i++)
	{
		Vector<T> tmp (nsize);
		tmp = m[i];
		tmp.print_coord();
	}
}
 
