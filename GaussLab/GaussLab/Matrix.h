#pragma once
#include "Vector.h"

using namespace std;

template < typename T >
class Matrix : public My_vector< My_vector < T > >
{
public:
	Matrix(int lines) : My_vector < My_vector < T > >(lines, My_vector < T >(lines)) {}
};