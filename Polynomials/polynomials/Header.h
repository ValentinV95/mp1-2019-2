#pragma once
#include <math.h>
#include <iostream>

typedef struct xn
{
	int n;
	float* x;
	float* err;
	float* sum;
}poly;

void init(poly* a, int N);
void inistate_sin_ln(poly* a, float x);
void inistate_cos_exp(poly* a);
void inistate_sin_ln_l2h(poly* a, float x);
void inistate_cos_exp_l2h(poly* a);
void addsum(poly* a, int N);
float currentX_sin(float prev_x, float x, int n);
float currentX_cos(float prev_x, float x, int n);
float currentX_exp(float prev_x, float x, int n);
float currentX_ln(float prev_x, float x, int n);
void sum_low_to_high(poly* a, int N);
void sum_high_to_low(poly* a, int N);
void kahan(poly* a, int N);
void struct_free(poly* a);
void fill(poly* a, float(*currentX)(float prev_x, float x, int n), float x, int n);
