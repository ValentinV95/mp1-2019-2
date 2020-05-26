#pragma once

template < class T >
class Vector 
{
public:
	Vector() 
	{
		v = new T[10];
		size = 10;
	}

	Vector(int _size, T value = T()) 
	{
		size = _size;
		v = new T[size];

		for (int i = 0; i < size; i++) 
		{
			v[i] = value;
		}
	}

	Vector (int _size, T* value)
	{
		size = _size;
		v = new T[_size];

		for (int i = 0; i < _size; i++)
		{
			v[i] = value[i];
		}
	}

	Vector (const Vector<T>& rhs)
	{
		

		this->size = rhs.size;
		this->v = new T[rhs.size];

		for (int i = 0; i < rhs.size; i++)
		{
			this->v[i] = rhs.v[i];
		}
	}

	void fill_v()
	{
		std::cout << "fill vector" << std::endl;

		for (int i = 0; i < this->size; i++)
		{
			std::cin >> this->v[i];
		}
	}

	void print_coord()
	{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << this->v[i] << ' ';
		}

		std::cout << std::endl;
	}

	Vector& operator= (const Vector& rhs)
	{
		delete[]this->v;

		this->v = new T[rhs.size];

		for (int i = 0; i < rhs.size; i++) 
		{
			this->v[i] = rhs.v[i];
		}

		return *this;
	}

	T& operator[](int index)
	{
		return v[index];
	}

	int getSize() 
	{
		return size;
	}

	~Vector() 
	{
		delete[]v;
	}

protected:
	T* v;
	int size;
};