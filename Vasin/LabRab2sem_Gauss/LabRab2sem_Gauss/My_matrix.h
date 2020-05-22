#pragma once
using namespace std;

template <typename T>
class My_matrix : public My_vector < My_vector < T > >
{
public:

	My_matrix(int n) : My_vector < My_vector < T > >(n, My_vector < T >(n)) {}

	void m_print()
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				cout << this->mas[i][j] << "\t";
			}
			cout << endl;
		}
	}

private:

};