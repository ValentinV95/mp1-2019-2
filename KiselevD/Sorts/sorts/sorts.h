#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void filler(double* a, int n);
void swapf(double& a, double& b);
void bubblesort(double* a, int n);
void insertion(double* a, int n);
void shell(double* a, int n);
void combsort(double* a, int n);
void count(double* a, unsigned int* counter, int n, int offset);
void radix(double* a, int n);