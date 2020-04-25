#pragma once

#include "Figure.h"

class Circle : public Figure
{
public:
	Circle(int _r = 0, int _size = 1)
	{
		Figure(1);
		r = _r;
	}

	void set_r(int _r);

	int get_r();

	void print();

private:
	int r;

protected:
};
