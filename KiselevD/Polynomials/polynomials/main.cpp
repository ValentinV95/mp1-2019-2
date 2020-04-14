// polynomials.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <math.h>
#include <iostream>

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
	float cur = ((-1) * x * x * prev_x )/( (2 * n + 2) * (2 * n + 3));
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
	float cur = (prev_x*x*-1*(n+1))/(n+2);
	return(cur);
}


void fill(poly* a, float(*currentX)(float prev_x, float x, int n), float x, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		a->x[i+1] = currentX(a->x[i], x, i);
	}
}

void addsum(poly* a, int N)
{
	a->sum[N - 1] = a->x[N - 1];
}

void sum_low_to_high(poly* a, int N) {
	for (int i = N-1; i >= 0; i--)
	{
		a->sum[i-1] = (a->sum[i] + a->x[i-1]);
	}
}

void sum_high_to_low(poly* a, int N) {
	for (int i = 1; i < N; i++)
	{
		a->sum[i] = (a->sum[i - 1] + a->x[i]);
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
}

void results(poly* a, poly* b, poly* c, poly* d, poly* e, poly* f, poly* g, poly* h, poly* i, poly* j, poly* k, poly* l, int N, float x) {
	if (abs(x) < 1)
	{
		printf(" --------------------------------------------------------- \n");
		printf("|   method    |   sin    |    cos   |    exp   |    ln    |\n");
		printf(" --------------------------------------------------------- \n");
		printf("| high to low | %f | %f | %f | %f |\n", a->sum[N - 1], d->sum[N - 1], g->sum[N - 1], j->sum[N - 1]);
		printf(" --------------------------------------------------------- \n");
		printf("| low to high | %f | %f | %f | %f |\n", b->sum[0], e->sum[0], h->sum[0], k->sum[0]);
		printf(" --------------------------------------------------------- \n");
		printf("|    Kahan    | %f | %f | %f | %f |\n", c->sum[N - 1], f->sum[N - 1], i->sum[N - 1], l->sum[N - 1]);
		printf(" --------------------------------------------------------- \n");
		printf("|    math.h   | %f | %f | %f | %f |\n", sin(x), cos(x), exp(x), log(1 + x));
		printf(" --------------------------------------------------------- \n");
	}
	else
	{
		printf(" --------------------------------------------------------- \n");
		printf("|   method    |   sin    |    cos   |    exp   |    ln    |\n");
		printf(" --------------------------------------------------------- \n");
		printf("| high to low | %f | %f | %f |    --    |\n", a->sum[N - 1], d->sum[N - 1], g->sum[N - 1]);
		printf(" --------------------------------------------------------- \n");
		printf("| low to high | %f | %f | %f |    --    |\n", b->sum[0], e->sum[0], h->sum[0]);
		printf(" --------------------------------------------------------- \n");
		printf("|    Kahan    | %f | %f | %f |    --    |\n", c->sum[N - 1], f->sum[N - 1], i->sum[N - 1]);
		printf(" --------------------------------------------------------- \n");
		printf("|    math.h   | %f | %f | %f | %f |\n", sin(x), cos(x), exp(x), log(1 + x));
		printf(" --------------------------------------------------------- \n");
	}
}

int main()
{
	float(*currentX)(float prev_x, float x, int n) = NULL;

	int sw = 0;
	float x;
	const int N = 20;
	while (sw != 2) {
		printf("Select an operation:\n1)Calculate the values\n2)Exit\n");
		scanf_s("%i", &sw);
		switch (sw)
		{
		case 1:
			printf("Enter the angle in radians:\n");
			scanf_s("%f", &x);
			currentX = currentX_sin;

			poly sin1;
			init(&sin1, N);
			inistate_sin_ln(&sin1, x);
			fill(&sin1, currentX, x, N);
			sum_high_to_low(&sin1, N);

			poly sin2;
			init(&sin2, N);
			inistate_sin_ln_l2h(&sin2, x);
			fill(&sin2, currentX, x, N);
			addsum(&sin2, N);
			sum_low_to_high(&sin2, N);

			poly sin3;
			init(&sin3, N);
			inistate_sin_ln(&sin3, x);
			fill(&sin3, currentX, x, N);
			kahan(&sin3, N);

			currentX = currentX_cos;
			poly cos1;
			init(&cos1, N);
			inistate_cos_exp(&cos1);
			fill(&cos1, currentX, x, N);
			sum_high_to_low(&cos1, N);

			poly cos2;
			init(&cos2, N);
			inistate_cos_exp_l2h(&cos2);
			fill(&cos2, currentX, x, N);
			addsum(&cos2, N);
			sum_low_to_high(&cos2, N);

			poly cos3;
			init(&cos3, N);
			inistate_cos_exp(&cos3);
			fill(&cos3, currentX, x, N);
			kahan(&cos3, N);

			currentX = currentX_exp;
			poly exp1;
			init(&exp1, N);
			inistate_cos_exp(&exp1);
			fill(&exp1, currentX, x, N);
			sum_high_to_low(&exp1, N);

			poly exp2;
			init(&exp2, N);
			inistate_cos_exp_l2h(&exp2);
			fill(&exp2, currentX, x, N);
			addsum(&exp2, N);
			sum_low_to_high(&exp2, N);

			poly exp3;
			init(&exp3, N);
			inistate_cos_exp(&exp3);
			fill(&exp3, currentX, x, N);
			kahan(&exp3, N);

			currentX = currentX_ln;

			poly ln1;
			init(&ln1, N);
			inistate_sin_ln(&ln1, x);
			fill(&ln1, currentX, x, N);
			sum_high_to_low(&ln1, N);

			poly ln2;
			init(&ln2, N);
			inistate_sin_ln_l2h(&ln2, x);
			fill(&ln2, currentX, x, N);
			addsum(&ln2, N);
			sum_low_to_high(&ln2, N);

			poly ln3;
			init(&ln3, N);
			inistate_sin_ln(&ln3, x);
			fill(&ln3, currentX, x, N);
			kahan(&ln3, N);

			results(&sin1, &sin2, &sin3, &cos1, &cos2, &cos3, &exp1, &exp2, &exp3, &ln1, &ln2, &ln3, N, x);
			break;
		case 2:
			struct_free(&sin1);
			struct_free(&sin2);
			struct_free(&sin3);
			struct_free(&cos1);
			struct_free(&cos2);
			struct_free(&cos3);
			struct_free(&exp1);
			struct_free(&exp2);
			struct_free(&exp3);
			struct_free(&ln1);
			struct_free(&ln2);
			struct_free(&ln3);
			break;
		}
	}
}



