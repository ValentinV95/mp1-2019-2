#include "Triangle.h"

void Triangle::Check_triangle()
{
	if ((Get_point(0) != Get_point(1)) && (Get_point(0) != Get_point(2)) && (Get_point(1) != Get_point(2)))
	{
		Point p1 = Get_point(1) - Get_point(0);
		Point p2 = Get_point(2) - Get_point(1);
		Point p3 = Get_point(0) - Get_point(2);

		if ((p3 * p3 <= p1 * p1 + p2 * p2) && (p2 * p2 <= p1 * p1 + p3 * p3) && (p1 * p1 <= p2 * p2 + p3 * p3))
		{
			std::cout << "All right!" << std::endl;
		}
		else
		{
			std::cout << "It is not triangle" << std::endl;
		}
	}
	else
	{
		std::cout << "It is not triangle" << std::endl;
	}
}

double Triangle::Get_side_a()
{
	Point p1 = (Get_point(1) - Get_point(0)) * (Get_point(1) - Get_point(0));
	int x = p1.Get_x();
	int y = p1.Get_y();
	return (x + y);
}

double Triangle::Get_side_b()
{
	Point p1 = (Get_point(2) - Get_point(1)) * (Get_point(2) - Get_point(1));
	int x = p1.Get_x();
	int y = p1.Get_y();
	return (x + y);
}

double Triangle::Get_side_c()
{
	Point p1 = (Get_point(0) - Get_point(2)) * (Get_point(0) - Get_point(2));
	int x = p1.Get_x();
	int y = p1.Get_y();
	return (x + y);
}