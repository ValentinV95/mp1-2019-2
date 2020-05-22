#pragma once
using namespace std;

template <typename T>
class SLAE : public My_matrix<T>
{

public:

	SLAE(int n, T _fm = T()) : My_matrix <T>(n)
	{
		fm = new T[n];
		for (int i = 0; i < this->size; i++)
		{
			fm[i] = _fm;
		}
	}

	~SLAE()
	{
		delete[]fm;
	}

	void s_print()
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				cout << this->mas[i][j] << "\t";
			}
			cout << "| " << fm[i] << endl;
		}
		cout << endl;
	}

	void InputMat()
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				cout << "Input [" << i << "]" << "[" << j << "] element:" << endl;
				cin >> this->mas[i][j];
			}
		}
		for (int i = 0; i < this->size; i++)
		{
			cout << "Input " << " free member" << endl;
			cin >> fm[i];
		}

	}

	void RandMat_double() // для отладки и проверки ввода матрицы
	{
		double min, max;
		min = 1;
		max = 50;

		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				this->mas[i][j] = (double)rand() / (double)RAND_MAX * (max - min) + min;
			}
		}
		for (int i = 0; i < this->size; i++)
		{
			fm[i] = (double)rand() / (double)RAND_MAX * (max - min) + min;
		}

	}

	void swap(int str1, int str2)
	{
		if ((str1 < this->size) && (str2 < this->size) && (str1 >= 0) && (str2 >= 0)) 
		{
			//Поменяем местами свободные члены
			T r_tmp;
			r_tmp = fm[str1];
			fm[str1] = fm[str2];
			fm[str2] = r_tmp;

			//Поменяем местами строки в матрице
			T* tmp = new T[this->size];
			for (int i = 0; i < this->size; i++)
			{
				tmp[i] = this->mas[str1][i];
				this->mas[str1][i] = this->mas[str2][i];
				this->mas[str2][i] = tmp[i];
			}
			delete[]tmp;
		}
		else
		{
			cout << "Error number of string!";
			exit(1); //выход с ошибкой
		}
	}


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

	My_vector <T> gauss()
	{
		T error = 0.0000001;
		// Приведение к треугольному виду
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
			swap(j, max_abs_index);
			for (int l = j + 1; l < this->size; l++)
			{
				if (this->mas[j][j] != 0)
				{
					T rate = -(this->mas[l][j] / this->mas[j][j]);
					for (int k = j; k < this->size; k++)
					{
						this->mas[l][k] += this->mas[j][k] * rate;
					}
					fm[l] += fm[j] * rate;
				}
				else
				{
					cout << "Division by 0 when searching rate!" << endl;
					exit(3);
				}
			}
		}
		// удаление ошибки
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (abs(this->mas[i][j]) < error)
				{
					this->mas[i][j] = 0;
				}
			}
			if (abs(fm[i]) < error)
			{
				fm[i] = 0;
			}
		}
		// Проверка недостающих решений
		for (int i = 0; i < this->size; i++)
		{
			T sum = 0;
			for (int j = 0; j < this->size; j++)
			{
				sum += abs(this->mas[i][j]);
			}
			if ((sum == 0) && (fm[i] != 0))
			{
				cout << "No solutions: 0 * x = c, c != 0;" << endl;
				exit(2);
			}
			if ((sum == 0) && (fm[i] == 0))
			{
				cout << "Can't solve: the equation depends on the variable" << endl;
				exit(3);
			}
		}
		// Находим решения
		T* sol = new T[this->size];
		for (int i = this->size - 1; i >= 0; i--)
		{
			T tmp = 0;
			for (int j = i + 1; j < this->size; j++)
			{
				tmp += this->mas[i][j] * sol[j];
			}
			sol[i] = (fm[i] - tmp) / this->mas[i][i];
		}
		return My_vector<T>(this->size, sol);
	}

private:

	T* fm; //свободные члены 

};