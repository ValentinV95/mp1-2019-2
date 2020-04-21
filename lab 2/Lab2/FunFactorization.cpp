#include "data.h"

void fillSin(float first, float& x, int n)
{
	x = (-1) * x * (first * first) / ((2 * n) * (2 * n + 1));
	
}

void fillCos(float first, float& x, int n)
{
	x = (-1) * x * (first * first) / ((2 * (n - 1) + 2) * (2 * (n - 1) + 1));
	
}

void fillExp(float first, float& x, int n)
{
	x = (x * first) / ((n - 1) + 1);
	
}

void fillLn(float first, float& x, int n)
{
	x = (-1) * (x * first) * n / (n + 1);
	
}