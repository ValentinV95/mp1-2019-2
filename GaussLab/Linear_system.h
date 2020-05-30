#pragma once
#include "Vector.h"
#include "Matrix.h"
#include "Mod.h"

using namespace std;


template < typename T >
class Linear_system : public Matrix<T>
{
public:
	Linear_system(int n) : Matrix <T>(n)
	{}

	void filler()
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				cout << "Введите [" << j + 1 << "] коэффициент" << "[" << i + 1 << "] уравнения:" << endl;
				cin >> this->m_x[i][j];
			}
		}
	}

	void check(T *rv)
	{
		T* check = new T[this->size];
		cout << endl;
		cout << "Правое значение при проверке:" << endl;
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				check[i] += this->m_x[i][j]*rv[j];
			}
			cout << rv[i] << "\t";
		}
	}

	void swap(int str1, int str2, T*rv)
	{
		if (str1 < this->size && str2 < this->size)
		{
			T r_tmp;
			r_tmp = rv[str1];
			rv[str1] = rv[str2];
			rv[str2] = r_tmp;
			T* tmp = new T[this->size];
			for (int i = 0; i < this->size; i++)
			{
				tmp[i] = this->m_x[str1][i];
				this->m_x[str1][i] = this->m_x[str2][i];
				this->m_x[str2][i] = tmp[i];
			}
			delete[]tmp;
		}
		else
		{
			cout << "Неправильная строка!";
			exit(1);
		}
	}

	void print(T *rv)
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				cout << this->m_x[i][j] << "\t";
			}
			cout << "| " << rv[i] << endl;
		}
		cout << endl;
	}

	My_vector <T> gauss_method(T* rv)
	{
		for (int j = 0; j < this->size; j++)
		{
			int i = 0;
			int max_index = i + j;
			T max = mod<T>(this->m_x[i + j][j]);
			for (i + j + 1; i + j + 1 < this->size; i++);
			{
				if (mod<T>(this->m_x[i + j][j]) > max)
				{
					max_index = i + j;
				}
			}
			swap(j, max_index, rv);
			for (int n = j + 1; n < this->size; n++)
			{
				if (this->m_x[j][j] != 0)
				{
					for (int k = j; k < this->size; k++)
					{
						this->m_x[n][k] += this->m_x[j][k] * (-(this->m_x[n][j] / this->m_x[j][j]));
					}
					rv[n] += rv[j] * (-(this->m_x[n][j] / this->m_x[j][j]));
				}
				else
				{
					cout << "Ошибка! Произошло деление на 0" << endl;
					exit(3);
				}
			}
		}

		for (int i = 0; i < this->size; i++)
		{
			T sum = 0;
			for (int j = 0; j < this->size; j++)
			{
				sum += mod<T>(this->m_x[i][j]);
			}
			if ((sum == 0) && (rv[i] != 0))
			{
				cout << "Система не совместна, нет решений." << endl;
				exit(2);
			}
			if ((sum == 0) && (rv[i] == 0))
			{
				cout << "Система не имеет частных решений." << endl;
				exit(3);
			}
		}

		T* res = new T[this->size];
		for (int i = this->size - 1; i >= 0; i--)
		{
			T tmp = 0;
			for (int j = i + 1; j < this->size; j++)
			{
				tmp += this->m_x[i][j] * res[j];
			}
			res[i] = (rv[i] - tmp) / this->m_x[i][i];
		}
		return My_vector<T>(this->size, res);
	}
};