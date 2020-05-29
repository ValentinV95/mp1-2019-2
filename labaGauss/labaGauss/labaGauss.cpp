// labaGauss.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define INPUT = true
//#undef INPUT

#include "dop.h"
#include "slau.h"


int main()
{
	int f;
	int sizeX;
	int sizeY;
#if defined(INPUT)
	std::cout << "SizeX: ";
	std::cin >> sizeX;
	std::cout << "SizeY: ";
	std::cin >> sizeY;
#else
	sizeX = 4;
	sizeY = 4;
#endif

	slau _matrix = slau(sizeX, sizeY);
	slau _matrixx = slau(sizeX, sizeY);

#if defined(INPUT)
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			std::cout << "[" << x << "," << y << "] ";
			std::cin >> _matrix[matrix_index(x, y)];
			_matrixx[matrix_index(x, y)]= _matrix[matrix_index(x, y)];
		}
	}
#else

	_matrix[matrix_index(0, 0)] = 1;
	_matrix[matrix_index(1, 0)] = 2;
	_matrix[matrix_index(2, 0)] = 0;
	_matrix[matrix_index(3, 0)] = 0;

	_matrix[matrix_index(0, 1)] = 2;
	_matrix[matrix_index(1, 1)] = 4;
	_matrix[matrix_index(2, 1)] = 0;
	_matrix[matrix_index(3, 1)] = -3;

	_matrix[matrix_index(0, 2)] = -3;
	_matrix[matrix_index(1, 2)] = -4;
	_matrix[matrix_index(2, 2)] = 2;
	_matrix[matrix_index(3, 2)] = 3;

	_matrix[matrix_index(0, 3)] = -1;
	_matrix[matrix_index(1, 3)] = 0;
	_matrix[matrix_index(2, 3)] = 3;
	_matrix[matrix_index(3, 3)] = 6;

#endif

	std::cout << "-----" << std::endl;
	for (int x = 0; x < _matrix.sizeX(); x++)
	{
		std::cout << "[" << x << "] ";
	}
	_matrix.print();

	vector<double> ans = vector<double>(sizeY);
#if defined(INPUT)
	for (int y = 0; y < sizeY; y++)
	{
		std::cout << "[" << y << "] ";
		std::cin >> ans[y];
	}
#else
	ans[0] = 5;
	ans[1] = 6;
	ans[2] = -10;
	ans[3] = 3;
	
#endif

	vector<double> vals = _matrix.gauss(ans);

	std::cout << "-----" << std::endl;
	for (int i = 0; i < vals.size; i++) std::cout << "[" << i << "] " << vals[i];
	std::cout << std::endl;

	std::cout << "do you want to solve this matrix with a different right column? " << std::endl << "1 - yes" << std::endl << "2 - no" << std::endl;
    std::cin>> f;
	if (f == 2)
		std::cout << "ok";
	else
	{
		_matrix.print();
		std::cout << std::endl;
		vector<double> ans1 = vector<double>(sizeY);
		for (int y = 0; y < sizeY; y++)
		{
			std::cout << "[" << y << "] ";
			std::cin >> ans1[y];
		}
		
		std::cout << "-----" << std::endl;
		
		std::cout << std::endl;
		vector<double> vals1 = _matrixx.gauss(ans1);

		std::cout << "-----" << std::endl;
		for (int i = 0; i < vals1.size; i++) std::cout << "[" << i << "] " << vals1[i];
		std::cout << std::endl;
	}

}







// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
