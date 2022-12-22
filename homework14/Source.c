#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);

double* full_elements(double* ptr_array, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] = rand() % 50;
	}
	return ptr_array;
}

int put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\na[%d] = %lf", i, ptr_array[i]);
	}

	return 0;
}

double* calc_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] *= ptr_array[i];
		printf("\na[%d] = %g", i, ptr_array[i]);
	}
	return ptr_array;
}

double sum_elements(double* ptr_array, int begin, int end)
{
	double sum = 0;
	for (int i = begin; i <= end; i++)
	{
		sum += ptr_array[i];
	}
	printf("%g", sum);

	return sum;
}

int find_element(double* ptr_array, int n, double element)
{
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element)
		{
			return i;
			break;
		}
		else
		{
			return -1;
			break;
		}
	}
}

double fun_min(double* ptr_array, int n, int k)
{
	int i = k;
	double min = ptr_array[i];
	for (i; i < n; i++)
	{
		if (ptr_array[i] < min)
		{
			min = ptr_array[i];
		}
	}

	return min;
}

double fun_max(double* ptr_array, int n, int k)
{
	int i = k;
	double max = ptr_array[i];
	for (i; i < n; i++)
	{
		if (ptr_array[i] > max)
		{
			max = ptr_array[i];
		}
	}

	return max;
}


int main(void)
{
	setlocale(LC_ALL, "RUS");

	int size, begin, end, k;
	double a;

	printf("������� ������ ������� = \n");
	scanf("%d", &size);
	printf("������� ������ =\n");
	scanf("%d", &begin);
	printf("������� ����� =\n");
	scanf("%d", &end);
	printf("������� ������� =\n");
	scanf("%g", &a);
	printf("������� ������� =\n");
	scanf("%d", &k);
	double* array = (double*)calloc(size, sizeof(double));
	full_elements(array, size);
	puts("\n");
	put_elements(array, size);
	puts("\n");
	calc_elements(array, size);
	puts("\n");
	sum_elements(array, begin, end);
	puts("\n");
	printf("������ �������� = %d\n", find_element(array, size, a));

	printf("����������� �������� = %g\n", fun_min(array, size, k));
	printf("������������ �������� = %g\n", fun_max(array, size, k));

	float res = ((fun_min(array, size, k)) + (int)(fun_min(array, size, k))) / 2;

	printf("�������� �������� ����� ������������ � ����������� = %f", res);




	return 0;
}