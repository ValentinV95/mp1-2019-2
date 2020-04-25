#pragma once

#include "rectangle.h"

class Square : public Rectangle
{
public:
	Square(int _a, int _size = 2) : Rectangle(_size), a(_a) {};

	void Check_Square();

	void Set_a(int _a);

	int Get_a();

private:
	int a;

protected:
};