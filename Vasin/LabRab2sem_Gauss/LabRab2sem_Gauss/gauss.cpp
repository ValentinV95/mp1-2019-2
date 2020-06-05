#include <iostream>
#include <iomanip>
#include "My_vector.h"
#include "My_matrix.h"
#include "SLAE.h"
using namespace std;

template <typename T>
void InputMat(int size, My_matrix<T>& mat) // заполнение матрицы
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "Input [" << i << "]" << "[" << j << "] element:" << endl;
			cin >> mat[i][j];
		}
	}
}

void RandMat_double(int size, My_matrix<double>& mat) // для отладки и проверки ввода матрицы
{
	double min, max;
	min = 1;
	max = 50;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mat[i][j] = (double)rand() / (double)RAND_MAX * (max - min) + min;
		}
	}
}

template <typename T>
void InputVec(int size, My_vector<T>& vec) // заполнение свободных членов
{
	for (int i = 0; i < size; i++)
	{
		cout << "Input [" << i << "]  element:" << endl;
		cin >> vec[i];
	}
}

void RandVec_double(int size, My_vector<double>& vec) // проверка заполнения с рандомными числами типа double
{
	double min, max;
	min = 1;
	max = 50;

	for (int i = 0; i < size; i++)
	{
		vec[i] = (double)rand() / (double)RAND_MAX * (max - min) + min;
	}
}

template <typename T>
void m_print(int size, My_matrix<T>& mat) // вывод матрицы на экран
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

template <typename T>
void v_print(int size, My_vector<T>& vec) // вывод на экран значений вектора
{
	cout << "{";
	for (int i = 0; i < size - 1; i++)
	{
		cout << vec[i] << ";";
	}
	cout << vec[size - 1] << "}";
	cout << endl;
	cout << endl;
}

void mv_print(int size, My_matrix<double>& mat, My_vector<double>& vec) // вывод матрицы и вектора на экран
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//cout << mat[i][j] << setw(5) << "\t";
			printf("%8.2f   ", mat[i][j]);                    // printf() используем для более красивого вывода
		}
		//cout << "| " << vec[i] << endl;
		printf("| %8.2f   ", vec[i]);
		printf("\n");
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));  // разные значения srand()

	int size;
	cout << "Input matrix size:" << endl;
	cin >> size;
	cout << endl;

	My_matrix<double>mat(size);
	//InputMat(size, mat);     // ввод матрицы
	RandMat_double(size, mat); // тест
	//m_print(size, mat);

	My_vector<double>vec(size);
	//InputVec(size, vec);     // ввод свободных членов
	RandVec_double(size, vec); // тест
	//v_print(size, vec);

	cout << "Original matrix:" << endl;
	mv_print(size, mat, vec);

	SLAE<double>sl(mat);
	My_vector<double>sol(size);
	sol = sl.gauss(vec);
	
	cout << "Triangular matrix:" << endl;
	My_matrix<double>mat_triang(size);
	mat_triang = sl.get_triangular_matrix();
	mv_print(size, mat_triang, vec);

	cout << "Solution vector:" << endl;
	v_print(size, sol);

	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	RandVec_double(size, vec); // тест

	cout << "Original matrix:" << endl;
	mv_print(size, mat, vec);

	//SLAE<double>sl1(mat);
	sol = sl.gauss(vec);

	cout << "Triangular matrix:" << endl;
	mat_triang = sl.get_triangular_matrix();
	mv_print(size, mat_triang, vec);

	cout << "Solution vector:" << endl;
	v_print(size, sol);

	cout << "-------------------------------------------------------------------------------------------------" << endl;
}

