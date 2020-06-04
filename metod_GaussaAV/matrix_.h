#pragma once
#include "vvector.h"

template<typename T> class matrix : public vvector<vvector<T>>
{
public:
	matrix(int sizeX, int sizeY) : size_x(sizeX), vvector<vvector<T>>(sizeY)
	{
		for (int i = 0; i < sizeY; i++)
			this->arr[i] = vvector<T>(sizeX);
	}
	int sizeX()
	{
		return this->size_x;
	}
	int sizeY()
	{
		return this->size;
	}
	T getItem(element index)
	{
		vvector<T>& _y = this->arr[index.y];
		T& _x = _y.operator[](index.x);
		return _x;
	}
	void setItem(element index, T value)
	{
		vvector<T>& _y = this->arr[index.y];
		_y.operator[](index.x) = value;
	}
private:
	const int size_x;
};