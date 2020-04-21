#include <stdlib.h>
#include <iostream>

#include "data.h"

void sum1_n(struct data* xn)
{
	for (int i = 1; i < xn->n; i++)
	{
		xn->sum[i] = xn->sum[i - 1] + xn->x[i];
	}

	printf("|   sum to end      | %lf \n", xn->sum[xn->n - 1]);

	memset(xn->sum, 0, xn->n * sizeof(float));
}

void sumN_1(struct data* xn)
{
	xn->sum[xn->n] = xn->x[xn->n - 1];

	for (int i = xn->n; i > 1; i--)
	{
		xn->sum[i - 1] = xn->sum[i] + xn->x[i - 2];
	}

	printf("|   sum to begin    | %lf \n", xn->sum[1]);

	memset(xn->sum, 0, xn->n * sizeof(float));
}

void sumKah(struct data* xn)
{
	xn->sum[0] = xn->x[0];

	for (int i = 1; i < xn->n; i++)
	{
		float t = xn->sum[i - 1] + xn->x[i];
		xn->err[i] = (t - xn->sum[i - 1]) - xn->x[i];
		xn->x[i + 1] = xn->x[i + 1] + xn->err[i];
		xn->sum[i] = t;
	}

	printf("|   sum by Kahan    | %lf\n", xn->sum[xn->n - 1]);
}