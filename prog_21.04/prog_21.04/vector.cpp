#include "vector.h"
void vector::sum(vector v2, int size)
{
	for (int i = 0; i < size; i++)
		a[i] = a[i] + v2.a[i];
}

void vector::scalumn(vector v2)
{
	Complex pr(0,0);
	for (int i = 0; i < size; i++)
		pr = pr + a[i] * v2.a[i];
	pr.print();

}

void vector::prov(vector v2)
{
	if (size != v2.size)
	{
		std::cout << "ERROR";
		std::cout << "\n";
	}

}


void vector::print()
{
	for (int i = 0; i < size; i++)
	{
		a[i].print();
		std::cout << std::endl;
	}
}

std::ostream& operator << (std::ostream& os, const vector& dt)
{
	for (int i = 0; i < dt.size; i++)
	{

		os<<dt.a[i]<< std::endl;
	}

	return os;
}