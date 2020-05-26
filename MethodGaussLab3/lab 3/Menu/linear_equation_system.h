#pragma once

#include "iostream"

#include "Square_matrix.h"
#include "Vector.h"


template <class T>
class Linear_equation_system : public Matrix<T>
{
public:
	Linear_equation_system(int _nsize, Matrix<T> _m) : Matrix<T>(_nsize, _m)
	{
		
	}
	

	void method_Gauss(Vector<T>& v_r)
	{
		Vector<Vector<T>> tmp_m = *this;

		for (int i = 0; i < this->size; i++)
		{
			T max = tmp_m[i][i];
			int _j = i;

			for (int j = i + 1; j < this->size; j++)
			{
				if (tmp_m[i][j] > max)
				{
					max = tmp_m[j][i];
					_j = j;
				}
			}

			Vector<T> _tmpm(this->size);
			T _tmpl;
			_tmpm = tmp_m[i];
			_tmpl = v_r[i];
			tmp_m[i] = tmp_m[_j];
			v_r[i] = v_r[_j];
			tmp_m[_j] = _tmpm;
			v_r[_j] = _tmpl;

			v_r[i] = v_r[i] / tmp_m[i][i];
			T tmp = tmp_m[i][i];
			for (int k = 0; k < this->size; k++)
			{
				tmp_m[i][k] = tmp_m[i][k] / tmp;
			}

			for (int z = i + 1; z < this->size; z++)
			{
				T tmp = tmp_m[z][i];
				v_r[z] = v_r[z] - v_r[i] * tmp;
				for (int c = 0; c < this->size; c++)
				{
					tmp_m[z][c] = tmp_m[z][c] - tmp_m[i][c] * tmp;
				}
			}
		}

		for (int z = this->size - 1; z > 0; z--)
		{
			for (int k = 0; (k < this->size - 1) && (k != z); k++)
			{
				v_r[k] = v_r[k] - v_r[z] * tmp_m[k][z];
				tmp_m[k][z] = tmp_m[k][z] - tmp_m[k][z] * tmp_m[z][z];
			}
		}

		std::cout << "linear equation system: " << std::endl;
		for (int i = 0; i < this->size; i++)
		{
			Vector<T> tmp1(this->size);
			tmp1 = tmp_m[i];
			for (int j = 0; j < this->size; j++)
			{
				std::cout << tmp1[j] << "\t";
			}
			std::cout << "\t|" << v_r[i];
			std::cout << std::endl;
		}
	}

	void Check(Vector<T>& _v)
	{
		Vector<T> check_v(this->size);

		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				check_v[i] += this->v[i][j] * _v[j];
			}
		}


		std::cout << std::endl << "Base right vector: ";
		check_v.print_coord();
	}

	

private:
};
