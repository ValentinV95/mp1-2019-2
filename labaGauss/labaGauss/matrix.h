#pragma once
#include "vector.h"

template<typename T> class matrix : public vector<vector<T>>
{
public:
	matrix(int sizeX, int sizeY) : size_x(sizeX), vector<vector<T>>(sizeY)
	{
		for (int i = 0; i < sizeY; i++)
			this->arr[i] = vector<T>(sizeX);
	}

	int sizeX()
	{
		return this->size_x;
	}
	int sizeY()
	{
		return this->size;
	}

	T getItem(matrix_index index)
	{
		vector<T>& _y = this->arr[index.y];
		T& _x = _y.operator[](index.x);
		return _x;
	}
	void setItem(matrix_index index, T value)
	{
		vector<T>& _y = this->arr[index.y];
		_y.operator[](index.x) = value;
	}
private:
	const int size_x;
};

