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
private:
	const int size_x;
};

