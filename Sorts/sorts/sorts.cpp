#include "sorts.h"

void bubblesort(double* a, int n) {
	int flag;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swapf(a[j], a[j + 1]);
				flag++;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

void insertion(double* a, int n) {
	for (int i = 0; i < n; i++)
	{
		int k = i;
		while (k != 0 && a[k] < a[k - 1]) {
			swapf(a[k], a[k - 1]);
			k--;
		}
	}
}

void shell(double* a, int n) {
	for (int h = n / 2; h > 0; h /= 2)
	{
		for (int i = h; i < n; i++)
		{
			for (int j = i; j >= h; j -= h)
			{
				if (a[j] < a[j - h])
				{
					swapf(a[j], a[j - h]);
				}
				else
				{
					break;
				}
			}
		}
	}
}

void combsort(double* a, int n) {
	int step = n / 2;
	for (; step > 1; step /= 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j + step < n; j += step)
			{
				if (a[j] > a[j + step])
				{
					swapf(a[j], a[j + step]);
				}
			}
		}
	}
}

void count(double* a, unsigned int* counter, int n, int offset) {
	unsigned char* b = (unsigned char* )a;
	b = b + offset;
	memset(counter, 0, 256 * sizeof(unsigned int));
	for (int i = 0; i < n; i++, b += sizeof(double))
	{
		counter[*b]++;
	}
	int s = 0, tmp;
	for (int i = 0; i < 255; i++)
	{
		tmp = counter[i];
		counter[i] = s;
		s += tmp;
	}
}

void radix(double* a, int n) {
	unsigned int counter[256];
	unsigned char* c = (unsigned char*)a;
	double* b = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < sizeof(double); i++)
	{
		count(a, counter, n, i);
		for (int j = 0; j < n; j++)
		{
			b[counter[*(c + i + j * sizeof(double))]++];
		}
		for (int j = 0; j < n; j++)
		{
			a[j] = b[j];
		}
	}
	free(b);
}
