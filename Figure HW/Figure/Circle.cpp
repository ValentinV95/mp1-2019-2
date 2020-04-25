#include "Circle.h"

void Circle::set_r(int _r)
{
	r = _r;
}

int Circle::get_r()
{
	return r;
}

void Circle::print()
{
	Point _p = Get_point(0);
	_p.printP();
	std::cout << std::endl << "r: " << r;
}
