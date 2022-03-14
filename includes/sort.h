#ifndef _SORT_
# define _SORT_

/* 병합 정렬 */
void	merge_sort(int *array, int start, int end);
void	merge(int *array, int start, int mid, int end);

/* 퀵 정렬 */
void	quick_sort(int *array, int start, int end);

#endif