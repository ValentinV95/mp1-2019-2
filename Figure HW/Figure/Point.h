#pragma once

class Point
{
public:
	Point(int value_x = 0, int value_y = 0)
	{
		x = value_x;
		y = value_y;
	}

	void  Set_x(int value);

	void Set_y(int value);

	int& Get_x();

	int& Get_y();

	Point operator+ (const Point& _p);

	Point operator- (const Point& _p);

	Point operator* (const Point& _p);

	Point operator= (const Point& _p);

	bool operator!= (const Point& _p);
	
	bool operator< (const Point& _p);

	bool operator<= (const Point& _p);

	void printP();

private:
	int x;
	int y;

protected:

};
