#include "rectangle.h"

void Rectangle::Check_rectangle()
{
	Point p1 = Get_point(0) - Get_point(1);
	Point p2 = Get_point(2) - Get_point(1);

	Point p3 = p1 * p2;

	if ((p1 != 0) && (p2 != 0))
	{
		double angle = p3.Get_x() + p3.Get_y();

		if (angle == 0)
		{
			std::cout << "All right" << std::endl;
		}
		else
		{
			std::cout << "It is not rectangle" << std::endl;
		}
	}
	else
	{
		std::cout << "It is not rectangle" << std::endl;
	}
}