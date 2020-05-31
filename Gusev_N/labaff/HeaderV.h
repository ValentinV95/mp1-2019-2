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

	void print()
	{
		cout << "\n" << "{";
		for (int i = 0; i < size - 1; i++)
		{
			cout << mas[i] << ";";
		}
		cout << mas[size - 1] << "}" << "\n";
	}

	T& operator[](int i)
	{
		return mas[i];
	}
	
	Vector<T> operator- (const Vector<T>& WW)
	{
		Vector<T> temp(WW.size);
		for (int i = 0; i < size; i++)
		{
			temp[i] = this->mas[i] - WW.mas[i];
		}
		return temp;
	}
	
	Vector<T> operator+ (const Vector<T>& WW)
	{
		Vector<T> temp(WW.size);
		for (int i = 0; i < size; i++)
		{
			temp[i] = this->mas[i] + WW.mas[i];
		}
		return temp;
	}
	
	Vector& operator = (const Vector& Vector2)
	{
		if (this->mas != Vector2.mas)
		{
			delete[]this->mas;
			this->size = Vector2.size;
			this->mas = new T[Vector2.size];
			for (int i = 0; i < Vector2.size; i++)
			{
				this->mas[i] = Vector2.mas[i];
			}
		}
		return *this;
	}
	


protected:
	T* mas;
	int size;
private:

};
