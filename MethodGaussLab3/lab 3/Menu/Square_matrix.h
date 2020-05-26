#pragma once

#include "Vector.h"

template <typename T>
class Matrix : public Vector<Vector<T>>
{
public:
	Matrix(int _size) : Vector<Vector<T>>(_size, Vector <T>(_size)) {}

	Matrix(int _size, Matrix<T> _m) : Vector<Vector<T>>(_m) {}

	void print_m() 
	{
		std::cout << std::endl;
		std::cout << "Matrix:" << std::endl;

		for (int j = 0; j < this->size; j++) 
		{
			for (int i = 0; i < this->size; i++)
			{
				std::cout << this->v[j][i] << "\t";
			}
			std::cout << std::endl;
		}
	}

	void fill_m() 
	{
		std::cout << "fill matrix";

		for (int i = 0; i < this->size; i++) 
		{
			for (int j = 0; j < this->size; j++)
			{
				std::cout << "[" << i << "]" << "[" << j << "]:" << std::endl;

				std::cin >> this->v[i][j];
			}
		}
	}
};