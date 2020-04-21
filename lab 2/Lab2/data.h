#pragma once

struct data																										//struct
{
	int n;																									    //extent of factorization
	float* x;                                                                                                  //value x1,x2,...,xn
	float* err;																								  //error: (xn->sum[i] + xn->x[i + 1]) - xn->sum[i]; for any i 
	float* sum;
};