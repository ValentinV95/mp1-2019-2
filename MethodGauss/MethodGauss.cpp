#include <iostream>

int main()
{
	vector <double> a;
	vector <double> b;

	void print()
	{
		for (int i = 0; i < a.size; i++)
			std::cout << a[i] << " ";
	}
	vector <double> c;
	c = a + b;
	c.print;
}