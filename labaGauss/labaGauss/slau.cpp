#include "slau.h"

void slau::print()
{
	std::cout << std::endl;
	for (int y = 0; y < this->sizeY(); y++)
	{
		for (int x = 0; x < this->sizeX(); x++)
		{
			std::cout << this->operator[](matrix_index(x, y)) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

