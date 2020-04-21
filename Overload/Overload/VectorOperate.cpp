#include "ComplexVector.h"
#include "Complex.h"

Vector& Vector::operator= (const Vector& other)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = other.a[i];
	}
	return *this;
}
Vector Vector::operator+ ()
{
	for (int i = 0; i < size; i++)
	{
		a[i] = a[i];
	}
	return *this;
}

Vector Vector::operator- ()
{
for (int i = 0; i < size; i++)
	{
		a[i] = -a[i];
	}
	return *this;
}
Vector& Vector::operator++ ()
{
for (int i = 0; i < size; i++)
	{
		++a[i];
	}
	return *this;
}
Vector Vector::operator-- ()
{
for (int i = 0; i < size; i++)
	{
		--a[i];
	}
	return *this;
}
Vector Vector::operator++ (int)
{
	Vector tmp(*this);
	operator++();
	return tmp;

}
Vector Vector::operator-- (int)
{
	Vector tmp(*this);
	operator--();
	return tmp;
}

Vector Vector::operator+ (const Vector& rhs)
{
	Vector t;
	for (int i = 0; i < size; i++)
	{
		Complex tmp = a[i] + rhs.a[i];
		t[i] = tmp;
	}
	return t;
}
Vector Vector::operator- (const Vector& rhs)
{
	Vector t;
	for (int i = 0; i < size; i++)
	{
		Complex tmp = a[i] - rhs.a[i];
		t[i] = tmp;
	}
	return t;
}
Vector Vector::operator* (const Vector& rhs)
{
Vector t;
for (int i = 0; i < size; i++)
	{
		Complex tmp = a[i] * rhs.a[i];
		t[i] = tmp;
	}
	return t;
}
Vector Vector::operator/ (const Vector& rhs)
{
Vector t;
for (int i = 0; i < size; i++)
	{
		Complex tmp = a[i] * rhs.a[i];
		t[i] = tmp;
	}
	return t;
}
Vector& Vector::operator+= (const Vector& rhs) 
{
for (int i = 0; i < size; i++)
	{
		a[i] = a[i] + rhs.a[i];
	}
	return *this;
}
Vector& Vector::operator-= (const Vector& rhs)
{
for (int i = 0; i < size; i++)
	{
		a[i] = a[i] + rhs.a[i];
	}
	return *this;
}
Vector& Vector::operator*= (const Vector& rhs)
{
for (int i = 0; i < size; i++)
	{
		a[i] = a[i] * rhs.a[i];
	}
	return *this;
}
Vector& Vector::operator/= (const Vector& rhs)
{
for (int i = 0; i < size; i++)
	{
		a[i] = a[i] / rhs.a[i];
	}
	return *this;
}

bool Vector::operator== (const Vector& rhs)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] != rhs.a[i])
		{
			return false;
		}
	}

	return true;
}
bool Vector::operator!= (const Vector& rhs)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == rhs.a[i])
		{
			return false;
		}
	}

	return true;
}