// teylor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "struct.h"
#include "tip.h"



void sin_ln_initstat(str* a, float y)
{
	a->x[0] = y;
	a->sum[0] = a->x[0];
}



void cos_e_initstate(str* a)
{
	a->x[0] = 1;
	a->sum[0] = a->x[0];
}

void sin_ln_initstate_1(str* a, float x)
{
	a->x[0] = x;

}

void cos_e_initstate_1(str*a)
{
	a->x[0] = 1;

}

float tekush_sin(float prevx, float x,int n)
{
	float sl = ((-1) * x * x * prevx) / ((2 * n + 2) * (2 * n + 3));
	return(sl);
}


float tekush_cos(float prevx, float x, int n)
{
	float sl = ((-1) * x * x * prevx) / ((2 * n + 1) * (2 * n + 2));
	return(sl);
}

float tekush_e(float prevx, float x, int n)
{
	float sl = (x * prevx) / (n + 1);
	return(sl);
}

float tekush_ln(float prevx, float x, int n)
{
	float sl = (prevx * x * -1*(n + 1)) / (n + 2);
	return(sl);
}

void filler(str* a, float(*tekush)(float prevx, float x, int n), float x,int n)
{
	for (int i = 0; i < n - 1; i++)
		a->x[i + 1] = tekush(a->x[i], x, i);
}



void sum(str* a, int n)
{
	a->sum[n - 1] = a->x[n - 1];
}


int main()


{
	float(*tekush)(float prevx, float x, int n) = NULL;

	int func, slog, vid;
	float x;

	printf("chouse the function:\n 1.sin\n 2.cos\n 3.exp\n 4.ln\n");
	scanf_s("%i", &func);

	printf("couse vid podscheta:\n 1.tip1\n 2.tip2\n 3.tip3\n");
	scanf_s("%i", &vid);

	printf("vvedite argument:\n");
	scanf_s("%f", &x);

	printf("vvedite kolichestvo chlenov:\n");
	scanf_s("%i", &slog);

	if (func == 1)
	{
		tekush = tekush_sin;
		str ryd;
		float atalon;
		mass(&ryd, slog);


		switch (vid)
		{
		case 1:                                       
			sin_ln_initstat(&ryd, x);
			filler(&ryd, tekush, x, slog);
			tip_2(&ryd, slog);
			
			freestr(&ryd);

			atalon = sin(x);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;
		case 2:
			sin_ln_initstate_1(&ryd, x);
			filler(&ryd, tekush, x, slog);
			sum(&ryd,slog);
			tip_1(&ryd, slog);
			
			freestr(&ryd);

			atalon = sin(x);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;
		case 3:
			sin_ln_initstat(&ryd, x);
			filler(&ryd, tekush, x, slog);
			tip_3(&ryd, slog);

			freestr(&ryd);

			atalon = sin(x);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;

		}


	}

	if (func == 2)
	{
		tekush = tekush_cos;
		str ryd;
		float atalon;
		mass(&ryd, slog);


		switch (vid)
		{
		case 1:
			cos_e_initstate(&ryd);
			filler(&ryd, tekush, x, slog);
			tip_2(&ryd, slog);

			freestr(&ryd);

			atalon = cos(x);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;
		case 2:
			cos_e_initstate_1(&ryd);
			filler(&ryd, tekush, x, slog);
			sum(&ryd, slog);
			tip_1(&ryd, slog);
			
			freestr(&ryd);

			atalon = cos(x);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;
		case 3:
			cos_e_initstate(&ryd);
			filler(&ryd, tekush, x, slog);
			tip_3(&ryd, slog);


			freestr(&ryd);

			atalon = cos(x);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;

		}

	}

	if (func == 3)
	{
		tekush = tekush_e;
		str ryd;
		float atalon;
		mass(&ryd, slog);


		switch (vid)
		{
		case 1:
			cos_e_initstate(&ryd);
			filler(&ryd, tekush, x, slog);
			tip_2(&ryd, slog);
			
			freestr(&ryd);

			atalon = exp(x);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;
		case 2:
			cos_e_initstate_1(&ryd);
			filler(&ryd, tekush, x, slog);
			sum(&ryd, slog);
			tip_1(&ryd, slog);
			
			freestr(&ryd);

			atalon = exp(x);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;
		case 3:
			cos_e_initstate(&ryd);
			filler(&ryd, tekush, x, slog);
			tip_3(&ryd, slog);


			freestr(&ryd);

			atalon = exp(x);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;

		}




	}
	if (func == 4)
	{
		tekush = tekush_ln;
		str ryd;
		float atalon;
		mass(&ryd, slog);


		switch (vid)
		{
		case 1:
			sin_ln_initstat(&ryd, x);
			filler(&ryd, tekush, x, slog);
			tip_2(&ryd, slog);
			
			freestr(&ryd);

			atalon = log(x+1);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;
		case 2:
			sin_ln_initstate_1(&ryd, x);
			filler(&ryd, tekush, x, slog);
			sum(&ryd, slog);
			tip_1(&ryd, slog);

			freestr(&ryd);

			atalon = log(x+1);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;
		case 3:
			sin_ln_initstat(&ryd, x);
			filler(&ryd, tekush, x, slog);
			tip_3(&ryd, slog);

			freestr(&ryd);

			atalon = log(x+1);
			printf("\n znachenie is math.h: ");
			printf("%f", atalon);

			break;
		
		}
	
	}

	return 0;
}










// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
