#pragma once

#include "Polygone.h"

class Rectangle : public Polygone
{
public:
	Rectangle(int _size = 4) : Polygone(_size) {};

	void Check_rectangle();

private:

protected:

};