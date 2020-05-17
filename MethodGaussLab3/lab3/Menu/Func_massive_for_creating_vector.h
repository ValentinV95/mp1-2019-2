#pragma once

#include "iostream"

template <typename T>
T* create_random_massive(int size, T* a)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = double((rand() % 90 + 10));
	}

	return a;
}

template <typename T>
void create_null_massive(int size, T* a)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = 0;
	}
}

template <typename T>
void print_massive(int size, T* a)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << "    ";
	}


	std::cout << std::endl;
}
