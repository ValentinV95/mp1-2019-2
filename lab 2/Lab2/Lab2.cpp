#include <iostream>
#include <stdio.h>
#include <math.h>

#include "data.h"

#include "initOnstruct.h"
#include "FunFactorization.h"
#include "sum.h"

int main()
{
	struct data xn;
	float first;
	
	bool flag = false;
	int factorization;	

	float x = 3.14;

	printf("Choice extent of factorization \n");
	scanf_s("%d", &xn.n);
	printf(" n = %d\n", xn.n);

	init(&xn);

	printf("Choice factorization:\n 1 - sinx,\n 2 - cosx,\n 3 - exp^x,\n 4 - ln(1+x).\n ");
	scanf_s("%d", &factorization);
	while (flag == false)
	{
		switch (factorization)
		{
		case 1:
		{
			printf("You have choisen 1 - sinx.\n");

			float x0 = x;
			first = x;

			printf("X = %lf\n", x);

			initState(&xn, x0);
			fill(&xn, fillSin, x0, first, xn.n);

			printf("Terms: ");
			for (int i = 0; i < xn.n; i++)
			{
				printf("%lf, ", xn.x[i]);
			}
			printf("\n\n");


			sum1_n(&xn);
			sumN_1(&xn);
			sumKah(&xn);
			printf("|   sum by math.h   | %lf \n", sinf(x0));

			flag = true;
			break;
		}
		case 2:
		{
			printf("You have choisen 2 - cosx.\n");

			float x0 = 1;
			first = x;

			initState(&xn, x0);
			fill(&xn, fillCos, x0, first, xn.n);

			printf("Terms: ");
			for (int i = 0; i < xn.n; i++)
			{
				printf("%lf, ", xn.x[i]);
			}
			printf("\n\n");

			sum1_n(&xn);
			sumN_1(&xn);
			sumKah(&xn);
			printf("|   sum by math.h   | %lf \n", cosf(first));

			flag = true;
			break;
		}
		case 3:
		{
			printf("You have choisen 3 - exp^x.\n");

			float x0 = 1;
			first = x;

			initState(&xn, x0);
			fill(&xn, fillExp, x0, first, xn.n);

			printf("Terms: ");
			for (int i = 0; i < xn.n; i++)
			{
				printf("%lf, ", xn.x[i]);
			}
			printf("\n\n");

			sum1_n(&xn);
			sumN_1(&xn);
			sumKah(&xn);
			printf("|   sum by math.h   | %lf \n", exp(first));

			flag = true;
			break;
		}
		case 4:
		{
			printf("You have choisen 4 - ln(1+x).\n");

			x = 1;
			float x0 = x;
			first = x;

			initState(&xn, x0);
			fill(&xn, fillLn, x0, first, xn.n);

			printf("Terms: ");
			for (int i = 0; i < xn.n; i++)
			{
				printf("%lf, ", xn.x[i]);
			}
			printf("\n\n");

			sum1_n(&xn);
			sumN_1(&xn);
			sumKah(&xn);
			printf("|   sum by math.h   | %lf \n", log(x0 + 1));                               

			flag = true;
			break;
		}
		default:
		{
			printf("Error. Incorrect value. Choice factorization again.\n 1 - sinx,\n 2 - cosx,\n 3 - exp^x,\n 4 - ln(1+x) ");

			scanf_s("%d", &factorization);

			flag = false;
		}
		};
	}

	//free(xn.x);
	//free(xn.err);
	//free(xn.sum);
}


