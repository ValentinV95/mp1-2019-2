#pragma once
using namespace std;

template <typename T>
class My_vector
{
public:
	My_vector() // ����������� �� ���������
	{
		size = 2;
		mas = new T[size];
	}

	My_vector(int _size, T _value = T()) // ������� �����������
	{
		size = _size;
		mas = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			mas[i] = _value;
		}
	}

	My_vector(int _size, T* _values) // �����������
	{
		size = _size;
		mas = new T[size];
		for (int i = 0; i < size; i++)
		{
			mas[i] = _values[i];
		}
	}

	My_vector(const My_vector& other)  // ����������� �����������
	{
		this->size = other.size;
		this->mas = new T[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->mas[i] = other.mas[i];
		}
	}

	~My_vector() // ���������� 
	{
		delete[]mas;
	}

	int GetSize() // �������� ������ �������
	{
		return size;
	}

	T& operator[](int i) // ���������� ���������[]
	{
		return mas[i];
	}

	My_vector& operator = (const My_vector& vec_other)
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

protected:
	T* mas;
	int size;

private:

};
