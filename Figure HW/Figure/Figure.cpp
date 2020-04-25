#include "Figure.h"

void Figure::Set_point(Point _p)
{
	if (i < size)
	{
		p[i] = _p;
		i++;
	}
	else
	{
		std::cout << "error - memory has ended " << std::endl;
	}
}

Point Figure::Get_point(int index)
{
	if (index < size)
	{
		return p[index];
	}
	else
	{
		std::cout << "error" << std::endl << std::endl;
		return 0;
	}
}

void Figure::move(int x_move, int y_move)
{
	Point _p = { x_move, y_move };
	for (int i = 0; i < size; i++)
	{
		p[i] = _p;
	}
}

void Figure::print_coord()
{
	std::cout << "Coord: ";
	for (int i = 0; i < size; i++)
	{
		Get_point(i).printP();
		std::cout << ", ";
	}
	std::cout << std::endl;
}