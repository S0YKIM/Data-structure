/*
원형 배열 큐 구현
*/

#include "data_structure.h"

/*
새로운 큐 생성
*/
ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *myQueue;

	myQueue = (ArrayQueue *)calloc(1, sizeof(ArrayQueue));
	if (!myQueue)
		return FALSE;
	myQueue->maxElementCount = maxElementCount;
	myQueue->pElement = (ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));
	if (!myQueue->pElement)
		return FALSE;
	return (myQueue);
}

/*
Enque: 큐의 리어에 새 노드 추가
*/
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue)
		return FALSE;
	if (isArrayQueueFull(pQueue))
		return FALSE;
	if (pQueue->currentElementCount == 0)
		pQueue->pElement[pQueue->front] = element;
	else
	{
		pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
		pQueue->pElement[pQueue->rear] = element;
	}
	pQueue->currentElementCount++;
	
	return TRUE;
}

/*
Deque: 큐의 프런트 노드 삭제
*/
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	 ArrayQueueNode	*frontNode;
	
	if (!pQueue)
		return FALSE;
	if (isArrayQueueEmpty(pQueue))
		return FALSE;
	frontNode = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
	if (!frontNode)
		return FALSE;
	*frontNode = pQueue->pElement[pQueue->front];
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;	
	pQueue->currentElementCount--;
	return (frontNode);
}

/*
Peek: 큐의 피크 노드 반환
*/
ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{	
	ArrayQueueNode  *peekNode;
	
	if (!pQueue)
		return FALSE;
	peekNode = &pQueue->pElement[pQueue->front];
	return (peekNode);
}

/*
큐가 비어있는가?
*/
int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (!pQueue)
	return FALSE;
	if (pQueue->currentElementCount == 0)
		return TRUE;
	else
		return FALSE;
}

/*
큐가 가득 찼는가?
*/
int isArrayQueueFull(ArrayQueue* pQueue)
{
	if(!pQueue)
		return FALSE;
	if (pQueue->currentElementCount == pQueue->maxElementCount)
		return TRUE;
	else
		return FALSE;
}

/*
큐 삭제
*/
void deleteArrayQueue(ArrayQueue** pQueue)
{
	if (!pQueue || !(*pQueue))
		return ;
	free((*pQueue)->pElement);
	(*pQueue)->pElement = NULL;
	free(*pQueue);
	*pQueue = NULL;
	return ;
}

/* 
(Custom) 큐의 모든 데이터 출력
*/
void displayArrayQueue(ArrayQueue* pQueue)
{
	int	j;

	if (!pQueue)
		return ;
	j = pQueue->front;
	for (int i = 0; i < pQueue->currentElementCount; i++)
	{
		printf("index : %d, data : %d\n", j, pQueue->pElement[j].data);
		j = (j + 1) % pQueue->maxElementCount;
	}
}
