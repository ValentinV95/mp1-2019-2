#include "Header.h"

typedef struct xn
{
	int n;
	float* x;
	float* err;
	float* sum;
}poly;

void init(poly* a, int N)
{
	a->n = N;
	a->x = (float*)malloc(N * sizeof(float));
	a->err = (float*)malloc(N * sizeof(float));
	a->sum = (float*)malloc(N * sizeof(float));
	memset(a->x, 0, N * sizeof(float));
	memset(a->err, 0, N * sizeof(float));
	memset(a->sum, 0, N * sizeof(float));
}

void inistate_sin_ln(poly* a, float x)
{
	a->x[0] = x;
	a->sum[0] = a->x[0];
}

void inistate_cos_exp(poly* a)
{
	a->x[0] = 1;
	a->sum[0] = a->x[0];
}

void inistate_sin_ln_l2h(poly* a, float x)
{
	a->x[0] = x;
}

void inistate_cos_exp_l2h(poly* a)
{
	a->x[0] = 1;
}

float currentX_sin(float prev_x, float x, int n)
{
	float cur = ((-1) * x * x * prev_x) / ((2 * n + 2) * (2 * n + 3));
	return(cur);
}

float currentX_cos(float prev_x, float x, int n)
{
	float cur = ((-1) * x * x * prev_x) / ((2 * n + 1) * (2 * n + 2));
	return(cur);
}

float currentX_exp(float prev_x, float x, int n)
{
	float cur = (x * prev_x) / (n + 1);
	return(cur);
}

float currentX_ln(float prev_x, float x, int n)
{
	float cur = (prev_x * x * -1 * (n + 1)) / (n + 2);
	return(cur);
}


void fill(poly* a, float(*currentX)(float prev_x, float x, int n), float x, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		a->x[i + 1] = currentX(a->x[i], x, i);
	}
}

void addsum(poly* a, int N)
{
	a->sum[N - 1] = a->x[N - 1];
}

void sum_low_to_high(poly* a, int N) {
	for (int i = N - 1; i >= 0; i--)
	{
		a->sum[i - 1] = (a->sum[i] + a->x[i - 1]);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		printf("X%i : %f\n", i, a->x[i]);
		printf("sum%i : %f\n", i, a->sum[i]);
	}
}

void sum_high_to_low(poly* a, int N) {
	for (int i = 1; i < N; i++)
	{
		a->sum[i] = (a->sum[i - 1] + a->x[i]);
	}
	for (int i = 0; i < N; i++)
	{
		printf("X%i : %f\n", i, a->x[i]);
		printf("sum%i : %f\n", i, a->sum[i]);
	}
}

void struct_free(poly* a)
{
	free(a->x);
	free(a->err);
	free(a->sum);
}

void kahan(poly* a, int N)
{
	for (int i = 1; i < N; i++)
	{
		a->x[i] = a->x[i] + a->err[i - 1];
		a->sum[i] = a->sum[i - 1] + a->x[i];
		a->err[i] = (a->sum[i] - a->sum[i - 1]) - a->x[i];
		a->sum[i - 1] = a->sum[i];
	}
	for (int i = 0; i < N; i++)
	{
		printf("X%i : %f\n", i, a->x[i]);
		printf("sum%i : %f\n", i, a->sum[i]);
		printf("err%i : %f\n", i, a->err[i]);
	}
}
