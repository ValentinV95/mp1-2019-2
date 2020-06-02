#include "tip.h"
void tip_1(str* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		a->sum[i - 1] = (a->sum[i] + a->x[i - 1]);
	for (int i = n - 1; i >= 0; i--)
	{
		printf("ard%i : %f\n", i, a->x[i]);
		printf("sum%i : %f\n", i, a->sum[i]);
		printf("\n");
	}
}

void tip_2(str* a, int n)
{
	for (int i = 1; i < n; i++)
		a->sum[i] = (a->sum[i - 1] + a->x[i]);

	for (int i = 0; i < n; i++)
	{
		printf("arg%i : %f\n", i, a->x[i]);
		printf("sum%i : %f\n", i, a->sum[i]);
		printf("\n");
	}

}

void tip_3(str* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		a->x[i] = a->x[i] + a->err[i - 1];
		a->sum[i] = a->sum[i - 1] + a->x[i];
		a->err[i] = (a->sum[i] - a->sum[i - 1]) - a->x[i];
		a->sum[i - 1] = a->sum[i];

	}

	for (int i = 0; i < n; i++)
	{

		printf("arg%i : %f\n", i, a->x[i]);
		printf("sum%i : %f\n", i, a->sum[i]);
		printf("err%i : %f\n", i, a->err[i]);
		printf("\n");
	}

}