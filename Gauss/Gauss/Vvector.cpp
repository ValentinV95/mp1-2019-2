#include "Vvector.h"
#include <iostream>

void Vvector<int>::print()
{
	for (int i = 0; i < size; i++)
		std::cout << vec[i] << " ";
}

void Vvector<double>::print()
{
	for (int i = 0; i < size; i++)
		std::cout << vec[i] << " ";
}

void Vvector<float>::print()
{
	for (int i = 0; i < size; i++)
		std::cout << vec[i] << " ";
}

template <typename T>
void Vvector<T>::sum(Vvector v, int size)
{
	if (size = this->size)
	{
		for (int i = 0; i < size; i++)
			vec[i] = vec[i] + v[i];
    }
	else
		std::cout << "ERORRE";

}

