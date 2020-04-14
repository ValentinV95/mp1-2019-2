#include "sorts.h"

void filler(double* a, int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = (double)rand()/RAND_MAX*(500000);
	}
}