#pragma once

//class MyVector {
//
//};

template < typename T >
class MyVector {
public: 
	MyVector() {
		m_x = new T[1];
	}

	MyVector(int size, T value = T()) {
		m_x = new T[size];
		for (int i = 0; i < size; i++) {
			m_x[i] = value;
		}
	}

	MyVector operator = (const T other) {
		delete[]this->m_x;
		this->m_x = new T[other.size];
		for (int i = 0; i < other.size; i++) {
			this->m_x[i] = other.m_x[i];
		}
		return *this;
	}

private:
	T* m_x;
};


template <typename T>
class Matrix : public MyVector<MyVector <T> > {
public:
	Matrix(int n): MyVector<MyVector <T>>(n, MyVector <T> (n)) {}

private:
	int n;
};