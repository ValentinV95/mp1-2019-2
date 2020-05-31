#pragma once

template <typename T>
T Mod(T x)
{
	if (x < 0)
	{
		return -x;
	}
	else
	{
		return x;
	}
}