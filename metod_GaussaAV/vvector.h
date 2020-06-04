#pragma once
struct element // структура, которая возвращает конкретный элемент матрицы
{
	int x;
	int y;
	element(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
template<typename T> static void swap(T* a, T* b) // поменять местами
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}
template<typename T> class vvector //класс вектор
{
public:
	vvector() : vvector(0) { }
	vvector(int size) : vvector(new T[size], size) { }
	vvector(int size, T obj) : vvector(size)
	{
		for (int i = 0; i < size; i++)
			arr[i] = obj;
	}
	vvector(T* arr, int size)
	{
		this->arr = arr;
		this->size = size;
	}
	T& operator +(vvector a)
	{
		for (int i = 0; i < size; i++)
			arr[i] += a[i];
	}
	T& operator -(vvector a)
	{
		for (int i = 0; i < size; i++)
			arr[i] -= a[i];
	}
	T& operator *(int a)
	{
		for (int i = 0; i < size; i++)
			arr[i] = arr[i] * a;
	}
	T& operator[](int index)
	{
		return arr[index];
	}
	int size;
protected:
	T* arr;
};