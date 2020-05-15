#pragma once

#include "iostream"

#include "Square_matrix.h"
#include "Func_massive_for_creating_vector.h"
#include "Vector.h"


template <class T>
class Linear_equation_system : public Matrix<T>
{
public:
	Linear_equation_system(int _nsize) : Matrix<T>(_nsize), v(_nsize)
	{
		this->nsize = _nsize;
		T* a = new T[_nsize];
		create_random_massive(_nsize, a);
		Vector<T> _v(_nsize, a);
		v = _v;
		delete[]a;
	}

	void method_Gauss()
	{

		for (int i = 0; i < this->nsize; i++)
		{
			T max = this->m[i][i];
			int _j = i;

			for (int j = i + 1; j < this->nsize; j++)
			{
				if (this->m[j][i] > max)
				{
					max = this->m[j][i];
					_j = j;
				}
			}

			Vector<T> _tmpm(this->nsize);
			T _tmpl;
			_tmpm = this->m[i];
			_tmpl = this->v[i];
			this->m[i] = this->m[_j];
			this->v[i] = this->v[_j];
			this->m[_j] = _tmpm;
			this->v[_j] = _tmpl;

			this->v[i] = this->v[i] / this->m[i][i];
			T tmp = this->m[i][i];
			for (int k = 0; k < this->nsize; k++)
			{
				this->m[i][k] = this->m[i][k] / tmp;
			}
		
			for (int z = i + 1; z < this->nsize; z++)
			{
				T tmp = this->m[z][i];
				this->v[z] = this->v[z] - this->v[i] * tmp;
				for (int c = 0; c < this->nsize; c++)
				{
					this->m[z][c] = this->m[z][c] - this->m[i][c] * tmp;
				}
			}
		}

		for (int z = this->nsize - 1; z > 0; z--)
		{
			for (int k = 0; (k < this->nsize - 1) && (k != z); k++)
			{
				this->v[k] = this->v[k] - this->v[z] * this->m[k][z];
				this->m[k][z] = this->m[k][z] - this->m[k][z] * this->m[z][z];
			}
		}
			
	
	}

	void print_linear_equation_system()
	{
		std::cout << "linear equation system: "<< std::endl;
		for (int i = 0; i < this->nsize; i++)
		{
			Vector<T> tmp1(this->nsize);
			tmp1 = this->m[i];
			tmp1.print_coord();
			std::cout << "\t|" << this->v[i];
			std::cout << std::endl;
		}
	}
private:
	Vector<T> v;
};