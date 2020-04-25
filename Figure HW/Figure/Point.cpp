#include "Point.h"

#include "iostream"

void Point::Set_x(int value)
{
	x = value;
}

void Point::Set_y(int value)
{
	y = value;
}

int& Point::Get_x()
{
	return x;
}

int& Point::Get_y()
{
	return y;
}

Point Point::operator+ (const Point& _p)
{
	return Point(x + _p.x, y + _p.y);
}

Point Point::operator- (const Point& _p)
{
	return Point(x - _p.x, y - _p.y);
}

Point Point::operator* (const Point& _p)
{
	return Point(x * _p.x, y * _p.y);
}

Point Point::operator= (const Point& _p)
{
	x = _p.x;
	y = _p.y;

	return *this;
}

bool Point::operator!= (const Point& _p)
{
	if ((x == _p.x) && (y == _p.y))
	{
		return false;
	}

	return true;
}

bool Point::operator< (const Point& _p)
{
	if ((x < _p.x) && (y < _p.y))
	{
		return true;
	}

	return false;
}

bool Point::operator<= (const Point& _p)
{
	if ((x <= _p.x) && (y <= _p.y))
	{
		return true;
	}

	return false;
}

void Point::printP()
{
	std::cout << x << " ";

	std::cout << y << " ";
}