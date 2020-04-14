#include <iostream>

#include "Complex.h"

void Complex::printE()
{
	std::cout << re << ", " << im << std::endl;
}

void Complex::print()
{
	std::cout << re << ", " << im << " ";
}
