#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector
{
protected:
	T* pVector;
	int isize;
public:
	Vector()
	{
		isize = 1;
		pVector = new T[isize];
		for (int i = 0; i < isize; i++)
		{
			pVector[i] = 0;
		}
	}
	Vector(int _size, T val = T())
	{
		isize = _size;
		pVector = new T[isize];
		for (int i = 0; i < isize; i++)
		{
			pVector[i] = val;
		}
	}
	Vector(int _size, T* val)
	{
		isize = _size;
		pVector = new T[isize];
		for (int i = 0; i < isize; i++)
		{
			pVector[i] = val[i];
		}
	}
	Vector(const Vector& other) {
		delete[]this->pVector;
		this->isize = other.isize;
		this->pVector = new T[other.isize];
		for (int i = 0; i < other.isize; i++)
		{
			this->pVector[i] = other.pVector[i];
		}
		return *this;
	}

	~Vector()
	{
		delete[] pVector;
	}
	Vector& operator = (const Vector& other) {
		delete[]this->pVector;
		this->pVector = new T[other.isize];
		for (int i = 0; i < other.isize; i++) {
			this->pVector[i] = other.pVector[i];
		}
		return *this;
	}
	T& operator[](int i)
	{
		return pVector[i];
	}
	void printV() const
	{
		for (int i = 0; i < isize; i++)
			cout << pVector[i] << "\n";
	}
};
template <typename T>
class MATRIX : public Vector <Vector <T> > {
public:
	MATRIX(int n) : Vector<Vector <T>>(n, Vector <T>(n)) {}

	void printm() {
		for (int i = 0; i < this->isize; i++) {
			for (int j = 0; j < this->isize; j++) {
				cout << this->pVector[i][j] << '\t';
			}
			cout << endl;
		}
		cout << endl;
	}
private:
};
template <typename T>
T abs(T a) {
	if (a < 0)
	{
		return -a;
	}
	else
	{
		return a;
	}
}
template <typename T>
class slau : public MATRIX <T>
{
private:
	T* p;
public:
	slau(int n, T _p = T()) : MATRIX<T>(n)
	{
		p = new T[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = _p;
		}
	}
	~slau()
	{
		delete[]p;
	}
	void RandM()
	{
		for (int i = 0; i < this->isize; i++)
		{
			for (int j = 0; j < this->isize; j++)
			{
				this->pVector[i][j] = rand() % 10;
			}
		}
	}
	void printM() {
		for (int i = 0; i < this->isize; i++)
		{
			for (int j = 0; j < this->isize; j++)
			{
				cout << this->pVector[i][j] << '\t';
			}
			cout << " | " << p[i];
			cout << endl;
		}
		cout << endl;
	}
	void minus(int mr, int sr, T* p, int index)
	{
		T pIndex = this->pVector[sr][index];
		for (int i = 0; i + index < this->isize; i++)
		{
			this->pVector[sr][i + index] -= this->pVector[mr][i + index] * pIndex / this->pVector[mr][index];
		}
		p[sr] -= p[mr] * pIndex / this->pVector[mr][index];
	}
	void swaps(int a1, int a2, T* p)
	{
		if ((a1 < this->isize) && (a2 < this->isize))
		{
			T tmp;
			tmp = p[a1];
			p[a1] = p[a2];
			p[a2] = tmp;
			T* ptmp = new T[this->isize];
			for (int i = 0; i < this->isize; i++)
			{
				ptmp[i] = this->pVector[a1][i];
				this->pVector[a1][i] = this->pVector[a2][i];
				this->pVector[a2][i] = ptmp[i];
			}
			delete[]ptmp;
		}
		else
		{
			cout << "ERROR";
			exit(0);
		}
	}
	Vector <T> gauss()
	{
		printM();
		slau<double> cop(this->isize);
		for (int i = 0; i < this->isize; i++) {
			for (int j = 0; j < this->isize; j++) {
				cop[j][i] = this->pVector[j][i];
			}
		}
		for (int i = 0; i < this->isize; i++)
		{
			int k = 0;
			for (int j = 0; j < this->isize; j++)
			{
				if (this->pVector[i][j] == 0)
				{
					k++;
				}
				else
				{
					break;
				}
			}
			if (k == this->isize)
			{
				if (p[i] == 0)
				{
					cout << "ERROR 0*0 = 0" << endl;
					exit(0);
				}
				else if (p[i] != 0)
				{
					cout << "ERROR 0*x = B, B != 0" << endl;
					exit(0);
				}
			}
		}
		int index = 0;
		for (int j = 0; j < this->isize; j++)
		{
			T max = 0;
			int sMax = 0;
			for (int i = 0; i + j < this->isize; i++)
			{
				if (max <= abs(this->pVector[i + j][j]))
				{
					max = abs(this->pVector[i + j][j]);
					sMax = i + j;
				}
			}
			if (max == 0)
			{
				cout << "ERROR" << endl;
				exit(0);
			}
			swaps(sMax, j, p);
			for (int i = 1; i + j < this->isize; i++)
			{
				minus(j, i + j, p, index);
			}
			index++;
		}
		printM();
		T* sl = new T[this->isize];
		for (int i = this->isize - 1; i >= 0; i--)
		{
			T tmp = 0;
			for (int j = i + 1; j < this->isize; j++)
			{
				tmp += this->pVector[i][j] * sl[j];
			}
			sl[i] = (p[i] - tmp) / this->pVector[i][i];
		}
		for (int i = 0; i < this->isize; i++) {
			for (int j = 0; j < this->isize; j++) {
				this->pVector[j][i] = cop[j][i];
			}
		}
		cout << "Resultat: " << endl;
		Vector<T>(this->isize, sl).printV();
		return Vector<T>(this->isize, sl);
	}
};