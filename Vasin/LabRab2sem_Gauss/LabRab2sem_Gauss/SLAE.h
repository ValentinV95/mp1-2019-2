#pragma once
#include "My_vector.h"
#include "My_matrix.h"
using namespace std;

template <typename T>
class SLAE 
{

public:

	SLAE(My_matrix<T>& _mas)
	{
		m_mas_copy = _mas;
	}

	~SLAE()
	{}

	My_matrix<T> get_triangular_matrix()
	{
		return m_mas; // возвращаем матрицу треугольного вида
	}

	My_vector <T> gauss(My_vector<T>& _fm)
	{
		m_mas = m_mas_copy;
		int size;
		size = m_mas.GetSize();
		T error = 0.0000001;
		// Приведение к треугольному виду
		for (int j = 0; j < size; j++)
		{
			int i = 0;
			int max_abs_index = i + j;
			T max_abs = abs(this->m_mas[i + j][j]);
			for (i + j + 1; i + j + 1 < size; i++)
			{
				if (abs(this->m_mas[i + j][j]) > max_abs)
				{
					max_abs_index = i + j;
				}
			}
			swap(_fm, j, max_abs_index);
			for (int l = j + 1; l < size; l++)
			{
				if (this->m_mas[j][j] != 0)
				{
					T rate = -(this->m_mas[l][j] / this->m_mas[j][j]);
					for (int k = j; k < size; k++)
					{
						this->m_mas[l][k] += this->m_mas[j][k] * rate;
					}
					_fm[l] += _fm[j] * rate;
				}
				else
				{
					cout << "Division by 0 when searching rate!" << endl;
					exit(3);
				}
			}
		}
		// удаление ошибки
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (abs(this->m_mas[i][j]) < error)
				{
					this->m_mas[i][j] = 0;
				}
			}
			if (abs(_fm[i]) < error)
			{
				_fm[i] = 0;
			}
		}
		// Проверка недостающих решений
		for (int i = 0; i < size; i++)
		{
			T sum = 0;
			for (int j = 0; j < size; j++)
			{
				sum += abs(this->m_mas[i][j]);
			}
			if ((sum == 0) && (_fm[i] != 0))
			{
				cout << "No solutions: 0 * x = c, c != 0;" << endl;
				exit(2);
			}
			if ((sum == 0) && (_fm[i] == 0))
			{
				cout << "Can't solve: the equation depends on the variable" << endl;
				exit(3);
			}
		}
		// Находим решения
		T* sol = new T[size];
		for (int i = size - 1; i >= 0; i--)
		{
			T tmp = 0;
			for (int j = i + 1; j < size; j++)
			{
				tmp += this->m_mas[i][j] * sol[j];
			}
			sol[i] = (_fm[i] - tmp) / this->m_mas[i][i];
		}
		return My_vector<T>(size, sol);
	}

private:

	My_matrix<T> m_mas; // матрица
	My_matrix<T> m_mas_copy; // копия матрицы

	T abs(T a)
	{
		if (a < 0)
		{
			return -a;
		}
		else
		{
			return a;
		}
	}

	void swap(My_vector<T>& _fm, int str1, int str2)
	{
		int size;
		size = m_mas.GetSize();
		if ((str1 < size) && (str2 < size) && (str1 >= 0) && (str2 >= 0))
		{
			//Поменяем местами свободные члены
			T r_tmp;
			r_tmp = _fm[str1];
			_fm[str1] = _fm[str2];
			_fm[str2] = r_tmp;

			//Поменяем местами строки в матрице
			T* tmp = new T[size];
			for (int i = 0; i < size; i++)
			{
				tmp[i] = this->m_mas[str1][i];
				this->m_mas[str1][i] = this->m_mas[str2][i];
				this->m_mas[str2][i] = tmp[i];
			}
			delete[]tmp;
		}
		else
		{
			cout << "Error number of string!";
			exit(1); //выход с ошибкой
		}
	}
};