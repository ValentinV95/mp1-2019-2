#pragma once
template <typename T>
T abs(T a) {
	if (a < 0)
	{
		return -a;
	}
	else
	{
		return a;
	}
}