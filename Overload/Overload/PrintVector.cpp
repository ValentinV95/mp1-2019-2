#include "ComplexVector.h"
#include "Complex.h"

void Vector::printV()
{
	for (int i = 0; i < size; i++)
	{
		Complex c1 = a[i];
		c1.printC();
	}
	
}