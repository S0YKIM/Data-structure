#ifndef _MINHEAP_
# define _MINHEAP_

typedef struct MinHeapNodeType
{
	int data;
} MinHeapNode;

typedef struct MinHeapType
{
	int depth;
	int maxElementCount;
	int currentElementCount;
	MinHeapNode *pRootNode;
} MinHeap;

MinHeap		*createMinHeap(int depth);
void		deleteMinHeap(MinHeap **pMinHeap);
int			insertMinHeapData(MinHeap *pMinHeap, int data);
MinHeapNode	*deleteMinHeapData(MinHeap *pMinHeap);
int			isMinHeapFull(MinHeap *pMinHeap);
int			isMinHeapEmpty(MinHeap *pMinHeap);
void		displayMinHeap(MinHeap *MinHeap);

#endif

// #ifndef _COMMON_HEAP_DEF_
// # define _COMMON_HEAP_DEF_

// # define TRUE	1
// # define FALSE	0
// # define ERROR	-1

// #endif