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
private:
	T* rv; //right_values
};

