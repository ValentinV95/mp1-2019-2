#pragma once
#include <stdlib.h>
#include <iostream>
typedef struct xn
{
	int n;
	float* x;
	float* err;
	float* sum;

}str;
void mass(str* a, int N);

void freestr(str* a);
