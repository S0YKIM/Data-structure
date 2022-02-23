#include "data_structure.h"

void	test_min_heap()
{
	MinHeap		*heap;
	MinHeapNode	*tmp;

	heap = createMinHeap(4);
	if (!heap)
		return ;
	for (int i = 1; i < 14; i++)
		insertMinHeapData(heap, i);
	tmp = deleteMinHeapData(heap);
	insertMinHeapData(heap, tmp->data);
	free(tmp);
	displayMinHeap(heap);
	deleteMinHeap(&heap);
}