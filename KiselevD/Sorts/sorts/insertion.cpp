#include "sorts.h"

void insertion(double* a, int n, double& c) {
	for (int i = 0; i < n; i++)
	{
		int k = i;
		while (k != 0 && a[k] < a[k - 1]) {
			swapf(a[k], a[k - 1]);
			k--;
			c++;
		}
	}
}