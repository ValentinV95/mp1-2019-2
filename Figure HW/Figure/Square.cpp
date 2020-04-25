#include "Square.h"

void Square::Check_Square()
{
	Point p1 = Get_point(0);
	Point p2 = Get_point(1);
	if ((p1.Get_x() != p2.Get_x()) && (p1.Get_y() != p2.Get_y()))
	{
		std::cout << "All right" << std::endl;
	}
	else
	{
		std::cout << "It is not square" << std::endl;
	}
}

void Square::Set_a(int _a)
{
	a = _a;
}

int Square::Get_a()
{
	return a;
}