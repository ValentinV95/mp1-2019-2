#pragma once

using namespace std;

template <typename T>
class Vector
{
public:
	Vector()
	{
		SIZE = 1;
		ptrVector = new T[SIZE];

		for (int i = 0; i < SIZE; i++)
		{
			ptrVector[i] = 0;
		}
	}

	Vector(int _SIZE, T* value)
	{
		SIZE = _SIZE;
		ptrVector = new T[_SIZE];

		for (int i = 0; i < _SIZE; i++)
		{
			ptrVector[i] = value[i];
		}
	}

	Vector(int _SIZE, T value = T())
	{
		SIZE = _SIZE;
		ptrVector = new T[_SIZE];

		for (int i = 0; i < _SIZE; i++)
		{
			ptrVector[i] = value;
		}
	}

	Vector(const Vector& other)
	{
		delete[]this->ptrVector;
		this->SIZE = other.SIZE;
		this->ptrVector = new T[other.SIZE];

		for (int i = 0; i < other.SIZE; i++)
		{
			this->ptrVector[i] = other.ptrVector[i];
		}
		return *this;
	}

	~Vector()
	{
		delete[] ptrVector;
	}

	T& operator[](int i)
	{
		return ptrVector[i];
	}

	Vector& operator = (const Vector& other)
	{
		delete[]this->ptrVector;
		this->SIZE = other.SIZE;
		this->ptrVector = new T[other.SIZE];

		for (int i = 0; i < other.SIZE; i++)
		{
			this->ptrVector[i] = other.ptrVector[i];
		}
		return *this;
	}

	void printVector() const
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << ptrVector[i] << "\n";
		}
	}

protected:
	T* ptrVector;
	int SIZE;
};

