#pragma once

using namespace std;

template <typename T>
class My_vector
{
public:
	My_vector()
	{
		m_x = new T[1];
		size = 1;
	}

	My_vector(int _size, T _value = T())
	{
		size = _size;
		m_x = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			m_x[i] = _value;
		}
	}

	My_vector(int _size, T* values)
	{
		size = _size;
		m_x = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			m_x[i] = values[i];
		}
	}

	My_vector(const My_vector& v)
	{
		delete[]this->m_x;
		this->size = v.size;
		this->m_x = new T[v.size];
		for (int i = 0; i < v.size; i++)
		{
			this->m_x[i] = v.m_x[i];
		}
		return *this;
	}

	T& operator[](int i)
	{
		return m_x[i];
	}

	My_vector& operator=(const My_vector& v)
	{
		delete[]this->m_x;
		this->size = v.size;
		this->m_x = new T[v.size];
		for (int i = 0; i < v.size; i++)
		{
			this->m_x[i] = v.m_x[i];
		}
		return *this;
	}

	void print()
	{
		cout << "(";
		for (int i = 0; i < size - 1; i++)
		{
			cout << m_x[i] << "\t";
		}
		cout << m_x[size - 1] << ")";
	}

	~My_vector()
	{
		delete[]m_x;
	}

private:
protected:
	T* m_x;
	int size;
};