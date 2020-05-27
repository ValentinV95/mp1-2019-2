#include "SLAU.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int dim_1;
	int dim_2;
	std::cout << "Введите размер матрицы" << std::endl;
	std::cout << "dim_1 ";
	std::cin >> dim_1;
	std::cout << "dim_2 ";
	std::cin >> dim_2;
	SLAU matriza = SLAU(dim_1, dim_2);
	for (int y = 0; y < dim_2; y++)
	{
		std::cout << "Введите коэффициенты перед неизвестными уравнения " << y + 1 << std::endl;
		for (int x = 0; x < dim_1; x++)
		{
			//std::cout << "[" << x << "," << y << "] ";
			std::cin >> matriza[element(x, y)];
		}
	}
	std::cout << "=================================================" << std::endl;
	for (int x = 0; x < matriza.sizeX(); x++)
	{
		std::cout << "(" << x << ")";
	}
	matriza.matrix_print();
	vvector<double> right = vvector<double>(dim_2);
	std::cout << "Введите правый столбец" << std::endl;
	for (int y = 0; y < dim_2; y++)
	{
		std::cout << "уравнения " << y + 1 << " ";
		std::cin >> right[y];
	}
	vvector<double> vals = matriza.gauss(right);
	std::cout << "===============================================" << std::endl;
	for (int i = 0; i < vals.size; i++) std::cout << "x" << i + 1 << "=" << vals[i] << std::endl;
	std::cout << std::endl;
}
