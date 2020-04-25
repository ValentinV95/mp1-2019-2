#pragma once

#include "polygone.h"

#include "math.h"


class Triangle : public Polygone
{
public:
	Triangle(int _size = 3) : Polygone(_size) {};

	void Check_triangle();

	double Get_side_a();

	double Get_side_b();

	double Get_side_c();

private:

protected:
};
