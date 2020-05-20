#pragma once
#include "dop.h"

template<typename T> class vector
{
public:
	vector() : vector(0) { }
	vector(int size) : vector(new T[size], size) { }
	vector(int size, T obj) : vector(size)
	{
		for (int i = 0; i < size; i++)
			arr[i] = obj;
	}
	vector(T* arr, int size)
	{
		this->arr = arr;
		this->size = size;
	}

	T& operator[](int index)
	{
		return arr[index];
	}
	int size;
protected:
	T* arr;
};
