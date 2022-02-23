/*
최소 힙
*/

#include "data_structure.h"

MinHeap	*createMinHeap(int depth)
{
	MinHeap *newHeap;
	int 	maxElementCount = 1;

	if (depth < 1)
		return (NULL); 
	newHeap = (MinHeap *)malloc(sizeof(MinHeap));
	if (!newHeap)
		return (NULL);
	for (int i = 1 ; i <= depth ; i++)
		maxElementCount *= 2;
	newHeap->depth = depth;
	newHeap->maxElementCount = maxElementCount - 1;
	newHeap->currentElementCount = 0;
	newHeap->pRootNode = (MinHeapNode *)calloc(1, sizeof(MinHeapNode) * (maxElementCount));
	if (!newHeap->pRootNode)
	{
		free(newHeap);
		return (NULL);
	}
	return (newHeap);
}

static int	getCurrentElementCount(MinHeap *MinHeap)
{
	if (!MinHeap)
		return (ERROR);
	return (MinHeap->currentElementCount);
}

int		isMinHeapFull(MinHeap *pMinHeap)
{
	if (!pMinHeap)
		return (ERROR);
	if (pMinHeap->currentElementCount == pMinHeap->maxElementCount)
		return (TRUE);
	return (FALSE);
}
int		isMinHeapEmpty(MinHeap *pMinHeap)
{
	if (!pMinHeap)
		return (ERROR);
	if (pMinHeap->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

static void	swapHeapNode(MinHeap *heap, int a, int b)
{
	int	tmp;

	if (a == b || a < 1 || b < 1 || a > heap->currentElementCount || b > heap->currentElementCount)
		return ;
	tmp = heap->pRootNode[a].data;
	heap->pRootNode[a].data = heap->pRootNode[b].data;
	heap->pRootNode[b].data = tmp;
}

int	insertMinHeapData(MinHeap *pMinHeap, int data)
{
	int index;

	if (!pMinHeap)
		return (ERROR);
	if (isMinHeapFull(pMinHeap))
	{
		printf("The heap is already full.\n");
		return (ERROR);
	}
	index = getCurrentElementCount(pMinHeap) + 1;
	pMinHeap->pRootNode[index].data = data;
	pMinHeap->currentElementCount++;
	while (index / 2)
	{
		if (pMinHeap->pRootNode[index].data >= pMinHeap->pRootNode[index/2].data)
			return (TRUE);
		swapHeapNode(pMinHeap, index, index / 2);
		index /= 2;
	}
	return (TRUE);
}

static int	getChildCount(MinHeap *pMinHeap, int index)
{
	if (!pMinHeap || index < 1 || index > pMinHeap->currentElementCount)
		return (ERROR);
	if (index * 2 > pMinHeap->currentElementCount)
		return (0);
	else if (index * 2 == pMinHeap->currentElementCount)
		return (1);
	else
		return (2);
}

MinHeapNode	*deleteMinHeapData(MinHeap *pMinHeap)
{
	MinHeapNode	*targetData;
	int			index;
	int			childIndex;
	int			childCount;

	if (!pMinHeap || pMinHeap->currentElementCount == 0)
		return (NULL);

	targetData = (MinHeapNode *)malloc(sizeof(MinHeapNode));
	if (!targetData)
		return (NULL);

	*targetData = pMinHeap->pRootNode[1];
	index = 1;
	pMinHeap->pRootNode[1] = pMinHeap->pRootNode[getCurrentElementCount(pMinHeap)];
	pMinHeap->currentElementCount--;
	childCount = getChildCount(pMinHeap, index);
	while (childCount)
	{
		if (childCount == 1)
			childIndex = index * 2;
		else if (childCount == 2)
		{
			if (pMinHeap->pRootNode[index * 2].data < pMinHeap->pRootNode[index * 2 + 1].data)
				childIndex = index * 2;
			else
				childIndex = index * 2 + 1;
		}
		if (pMinHeap->pRootNode[index].data < pMinHeap->pRootNode[childIndex].data)
			break ;
		swapHeapNode(pMinHeap, index, childIndex);
		index = childIndex;
		childCount = getChildCount(pMinHeap, index);
	}
	return (targetData);
}

void	deleteMinHeap(MinHeap **pMinHeap)
{
	if (!pMinHeap || !(*pMinHeap))
		return ;
	free((*pMinHeap)->pRootNode);
	free(*pMinHeap);
	*pMinHeap = NULL;
}

static int	getPowerOfTwo(int num)
{
	int	tmp;
	int	maxInt;
	int power;

	maxInt = 2147483647;
	tmp = 1;
	power = 0;
	while (tmp <= maxInt && tmp > 0)
	{
		if (tmp == num)
			return (power);
		tmp *= 2;
		power++;
	}
	return (-1);
}

void	displayMinHeap(MinHeap *pMinHeap)
{
	int	power;

	if (!pMinHeap)
		return ;
	printf("------------ Min Heap ------------\n");
	if (isMinHeapEmpty(pMinHeap))
	{
		printf("The heap is empty.\n");
		return ;
	}
	else if (isMinHeapFull(pMinHeap))
		printf("The heap is full.\n");
	printf("Max element count : %i\n", pMinHeap->maxElementCount);
	printf("Current element count : %i\n", pMinHeap->currentElementCount);
	printf("----------------------------------\n");
	for (int i = 1; i <= pMinHeap->currentElementCount; i++)
	{
		power = getPowerOfTwo(i);
		if (power > -1)
			printf("\nLevel[%i] : ", power + 1);
		printf("[%i] ", pMinHeap->pRootNode[i].data);
	}
	printf("\n----------------------------------\n");
}
