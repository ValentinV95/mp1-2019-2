#pragma once

#include "Matrix.h"
#include "Vector.h"
#include "Mod.h"

template <typename T>
class Linear_System : public Matrix <T>
{
private:
	T* ptr;
public:
	Linear_System(int N, T _ptr = T()) : Matrix<T>(N)
	{
		ptr = new T[N];

		for (int i = 0; i < N; i++)
		{
			ptr[i] = _ptr;
		}
	}

	~Linear_System()
	{
		delete[]ptr;
	}

	void printMatrix(T* ptr)
	{
		for (int i = 0; i < this->SIZE; i++)
		{
			for (int j = 0; j < this->SIZE; j++)
			{
				cout << this->ptrVector[i][j] << '\t';
			}
			cout << "\t| " << ptr[i];
			cout << endl;
		}
		cout << endl;
	}

	void FillMatrix()
	{
		for (int i = 0; i < this->SIZE; i++)
		{
			for (int j = 0; j < this->SIZE; j++)
			{
				cout << "Enter [" << j + 1 << "] equation" << "[" << i + 1 << "] coefficient:" << endl;
				cin >> this->ptrVector[i][j];
			}
		}
	}
	

	void minus(int val1, int val2, T* ptr, int index)
	{
		T ptrIndex = this->ptrVector[val2][index];

		for (int i = 0; i + index < this->SIZE; i++)
		{
			this->ptrVector[val2][i + index] -= this->ptrVector[val1][i + index] * ptrIndex / this->ptrVector[val1][index];
		}
		ptr[val2] -= ptr[val1] * ptrIndex / this->ptrVector[val1][index];
	}

	void swap(int x, int y, T* ptr)
	{
		if ((x < this->SIZE) && (y < this->SIZE))
		{
			T tmp;
			tmp = ptr[x];
			ptr[x] = ptr[y];
			ptr[y] = tmp;
			T* ptrtmp = new T[this->SIZE];

			for (int i = 0; i < this->SIZE; i++)
			{
				ptrtmp[i] = this->ptrVector[x][i];
				this->ptrVector[x][i] = this->ptrVector[y][i];
				this->ptrVector[y][i] = ptrtmp[i];
			}
			delete[]ptrtmp;
		}
		else
		{
			cout << "Error!";
			exit(0);
		}
	}

	Vector <T> Gauss(T* ptr)
	{
	
		for (int j = 0; j < this->SIZE; j++)
		{
			int i = 0;
			int indexMax = i + j;
			T max = Mod<T>(this->ptrVector[i + j][j]);
			for (i + j + 1; i + j + 1 < this->SIZE; i++);
			{
				if (Mod<T>(this->ptrVector[i + j][j]) > max)
				{
					indexMax = i + j;
				}
			}
			swap(j, indexMax, ptr);
			for (int n = j + 1; n < this->SIZE; n++)
			{
				if (this->ptrVector[j][j] != 0)
				{
					for (int k = j; k < this->SIZE; k++)
					{
						this->ptrVector[n][k] += this->ptrVector[j][k] * (-(this->ptrVector[n][j] / this->ptrVector[j][j]));
					}
					ptr[n] += ptr[j] * (-(this->ptrVector[n][j] / this->ptrVector[j][j]));
				}
				else
				{
					cout << "Error! Division by zero!" << endl;
					exit(3);
				}
			}
		}

		for (int i = 0; i < this->SIZE; i++)
		{
			T sum = 0;
			for (int j = 0; j < this->SIZE; j++)
			{
				sum += Mod<T>(this->ptrVector[i][j]);
			}
			
			if ((sum == 0) && (ptr[i] == 0))
			{
				cout << "No solution!" << endl;
				exit(3);
			}

			if ((sum == 0) && (ptr[i] != 0))
			{
				cout << "No solution!" << endl;
				exit(2);
			}
		}

		T* result = new T[this->SIZE];
		for (int i = this->SIZE - 1; i >= 0; i--)
		{
			T tmp = 0;
			for (int j = i + 1; j < this->SIZE; j++)
			{
				tmp += this->ptrVector[i][j] * result[j];
			}
			result[i] = (ptr[i] - tmp) / this->ptrVector[i][i];
		}
		return Vector<T>(this->SIZE, result);
		
	}
	
	void Check(T* ptr)
	{
		T* Check = new T[this->SIZE];
		
		cout << "\nValues to Check: " << endl;
		for (int i = 0; i < this->SIZE; i++)
		{
			for (int j = 0; j < this->SIZE; j++)
			{
				Check[i] += this->ptrVector[i][j] * ptr[j];
			}
			cout << ptr[this->SIZE-i-1] << "\t";
		}
		cout << endl << endl;
		delete[]Check;
	}

};
