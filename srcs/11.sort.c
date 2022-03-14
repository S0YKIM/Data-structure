/*
Merge (~13:00)
Quick (~15:30)
Insertion (~16:00)
*/

#include "data_structure.h"

void	merge(int *array, int start, int mid, int end)
{
	int	*left;
	int	*right;

	left = (int *)malloc(sizeof(int) * (mid - start + 1));
	if (!left)
		return ;
	right = (int *)malloc(sizeof(int) * (end - mid));
	if (!right)
	{
		free(left);
		return ;
	}

	for (int i = 0; i < mid - start; i++)
		left[i] = array[start + i];
	for (int i = 0; i < end - mid + 1; i++)
		right[i] = array[mid + i];

	int	l_idx = 0, r_idx = 0, a_idx = start;
	while ((l_idx < mid - start) && (r_idx < end - mid + 1))
	{
		if (left[l_idx] < right[r_idx])
			array[a_idx++] = left[l_idx++];
		else
			array[a_idx++] = right[r_idx++];
	}

	while (l_idx < mid - start)
		array[a_idx++] = left[l_idx++];
	while (r_idx < end - mid + 1)
		array[a_idx++] = right[r_idx++];

	free(left);
	free(right);
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