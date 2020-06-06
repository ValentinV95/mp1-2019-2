#pragma once
using namespace std;

template <typename T>
class My_matrix : public My_vector < My_vector < T > >
{
public:

	My_matrix(int n) : My_vector < My_vector < T > >(n, My_vector < T >(n)) {}

	My_matrix() {} // конструктор по умолчанию
private:

};