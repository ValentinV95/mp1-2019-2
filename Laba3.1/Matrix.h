#pragma once
using namespace std;

template <typename T>
class Matrix : public Vector < Vector < T > >
{
public:

	Matrix(int n) : Vector < Vector < T > >(n, Vector < T >(n)) {}

	void matrix_print()
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				cout << this->mas[i][j] << "\n";
			}
			cout << endl;
		}
	}

private:

};