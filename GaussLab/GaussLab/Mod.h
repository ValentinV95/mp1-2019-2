#pragma once

template <typename T>
T mod(T a) {
	if (a > 0)
	{
		return a;
	}
	else
	{
		return -a;
	}
}