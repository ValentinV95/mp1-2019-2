#pragma once

template <typename T>
class Vector {
public:
	Vector() {
		size = 2;
		m_x = new T[size];
	}
	Vector(int _size, T _value = T()) {
		size = _size;
		m_x = new T[_size];
		for (int i = 0; i < _size; i++) {
			m_x[i] = _value;
		}
	}
	Vector(const Vector& other) {
		delete[]this->m_x;
		this->size = other.size;
		this->m_x = new T[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->m_x[i] = other.m_x[i];
		}
		return *this;
	}
	~Vector()
	{
		delete[]m_x;
	}

	int Get_Size() {return size;}

	T& operator[](int i) {
		return m_x[i];
	}

	Vector& operator=(const Vector& other) {
		delete[]this->m_x;
		this->size = other.size;
		this->m_x = new T[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->m_x[i] = other.m_x[i];
		}
		return *this;
	}


protected:
	T* m_x;
	int size;
};