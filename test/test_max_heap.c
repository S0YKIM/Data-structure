#include "data_structure.h"

void	test_max_heap()
{
	MaxHeap	*heap;

	heap = createMaxHeap(4);
	if (!heap)
		return ;
	for (int i = 1; i < 14; i++)
		insertMaxHeapData(heap, i);
	displayMaxHeap(heap);
	deleteMaxHeap(&heap);
}