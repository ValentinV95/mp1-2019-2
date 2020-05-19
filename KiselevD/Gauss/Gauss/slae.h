#pragma once

template < typename T >
class SLAE : public Matrix<T>
{
public:
	SLAE(int n, T _rv = T()) : Matrix <T>(n) {
		rv = new T[n];
		for (int i = 0; i < n; i++)
		{
			rv[i] = _rv;
		}
	}
	~SLAE() {
		delete[]rv;
	}
	void fill() {
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				cout << "Input [" << i << "]" << "[" << j << "] element:" << endl;
				cin >> this->m_x[i][j];
			}
		}
		for (int i = 0; i < this->size; i++)
		{
			cout << "Input " << i << " right value" << endl;
			cin >> rv[i];
		}
	}
	void s_print() {
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
	void swap(int str1, int str2) {
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
			cout << "Wrong string!";
			exit(1);
		}
	}
	Vector <T> gauss() {
		T error = 0.0000001; 
		//making it look triangular
		for (int j = 0; j < this->size; j++)
		{
			int i = 0;
			int max_abs_index = i + j;
			T max_abs = abs<T>(this->m_x[i + j][j]);
			for (i + j + 1; i + j + 1 < this->size; i++);
			{
				if (abs<T>(this->m_x[i+j][j]) > max_abs)
				{
					max_abs_index = i+j;
				}
			}
			swap(j, max_abs_index);
			for (int l = j + 1; l < this->size; l++)
			{
				if (this->m_x[j][j] != 0)
				{
					T rate = -(this->m_x[l][j] / this->m_x[j][j]);
					for (int k = j; k < this->size; k++)
					{
						this->m_x[l][k] += this->m_x[j][k] * rate;
					}
					rv[l] += rv[j] * rate;
				}
				else
				{
					cout << "Division by 0 when searching rate!" << endl;
					exit(3);
				}
			}
		}
		//removing the error
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (abs(this->m_x[i][j]) < error)
				{
					this->m_x[i][j] = 0;
				}
			}
			if (abs(rv[i]) < error)
			{
				rv[i] = 0;
			}
		}
		//checking for missing solutions
		for (int i = 0; i < this->size; i++)
		{
			T sum = 0;
			for (int j = 0; j < this->size; j++)
			{
				sum += abs<T>(this->m_x[i][j]);
			}
			if ((sum == 0) && (rv[i] != 0))
			{
				cout << "No solution: 0 * x = C, C!=0" << endl;
				exit(2);
			}
			if ((sum == 0) && (rv[i] == 0))
			{
				cout << "Cant solve: the equation depends on the variable" << endl;
				exit(3);
			}
		}
		//find solutions
		T* sol = new T[this->size];
		for (int i = this->size - 1; i >= 0; i--) {
			T tmp = 0;
			for (int j = i + 1; j < this->size; j++) {
				tmp += this->m_x[i][j] * sol[j];
			}
			sol[i] = (rv[i] - tmp) / this->m_x[i][i];
		}
		return Vector<T>(this->size, sol);
	}
private:
	T* rv; //right_values
};

