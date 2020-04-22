#include "header.h"

void cmp_printer(Complex a) {
	cout << "[" << a.re << " " << a.im << "]";
}


int main()
{
	int dim;
	Complex* values;
	double re1, im1;
	cout << "Input first vector value: real and imagine parts: RE1 IM1\n";
	cin >> re1 >> im1;
	Complex cmp1(re1, im1);
	cout << "Input first vector dimension\n";
	cin >> dim;
	values = new Complex[dim];
	for (int i = 0; i < dim; i++)
	{
		values[i] = cmp1;
	}
	Vector v1(dim, cmp1);
	cout << "First vector:\n";
	v1.print();
	cout << "Input second vector value: real and imagine parts: RE1 IM1\n";
	cin >> re1 >> im1;
	Complex cmp2(re1, im1);
	cout << "Input second vector dimension\n";
	cin >> dim;
	Vector v2(dim, cmp2);
	cout << "Second vector:\n";
	v2.print();
	Vector v3;
	cout << "Sum of vectors:\n";
	v3 = v1 + v2;
	//v3 = v1;
	//v3.print();
}

