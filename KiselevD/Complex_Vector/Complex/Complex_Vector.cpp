#include "header.h"

int main()
{
	int dim;
	int choice;
	int choice2 = 0;
	double re, im;
	double scalar;
	Vector tmp1, tmp2;
	cout << "Input first vector value: real and imagine parts: RE1 IM1\n";
	cin >> re >> im;
	Complex cmp1(re, im);
	cout << "Input first vector dimension\n";
	cin >> dim;
	Vector v1(dim, set_values(dim, cmp1));
	cout << "First vector:\n";
	v1.print();
	cout << "Input second vector value: real and imagine parts: RE2 IM2\n";
	cin >> re >> im;
	Complex cmp2(re, im);
	cout << "Input second vector dimension\n";
	cin >> dim;
	Vector v2(dim, set_values(dim, cmp2));
	cout << "Second vector:\n";
	v2.print();
	while (true)
	{
		cout << "Now you can change FIRST vector values, to close input 0, to continue input any number != 0\n";
		cin >> choice;
		if (choice != 0)
		{
			cout << "Input real and imagine parts: RE IM\n";
			cin >> re >> im;
			Complex change(re, im);
			change_value(v1, change);
			cout << "Changed vector:\n";
			v1.print();
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Now you can change SECOND vector values, to close input 0, to continue input any number != 0\n";
		cin >> choice;
		if (choice != 0)
		{
			cout << "Input real and imagine parts: RE IM\n";
			cin >> re >> im;
			Complex change(re, im);
			change_value(v2, change);
			cout << "Changed vector:\n";
			v2.print();
		}
		else
		{
			break;
		}
	}
	while (choice2 != 7)
	{
		cout << "Actions:\n1)Opposite\n2)Add\n3)Subtract\n4)Scalar product\n5)Multiply on double\n6)Divide on double\n7)Exit\n";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			tmp1 = -v1;
			tmp2 = -v2;
			cout << "Opposite of first vector:\n";
			tmp1.print();
			cout << "Opposite of second vector:\n";
			tmp2.print();
			break;
		case 2:
			if (v1.get_size()== v2.get_size())
			{
				cout << "Result of addition:\n";
				(v1 + v2).print();
			}
			else
			{
				cout << "Dimensions don't match\n";
			}
			break;
		case 3:
			if (v1.get_size() == v2.get_size())
			{
				cout << "Result of subtraction:\n";
				(v1 - v2).print();
			}
			else
			{
				cout << "Dimensions don't match\n";
			}
			break;
		case 4:
			if (v1.get_size() == v2.get_size())
			{
				cout << "Scalar product is:\n";
				cmp_printer(v1 * v2);
				cout << "\n";
			}
			else
			{
				cout << "Dimensions don't match\n";
			}
			break;
		case 5:
			cout << "Input a double number:\n";
			cin >> scalar;
			cout << "V1 * "<<scalar<<":\n";
			(v1 * scalar).print();
			cout << "V2 * " << scalar << ":\n";
			(v2 * scalar).print();
			break;
		case 6:
			cout << "Input a double number:\n";
			cin >> scalar;
			cout << "V1 / " << scalar << ":\n";
			(v1 / scalar).print();
			cout << "V2 / " << scalar << ":\n";
			(v2 / scalar).print();
			break;
		case 7:
			break;
		}
	}
}

