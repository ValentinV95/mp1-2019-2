#pragma once

#include "iostream"

#include "Point.h"

class Figure
{
public:

	Figure(int _size = 1) : size(_size)
	{
		p = new Point[size];

		for (int i = 0; i < _size; i++)
		{
			p[i] = 0;
		}
	}

	Figure(Point* _p, int _size = 1)
	{
		this->size = _size;
		p = new Point[size];

		for (int i = 0; i < size; i++)
		{
			p[i] = _p[i];
		}
	}

	void Set_point(Point _p);

	Point Get_point(int index);

	void move(int x_move, int y_move);

	void print_coord();

	~Figure()
	{
		delete[]p;
	}

private:
	int i = 0;

protected:
	int size;
	Point* p;
};
