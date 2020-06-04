#pragma once
#include <iostream>
#include "matrix_.h"

class SLAU : public matrix<double>
{
public:
	SLAU(int sizeX, int sizeY) : matrix<double>(sizeX, sizeY) { }
	vvector<double> gauss(vvector<double> ex)
	{
		int _sizeX = sizeX();
		int _sizeY = sizeY();
		matrix<double> _matrix = matrix<double>(_sizeX, _sizeY);
		for (int x = 0; x < _sizeX; x++)
			for (int y = 0; y < _sizeY; y++)
			{
				double val = this->operator[](element(x, y));
				_matrix.setItem(element(x, y), val);
			}
		porydok(_matrix, ex);
		int size_X = this->sizeX();
		matrix_print();
		vvector<double> arr = vvector<double>(size_X, 0);
		for (int i = sizeY() - 1; i >= 0; i--)
		{
			double ans = ex[i];
			double sum = getSum(_matrix.operator[](i), arr);
			double val = zeroinstart(_matrix.operator[](i));
			arr[i] = round((ans - sum) / val, 5);
		}
		return arr;
	}
	double& operator[](element index)
	{
		vvector<double>& _y = this->arr[index.y];
		double& _x = _y.operator[](index.x);
		return _x;
	}
	void matrix_print();
private:
	static void porydok(matrix<double> _matrix, vvector<double> ex)
	{
		int i = 1;
		int size = _matrix.sizeY();
		while (i < size)
		{
			habr(_matrix, ex);
			int zc_1 = zeroCount(_matrix[i - 1]);
			int zc_2 = zeroCount(_matrix[i]);
			if (zc_1 == zc_2) revert(_matrix, i - 1, i, ex);
			else i++;
		}
		habr(_matrix, ex);
	}
	static double round(double n, int count)
	{
		double _pow = pow(count, 10);
		return std::round(n * _pow) / _pow;
	}
	static int zeroCount(vvector<double>& arr)
	{
		int length = arr.size;
		for (int i = 0; i < length; i++)
			if (arr[i] != 0)
				return i + 1;
		return length;
	}
	static void habr(matrix<double> _matrix, vvector<double> ex)
	{
		int count = _matrix.size;
		for (int i = 1; i < count; i++)
		{
			int k = i;
			for (int j = i - 1; j >= 0; j--)
				if (zeroCount(_matrix[k]) < zeroCount(_matrix[j]))
				{
					swap(&_matrix[k], &_matrix[j]);
					swap(&ex[k], &ex[j]);
					k--;
				}
				else
					break;
		}
	}
	static double getSum(vvector<double> vals, vvector<double> arr)
	{
		int length = arr.size;
		double sum = 0;
		for (int i = 0; i < length; i++)
			if (arr[i] != 0)
				sum += arr[i] * vals[i];
		return sum;
	}
	static double zeroinstart(vvector<double> arr)
	{
		int length = arr.size;
		for (int i = 0; i < length; i++)
			if (arr[i] != 0)
				return arr[i];
		return 0;
	}
	static void revert(matrix<double> _matrix, int arr1_index, int arr2_index, vvector<double> ex)
	{
		vvector<double> arr1 = _matrix[arr1_index];
		vvector<double> arr2 = _matrix[arr2_index];
		int index = 0;
		int length = arr1.size;
		double value = 0;
		for (int i = 0; i < length; i++)
		{
			index = i;
			if (arr1[i] == 0) continue;
			value = arr2[i] / arr1[i];
			break;

		}

		for (int i = 0; i < length; i++) arr2[i] = round(arr2[i] - arr1[i] * value, 100);

		ex[arr2_index] = ex[arr2_index] - ex[arr1_index] * value;

	}

};


