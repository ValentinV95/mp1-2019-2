#include "header.h"

void cmp_printer(Complex a) {
	cout << "[" << a.re << " " << a.im << "]";
}

Complex* set_values(int _dim, Complex _value) {
	Complex* values;
	values = new Complex[_dim];
	for (int i = 0; i < _dim; i++)
	{
		values[i] = _value;
	}
	return values;
	delete values;
}

void change_value(Vector& _v, Complex a){
	int pos;
	cout << "Choose position 0-" << _v.size-1 << "\n";
	cin >> pos;
	if (pos >= 0 && pos < _v.size)
	{
		_v.arr[pos] = a;
	}
	else
	{
		cout << "Wrong position!\n";
	}
}