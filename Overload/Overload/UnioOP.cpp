#include "Complex.h"

Complex Complex::operator+ ()
{
	return Complex(+re, +im);
}

Complex Complex::operator- ()
{
	return Complex(-re, -im);
}

Complex& Complex::operator++ ()						//++re
{
	re++;
	return *this;
}

Complex Complex::operator-- ()						//--re
{
	re--;
	return *this;
}

Complex Complex::operator++ (int)					//re++
{
	Complex res(*this);
	++(*this);
	return res;
}

Complex Complex::operator-- (int)					//re--
{
	Complex res(*this);
	--(*this);
	return res;
}

bool Complex::operator! ()						//!re
{
	if (re != 0)
	{
		return true;
	}
	
	return false;
}
