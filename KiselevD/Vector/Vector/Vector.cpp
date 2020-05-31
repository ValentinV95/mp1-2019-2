#include <iostream>
using namespace std;

class Vector
{
public:
	Vector(int size = 10, int value = 0) {
		a = new int[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = value;
		}
		this->size = size;
		this->value = value;
	};

	Vector(const Vector& _copy) {
		size = _copy.size;
		value = _copy.value;
		a = new int[size];
		for (int i = 0; i < size; i++)
		{
			a[i] = _copy.a[i];
		}
		cout << size << " " << value << endl;
	};

	void sum(Vector* a) {
		if (a->size == size)
		{
			Vector c(a->size, 0);
			for (int i = 0; i < a->size; i++)
			{
				c.a[i] = a->a[i] + this->a[i];
			}
			cout << "Sum of vectors is: (";
			for (int i = 0; i < a->size; i++)
			{
				cout << " " << c.a[i];
			}
			cout << " )" << endl;
		}
		else
		{
			cout << "Size a != size b" << endl;
		}
	}

	void scalar(Vector* a) {
		int sc = 0;
		if (a->size == size)
		{
			for (int i = 0; i < a->size; i++)
			{
				sc = sc + (a->a[i] * this->a[i]);
			}
			cout << sc << endl;
		}
		else
		{
			cout << "Size a != size b" << endl;
		}
	}

	void change(int i, int value) {
		if (i >= 0 || i < this->value)
		{
			a[i] = value;
			cout << i << " coordinate get value " << value << endl;
		}
		for (int i = 0; i < this->size; i++)
		{
			cout << " " << a[i];
		}
	}

	~Vector() {
		delete(a);
	};

private:
	int* a;
	int size;
	int value;
};



int main()
{
	int size, value, change_val, pos;
	cout << "Input first vector size and value: " << endl;
	cin >> size >> value;
	Vector a(size, value);

	cout << "Input second vector size and value: " << endl;
	cin >> size >> value;
	Vector b(size, value);
	a.sum(&b);
	cout << "Copy of first vector: ";
	Vector d(a);
	cout << "Scalar product of vectors: ";
	a.scalar(&b);
	cout << "Input desired size and value: " << endl;
	cin >> pos >> change_val;
	a.change(pos, change_val);
}