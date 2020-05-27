#pragma once
#include "matrix_.h"
#include <iostream>

class SLAU : public matrix_<double>
{
public:
	SLAU(int sizeX, int sizeY) : matrix_<double>(sizeX, sizeY) { }
	vvector<double> gauss(vvector<double> ex)
	{
		porydok(ex);
		int size_X = this->sizeX();
		matrix_print();
		vvector<double> arr = vvector<double>(size_X, 0);
		vvector<vvector<double>>* _mat = (vvector<vvector<double>>*)this;
		for (int i = sizeY() - 1; i >= 0; i--)
		{
			double ans = ex[i];
			double sum = getSum(_mat->operator[](i), arr);
			double val = getValue(_mat->operator[](i));
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
	void porydok(vvector<double> ex)
	{
		int i = 1;
		int size = this->sizeY();
		while (i < size)
		{
			habr(ex);
			int zc_1 = zero_in_start(this->arr[i - 1]);
			int zc_2 = zero_in_start(this->arr[i]);
			if (zc_1 == zc_2) revert(i - 1, i, ex);
			else i++;
			matrix_print();
		}
		habr(ex);
	}
	static double round(double n, int count)
	{
		double st = pow(count, 10);
		return std::round(n * st) / st;
	}
	static int zero_in_start(vvector<double>& arr)
	{
		int length = arr.size;
		for (int i = 0; i < length; i++)
			if (arr[i] != 0)
				return i + 1;
		return length;
	}
	void habr(vvector<double> ex);
	void revert(int arr1_index, int arr2_index, vvector<double> ex);
	static double getSum(vvector<double> vals, vvector<double> arr)
	{
		int length = arr.size;
		double sum = 0;
		for (int i = 0; i < length; i++)
			if (arr[i] != 0)
				sum += arr[i] * vals[i];
		return sum;
	}
	static double getValue(vvector<double> vec)
	{
		int length = vec.size;
		for (int i = 0; i < length; i++)
			if (vec[i] != 0)
				return vec[i];
		return 0;
	}
};
