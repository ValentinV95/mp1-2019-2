#include <stdlib.h>
#include <iostream>

#include "data.h"

#include "FunFactorization.h"

void init(struct data* xn)																						// pick out arrays
{
	xn->x = (float*)malloc(sizeof(float) * xn->n);
	xn->err = (float*)malloc(sizeof(float) * (xn->n - 1));
	xn->sum = (float*)malloc(sizeof(float) * xn->n);
	memset(xn->x, 0, xn->n * sizeof(float));
	memset(xn->err, 0, xn->n * sizeof(float));
	memset(xn->sum, 0, xn->n * sizeof(float));
}

void initState(struct data* xn, float x)
{
	xn->x[0] = x;																								//x[0] = value of x or 1
	xn->sum[0] = x;																							   //sum[1] = x[0]
}

void fill(struct data* xn, void(*func)(float prev, float& x, int n), float x, float& prev, int n)
{
	for (int i = 1; i < xn->n; i++)
	{
		func(prev, x, i);
		xn->x[i] = x;
	}
}
