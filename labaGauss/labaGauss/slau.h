#pragma once
#include "matrix.h"
#include <iostream>

class slau : public matrix<double>
{
public:
	slau(int sizeX, int sizeY) : matrix<double>(sizeX, sizeY) { }
	vector<double> gauss(vector<double> ex)
	{
		order(ex);
		int size_X = this->sizeX();
		print();

		vector<double> arr = vector<double>(size_X, 0);

		vector<vector<double>>* _mat = (vector<vector<double>>*)this;
		for (int i = sizeY() - 1; i >= 0; i--)
		{
			double ans = ex[i];
			double sum = getSum(_mat->operator[](i), arr);
			double val = getValue(_mat->operator[](i));

			arr[i] = round((ans - sum) / val, 5);
		}

		return arr;
	}

	double& operator[](matrix_index index)
	{
		vector<double>& _y = this->arr[index.y];
		double& _x = _y.operator[](index.x);
		return _x;
	}
	void print();

private:
	void order(vector<double> ex)
	{
		int i = 1;
		int size = this->sizeY();
		while (i < size)
		{
			sort(ex);
			int zc_1 = zeroCount(this->arr[i - 1]);
			int zc_2 = zeroCount(this->arr[i]);
			if (zc_1 == zc_2) revert(i - 1, i, ex);
			else i++;
			print();
		}
		sort(ex);
	}
	static double round(double n, int count)
	{
		double _pow = pow(count, 10);
		return std::round(n * _pow) / _pow;
	}

	static int zeroCount(vector<double>& arr)
	{
		int length = arr.size;
		for (int i = 0; i < length; i++)
			if (arr[i] != 0)
				return i + 1;
		return length;
	}


	/*template<typename T> static void swap(T* a, T* b)
	{
		T tmp = *a;
		*a = *b;
		*b = tmp;
	}*/

	void sort(vector<double> ex);
	void revert(int arr1_index, int arr2_index, vector<double> ex);
	static double getSum(vector<double> vals, vector<double> arr)
	{
		int length = arr.size;
		double sum = 0;
		for (int i = 0; i < length; i++)
			if (arr[i] != 0)
				sum += arr[i] * vals[i];
		return sum;
	}
	static double getValue(vector<double> arr)
	{
		int length = arr.size;
		for (int i = 0; i < length; i++)
			if (arr[i] != 0)
				return arr[i];
		return 0;
	}

};
