#pragma once
using namespace std;

template <typename T>
class Vector
{
public:
	Vector() 
	{
		size = 1;
		mas = new T[size];
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

	Vector(int _size, T _value = T()) 
	{
		size = _size;
		mas = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			mas[i] = _value;
		}
	}

	Vector(int _size, T* _values) 
	{
		size = _size;
		mas = new T[size];
		for (int i = 0; i < size; i++)
		{
			mas[i] = _values[i];
		}
	}

	Vector(const Vector& other)  
	{
		this->size = other.size;
		this->mas = new T[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->mas[i] = other.mas[i];
		}
	}

	~Vector() 
	{
		delete[]mas;
	}

	void v_print() 
	{
		cout << "{";
		for (int i = 0; i < size - 1; i++)
		{
			cout << mas[i] << ";";
		}
		cout << mas[size - 1] << "}";
	}

	T& operator[](int i) 
	{
		return mas[i];
	}

	Vector& operator = (const Vector& vec_other)
	{
		if (this->mas != vec_other.mas)
		{
			delete[]this->mas;
			this->size = vec_other.size;
			this->mas = new T[vec_other.size];
			for (int i = 0; i < vec_other.size; i++)
			{
				this->mas[i] = vec_other.mas[i];
			}
		}
		return *this;
	}
	Vector<T> operator+ (const Vector<T>& rhs)
	{
		Vector<T> temp(rhs.size);

		for (int i = 0; i < size; i++)
		{
			temp[i] = this->mas[i] + rhs.mas[i];
		}

		return temp;
	}
	Vector<T> operator- (const Vector<T>& rhs)
	{
		Vector<T> temp(rhs.size);

		for (int i = 0; i < size; i++)
		{
			temp[i] = this->mas[i] - rhs.mas[i];
		}

		return temp;
	}

protected:
	T* mas;
	int size;

private:

};