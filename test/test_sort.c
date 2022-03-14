#include "data_structure.h"

void	test_merge_sort()
{
	int	array[] = {80, 50, 70, 10, 60, 20, 40, 30};
	int n = sizeof(array)/sizeof(int);

	printf("-------------- Original array --------------\n");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("--------------------------------------------\n");

	merge_sort(array, 0, n - 1);

	printf("\n-------------- Sorted array ----------------\n");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("--------------------------------------------\n");
}

void	test_quick_sort()
{
	int	array[] = {80, 50, 70, 10, 60, 20, 40, 30};
	int n = sizeof(array)/sizeof(int);

	printf("-------------- Original array --------------\n");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("--------------------------------------------\n");

	quick_sort(array, 0, n - 1);

	printf("\n-------------- Sorted array ----------------\n");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("--------------------------------------------\n");
}

void	test_insertion_sort()
{
	int	array[] = {80, 50, 70, 10, 60, 20, 40, 30};
	int n = sizeof(array)/sizeof(int);

	printf("-------------- Original array --------------\n");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("--------------------------------------------\n");

	insertion_sort(array, n - 1);

	printf("\n-------------- Sorted array ----------------\n");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("--------------------------------------------\n");
}