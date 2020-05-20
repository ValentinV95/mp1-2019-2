#pragma once

struct matrix_index
{
	int x;
	int y;

	matrix_index(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

template<typename T> static void swap(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

