#pragma once
#include <iostream>
#include"Vector.h"

using namespace std;

template <typename T>
class Matrix : public Vector <Vector <T> >
{
public:
	Matrix(int N) : Vector<Vector <T>>(N, Vector <T>(N)) {}
};
