/*
Merge (~13:00)
Quick (~15:30)
Insertion (~16:00)
*/

#include "data_structure.h"

void	merge(int *array, int start, int mid, int end)
{
	int	*l;
	int	*r;

	l = (int *)malloc(sizeof(int) * (mid - start + 1));
	if (!l)
		return ;
	r = (int *)malloc(sizeof(int) * (end - mid));
	if (!r)
	{
		free(l);
		return ;
	}

	for (int i = 0; i < mid - start; i++)
		l[i] = array[start + i];
	for (int i = 0; i < end - mid + 1; i++)
		r[i] = array[mid + i];

	int	l_idx = 0, r_idx = 0, a_idx = start;
	while ((l_idx < mid - start) && (r_idx < end - mid + 1))
	{
		if (l[l_idx] < r[r_idx])
			array[a_idx++] = l[l_idx++];
		else
			array[a_idx++] = r[r_idx++];
	}

	while (l_idx < mid - start)
		array[a_idx++] = l[l_idx++];
	while (r_idx < end - mid + 1)
		array[a_idx++] = r[r_idx++];

	free(l);
	free(r);
}

void	merge_sort(int *array, int start, int end)
{
	int	mid;

	if (start >= end)
		return ;
	if (!array)
		return ;
	mid = (start + end + 1) / 2;
	merge_sort(array, start, mid - 1);
	merge_sort(array, mid, end);
	merge(array, start, mid, end);
}

static void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int *array, int start, int end)
{
	int	l;
	int	r;

	if (start >= end)
		return ;

	l = start;
	r = end;

	while (l < r)
	{
		while (array[l] <= array[end] && l < end)
			l++;
		while (array[r] >= array[end] && r > l)
			r--;
		swap(array + l, array + r);
	}

	swap(array + l, array + end);
	quick_sort(array, start, l - 1);
	quick_sort(array, l + 1, end);
}