#pragma once
#include "vvector.h"

template<typename T> class matrix_ : public vvector<vvector<T>>
{
public:
	matrix_(int sizeX, int sizeY) : size_x(sizeX), vvector<vvector<T>>(sizeY)
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
private:
	const int size_x;
};