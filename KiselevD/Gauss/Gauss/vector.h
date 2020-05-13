#pragma once

/*template<typename T>
T* Vptr(int _size) {
	T* values = new T[_size];
	for (int i = 0; i < _size; i++)
	{
		T value;
		cout << "Input " << i << " value of vector\n";
		cin >> value;
		values[i] = value;
	}
	return values;
}*/

template <typename T>
class Vector {
public:
	Vector() {
		m_x = new T[2];
	}
	Vector(int _size, T _value = T()) {
		size = _size;
		m_x = new T[_size];
		for (int i = 0; i < _size; i++) {
			m_x[i] = _value;
		}
	}
	~Vector()
	{
		delete[]m_x;
	}
	T& operator[](int i) {
		return m_x[i];
	}
	Vector& operator=(const Vector& other) {
		delete[]this->m_x;
		this->m_x = new T[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->m_x[i] = other.m_x[i];
		}
		return *this;
	}


private:
	T* m_x;
	int size;
};