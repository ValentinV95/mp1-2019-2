// sorts.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//пузырек, вставки, шелла, расческа, поразрядная

#include "sorts.h"

void ArPrint(double* a, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%lf\n", a[i]);
	}
	printf("___\n\n");
}


int main()

{
	double start, finish, result;
	int choice;
	double *a, *b, *c, *d, *e;
	const int n1 = 500, n2 = 5000, n3 = 10000, n4 = 50000, n5 = 100000;
	a = (double*)malloc(n1 * sizeof(double));
	b = (double*)malloc(n2 * sizeof(double));
	c = (double*)malloc(n3 * sizeof(double));
	d = (double*)malloc(n4 * sizeof(double));
	e = (double*)malloc(n5 * sizeof(double));
	filler(a, n1);
	filler(b, n2);
	filler(c, n3);
	filler(d, n4);
	filler(e, n5);
	printf("Choice a sort:\n1) Bubblesort\n2) Insertion\n3) Shell\n4) Combsort\n");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		start = clock();
		bubblesort(a, n1);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("Elements   Time\n%d        %.3f\n", n1, result);
		start = clock();
		bubblesort(b, n2);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d       %.3f\n", n2, result);
		start = clock();
		bubblesort(c, n3);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d      %.3f\n", n3, result);
		start = clock();
		bubblesort(d, n4);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d      %.3f\n", n4, result);
		start = clock();
		bubblesort(e, n5);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d     %.3f\n", n5, result);
		break;
	case 2:
		start = clock();
		insertion(a, n1);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("Elements   Time\n%d        %.3f\n", n1, result);
		start = clock();
		insertion(b, n2);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d       %.3f\n", n2, result);
		start = clock();
		insertion(c, n3);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d      %.3f\n", n3, result);
		start = clock();
		insertion(d, n4);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d      %.3f\n", n4, result);
		start = clock();
		insertion(e, n5);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d     %.3f\n", n5, result);
		break;
	case 3:
		start = clock();
		shell(a, n1);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("Elements   Time\n%d        %.3f\n", n1, result);
		start = clock();
		shell(b, n2);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d       %.3f\n", n2, result);
		start = clock();
		shell(c, n3);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d      %.3f\n", n3, result);
		start = clock();
		shell(d, n4);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d      %.3f\n", n4, result);
		start = clock();
		shell(e, n5);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d     %.3f\n", n5, result);
		break;
	case 4:
		start = clock();
		combsort(a, n1);
		bubblesort(a, n1);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("Elements   Time\n%d        %.3f\n", n1, result);
		start = clock();
		combsort(b, n2);
		bubblesort(b, n2);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d       %.5f\n", n2, result);
		start = clock();
		combsort(c, n3);
		bubblesort(c, n3);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d      %.5f\n", n3, result);
		start = clock();
		combsort(d, n4);
		bubblesort(d, n4);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d      %.5f\n", n4, result);
		start = clock();
		combsort(e, n5);
		bubblesort(e, n5);
		finish = clock();
		result = (finish - start) / CLOCKS_PER_SEC;
		printf("%d     %.5f\n", n5, result);
		break;
	case 5:
		radix(e, n5);
	default:
		printf("Wrong choice!");
		return(5);
	}
	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
}

