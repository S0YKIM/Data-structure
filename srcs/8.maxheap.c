/*
최대 힙
*/

#include "data_structure.h"

MaxHeap	*createMaxHeap(int maxElementCount)
{
	MaxHeap *newHeap;

	if (maxElementCount <= 0)
		return (NULL); 
	newHeap = (MaxHeap *)malloc(sizeof(MaxHeap));
	if (!newHeap)
		return (NULL);
	newHeap->maxElementCount = maxElementCount;
	newHeap->CurrentElementCount = 0;
	newHeap->pRootNode = (MaxHeapNode *)calloc(1, sizeof(MaxHeapNode) * (maxElementCount + 1));
	if (!newHeap->pRootNode)
	{
		free(newHeap);
		return (NULL);
	}
	return (newHeap);
}

int		getCurrentElementCount(MaxHeap *MaxHeap)
{
	if (!MaxHeap)
		return (ERROR);
	return (MaxHeap->CurrentElementCount);
}

int		isMaxHeapFull(MaxHeap *pMaxHeap)
{
	if (!pMaxHeap)
		return (ERROR);
	if (pMaxHeap->CurrentElementCount == pMaxHeap->maxElementCount)
		return (TRUE);
	return (FALSE);
}
int		isMaxHeapEmpty(MaxHeap *pMaxHeap)
{
	if (!pMaxHeap)
		return (ERROR);
	if (pMaxHeap->CurrentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

int	insertMaxHeapData(MaxHeap *pMaxHeap, int data)
{
	int index;
	int parent_index;
	int	tmp;

	if (!pMaxHeap)
		return (NULL);
	if (isMaxHeapFull(pMaxHeap))
	{
		printf("The heap is already full.\n");
		return (NULL);
	}
	index = getCurrentElementCount(pMaxHeap) + 1;
	pMaxHeap->pRootNode[index].data = data;
	pMaxHeap->CurrentElementCount++;
	parent_index = index / 2;
	while (parent_index)
	{
		if (pMaxHeap->pRootNode[index].data <= pMaxHeap->pRootNode[parent_index].data)
			return (TRUE);
		tmp = pMaxHeap->pRootNode[index].data;
		pMaxHeap->pRootNode[index].data = pMaxHeap->pRootNode[parent_index].data;
		pMaxHeap->pRootNode[parent_index].data = tmp;
		index /= 2;
		parent_index = index / 2;
	}
	return (TRUE);
}

MaxHeap	*deleteMaxHeapData(MaxHeap *pMaxHeap)
{
	if (!pMaxHeap || pMaxHeap->CurrentElementCount == 0)
		return (NULL);
	
}

void	deleteMaxHeap(MaxHeap *pMaxHeap)
{

}

void	displayMaxHeap(MaxHeap *MaxHeap)
{

}