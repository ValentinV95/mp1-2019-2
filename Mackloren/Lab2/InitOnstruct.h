#pragma once

void init(struct data* xn);

void initState(struct data* xn, float x);

void fill(struct data* xn, void(*func)(float prev, float& x, int n), float x, float& prev, int n);