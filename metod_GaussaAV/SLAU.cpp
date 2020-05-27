#include "SLAU.h"

void SLAU::matrix_print()
{
	std::cout << std::endl;
	for (int y = 0; y < this->sizeY(); y++)
	{
		for (int x = 0; x < this->sizeX(); x++)
		{
			std::cout << this->operator[](element(x, y)) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void SLAU::revert(int arr1_index, int arr2_index, vvector<double> ex)
{
	vvector<double> arr1 = this->arr[arr1_index];
	vvector<double> arr2 = this->arr[arr2_index];
	int index = 0;
	int length = arr1.size;
	double value = 0;
	for (int i = 0; i < length; i++)
	{
		index = i;
		if (arr1[i] == 0) continue;
		value = arr2[i] / arr1[i];
		break;
	}
	for (int i = 0; i < length; i++) arr2[i] = round(arr2[i] - arr1[i] * value, 100);
	ex[arr2_index] = ex[arr2_index] - ex[arr1_index] * value;
}
void SLAU::habr(vvector<double> ex)
{
	int count = size;
	for (int i = 1; i < count; i++)
	{
		int k = i;
		for (int j = i - 1; j >= 0; j--)
			if (zero_in_start(this->arr[k]) < zero_in_start(this->arr[j]))
			{
				swap(&this->arr[k], &this->arr[j]);
				swap(&ex[k], &ex[j]);
				k--;
			}
			else
				break;
	}
	count = size;
}