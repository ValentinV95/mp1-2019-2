#include "header.h"

void printer(Complex a) {
	cout << "(" << a.re << " " << a.im << ")" << "\n";
}

int main()
{
	int choice = 0;
	double re1, im1, re2, im2;
	cout << "Input real and imagine parts: RE1 IM1\n";
	cin >> re1 >> im1;
	cout << "Input real and imagine parts: RE2 IM3\n";
	cin >> re2 >> im2;
	Complex a(re1, im1);
	Complex b(re2, im2);
	cout << "What do you want?\n1)Add\n2)Subtract\n3)Multiply\n4)Divide\n5)Compare by absolute value\n6)Exit\n";
	while (choice != 6)
	{
		cin >> choice;
		switch (choice) {
		case 1:
			printer(a + b);
			break;
		case 2:
			printer(a - b);
			break;
		case 3:
			printer(a * b);
			break;
		case 4:
			printer(a / b);
			break;
		case 5:
			if (a == b)
			{
				cout << "Numbers are equal\n";
			}
			if (a < b)
			{
				cout << "Number1 is less\n";
			}
			if (a > b)
			{
				cout << "Number2 is less\n";
			}
			break;
		case 6:
			break;
		}
	}
}

