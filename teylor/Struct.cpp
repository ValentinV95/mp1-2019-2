#include "struct.h"

void mass(str* a, int N)
{
	a->n = N;
	a->x = (float*)malloc(N * sizeof(float));
	a->err = (float*)malloc(N * sizeof(float));
	a->sum = (float*)malloc(N * sizeof(float));

	memset(a->x, 0, N * sizeof(float));                  //fill all 0
	memset(a->err, 0, N * sizeof(float));
	memset(a->sum, 0, N * sizeof(float));

}

void freestr(str* a)
{
	free(a->x);
	free(a->err);
	free(a->sum);

}
