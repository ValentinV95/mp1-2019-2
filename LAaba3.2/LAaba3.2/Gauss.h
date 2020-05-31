#pragma once
using namespace std;

template <typename T>
class Gauss : public Matrix<T>
{

private:

	T* el;

public:

	Gauss(int n, T _el = T()) : Matrix <T>(n)
	{
		el = new T[n];
		for (int i = 0; i < this->size; i++)
		{
			el[i] = _el;
		}
	}

	~Gauss()
	{
		delete[]el;
	}

	void s_print(T *el)
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				cout << this->mas[i][j] << "\t";
			}
			cout << "| " << el[i] << endl;
		}
		cout << endl;
	}

	void InputMat()
	{
		cout << "To enter items manually press 1 \nIn order to generate random numbers press 2 \n";
		int mode = 1;
		cin >> mode;
		double min = 1, max = 20;
		switch (mode) {
		case 1:
			for (int i = 0; i < this->size; i++)
			{
				for (int j = 0; j < this->size; j++)
				{
					cout << "Input [" << i << "]" << "[" << j << "] element:" << endl;
					cin >> this->mas[i][j];
				}
			}
			break;
		case 2:
			for (int i = 0; i < this->size; i++)
			{
				for (int j = 0; j < this->size; j++)
				{
					this->mas[i][j] = (double)rand() / (double)RAND_MAX * (max - min) + min;
				}
			}
			break;
		default:
			cout << "you have chosen the wrong value, the matrix is filled with random values";

			for (int i = 0; i < this->size; i++)
			{
				for (int j = 0; j < this->size; j++)
				{
					this->mas[i][j] = (double)rand() / (double)RAND_MAX * (max - min) + min;
				}
			}
			break;
		}
	}

	void swap(int str1, int str2, T *el)
	{
		T _tmp;
		_tmp = el[str1];
		el[str1] = el[str2];
		el[str2] = _tmp;
	}

	Vector <T> gauss(T *el)
	{
		T prec = 0.001;
		for (int j = 0; j < this->size; j++)
		{
			int i = 0;
			int max_abs_index = i + j;
			T max_abs = abs(this->mas[i + j][j]);
			for (i + j + 1; i + j + 1 < this->size; i++)
			{
				if (abs(this->mas[i + j][j]) > max_abs)
				{
					max_abs_index = i + j;
				}
			}
			swap(j, max_abs_index, el);
			for (int l = j + 1; l < this->size; l++)
			{
				if (this->mas[j][j] != 0)
				{
					T rate = -(this->mas[l][j] / this->mas[j][j]);
					for (int k = j; k < this->size; k++)
					{
						this->mas[l][k] += this->mas[j][k] * rate;
					}
					el[l] += el[j] * rate;
				}
				else
				{
					cout << "Error: division by 0" << endl;
					exit(1);
				}
			}
		}

		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (abs(this->mas[i][j]) < prec)
				{
					this->mas[i][j] = 0;
				}
			}
			if (abs(el[i]) < prec)
			{
				el[i] = 0;
			}
		}

		for (int i = 0; i < this->size; i++)
		{
			T sum = 0;
			for (int j = 0; j < this->size; j++)
			{
				sum += abs(this->mas[i][j]);
			}
			if ((sum == 0) && (el[i] != 0))
			{
				cout << "No solutions" << endl;
				exit(2);
			}
			if ((sum == 0) && (el[i] == 0))
			{
				cout << "Can't solve: the equation depends on the variable" << endl;
				exit(3);

			}
		}

		T* sol = new T[this->size];
		for (int i = this->size - 1; i >= 0; i--)
		{
			T tmp = 0;
			for (int j = i + 1; j < this->size; j++)
			{
				tmp += this->mas[i][j] * sol[j];
			}
			sol[i] = (el[i] - tmp) / this->mas[i][i];
		}
		return Vector<T>(this->size, sol);
	}

	void Verification(T *el)
	{
		T* Ver = new T[this->size];

		cout << "\nChecking values: " << "\n" <<endl;
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				Ver[i] += this->mas[i][j] * el[j];
			}
			cout << el[this->size - i - 1] << "\n" << endl;;
		}
		delete[]Ver;
	}

};