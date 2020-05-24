#pragma once

#include "Vector.h"
#include "Func_massive_for_creating_vector.h"


template <class T>
class Matrix : public Vector<Vector<T>>
{
public:
	Matrix(int _nsize) : nsize(_nsize), m(_nsize), tmp_m(_nsize)
	{
		for (int i = 0; i < _nsize; i++)
		{
			T* a = new T[_nsize];
			create_random_massive(_nsize, a);
			Vector<T> tmp(nsize, a);
			this->m[i] = tmp;
			this->tmp_m[i] = tmp;
			delete[]a;
		}
	}

	void print_Matrix();

protected:
	Vector<Vector<T>> m;
	Vector<Vector<T>> tmp_m;
	int nsize;	
};

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
 
