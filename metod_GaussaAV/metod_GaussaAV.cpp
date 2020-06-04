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
	SLAU _matriza = SLAU(dim_1, dim_2);
	for (int y = 0; y < dim_2; y++)
	{
		std::cout << "Введите коэффициенты перед неизвестными уравнения " << y + 1 << std::endl;
		for (int x = 0; x < dim_1; x++)
		{
			//std::cout << "[" << x << "," << y << "] ";
			std::cin >> matriza[element(x, y)];
			_matriza[element(x, y)] = matriza[element(x, y)];
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
	int f = 0;
	int k;
	while (f == 0)
	{
		std::cout << "хотите повторно использовать матрицу?" << std::endl << "1-да" << std::endl << "2-нет" << std::endl;
		std::cin >> k;
		if (k == 2)
		{
			f = 1;
			std::cout << "конец программы";
		}
		else
		{
			_matriza.matrix_print();
			std::cout << std::endl;
			vvector<double> right1 = vvector<double>(dim_2);
			std::cout << "Введите правый столбец" << std::endl;
			for (int y = 0; y < dim_2; y++)
			{
				std::cout << "уравнения " << y + 1 << " ";
				std::cin >> right1[y];
			}
			std::cout << "=============================================" << std::endl;
			vvector<double> vals1 = _matriza.gauss(right1);
			std::cout << "=============================================" << std::endl;
			for (int i = 0; i < vals1.size; i++) std::cout << "x" << i + 1 << "=" << vals1[i] << std::endl;
			std::cout << std::endl;
		}
	}
}