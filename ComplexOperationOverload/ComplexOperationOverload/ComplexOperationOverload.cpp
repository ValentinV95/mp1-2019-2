// ComplexOperationOverload.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Complex
{
private:
	double re, im;

public:
	Complex()
	{
		re = 0;
		im = 0;
	};

	Complex(double r, double i)
	{
		re = r;
		im = i;
	}

	Complex(const Complex& other)
	{
		re = other.re;
		im = other.im;
	}

	Complex& operator =(Complex& other)
	{
		re = other.re;
		im = other.im;
		return *this;
	}

	Complex& operator +=(Complex& other)
	{
		re = re + other.re;
		im = im + other.im;
		return *this;
	}

	Complex& operator -=(Complex& other)
	{
		re = re - other.re;
		im = im - other.im;
		return *this;
	}

	Complex& operator *=(Complex& other)
	{
		re = re * other.re - im * other.im;
		im = im * other.re + re * other.im;
		return *this;
	}

	Complex& operator /=(Complex& other)
	{
		double k, i, r;
		k = other.re * other.re + other.im * other.im;
		r = (re * other.re + im * other.im) / k;
		i = (other.re * im - re * other.im) / k;
		re = r;
		im = i;
		return *this;
	}

	Complex operator +(const Complex& rhs)
	{
		return Complex(re + rhs.re, im + rhs.im);
	}

	Complex operator -(Complex& rhs)
	{
		return Complex(re - rhs.re, im - rhs.im);
	}

	Complex operator *(Complex& rhs)
	{
		return Complex(re * rhs.re - im * rhs.im, im * rhs.re + re * rhs.im);
	}

	Complex operator -()
	{
		return Complex(-re, -im);
	}

	Complex operator /(const Complex& rhs)
	{
		double k, i, r;
		k = rhs.re * rhs.re + rhs.im * rhs.im;
		r = (re * rhs.re + im * rhs.im) / k;
		i = (rhs.re * im - re * rhs.im) / k;
		return Complex(r, i);
	}


	bool operator ==(const Complex& rhs) {
		if ((re == rhs.re) && (im == rhs.im))
			return true;
		return false;
	}

	bool operator !=(const Complex& rhs) {
		return !(*this == rhs);
	}
	
	void Printcomplex() 
	{
		cout << re << "\t" << im << endl;
	}

	friend Complex operator/(const Complex& rhs, const double& lhs);
	friend Complex operator-(const Complex& rhs, const double& lhs);
	friend Complex operator+(const Complex& rhs, const double& lhs);
	friend Complex operator*(const Complex& rhs, const double& lhs);
};


Complex operator/(const Complex& rhs, const double& lhs)
{
	return Complex(rhs.re / lhs, rhs.im / lhs);
}

Complex operator-(const Complex& rhs, const double& lhs)
{
	return Complex(rhs.re - lhs, rhs.im);
}

Complex operator+(const Complex& rhs, const double& lhs)
{
	return Complex(rhs.re + lhs, rhs.im);
} 

Complex operator*(const Complex& rhs, const double& lhs)
{
	return Complex(rhs.re * lhs, rhs.im * lhs);
}

int main()
{
	Complex a(5, 10);
	Complex b(7, 2);
	Complex c = a + b;
	c.Printcomplex();

	c = b;
	c.Printcomplex();

	Complex d = -c;
	d.Printcomplex();

	Complex e = a - b;
	e.Printcomplex();

	Complex f = a * b;
	f.Printcomplex();

	bool g = c == b;
	cout << g << endl;
	bool h = c != b;
	cout << h << endl;

	double i = 2.232;
	Complex j = a / i;
	j.Printcomplex();

	double k = 1.554;
	Complex l = a + i;
	l.Printcomplex();

	double m = 2.354;
	Complex n = a - i;
	n.Printcomplex();

	double o = 3.554;
	Complex p = a * i;
	p.Printcomplex();

	Complex q = a / b;
	q.Printcomplex();

	c += a;
	c.Printcomplex();

	c -= a;
	c.Printcomplex();

	c *= a;
	c.Printcomplex();

	c /= a;
	c.Printcomplex();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
