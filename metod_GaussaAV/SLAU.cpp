#include "SLAU.h"

void SLAU::matrix_print() //функция печати матрицы
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