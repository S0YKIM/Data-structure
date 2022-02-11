/*
연결 리스트로 구현한 큐
(이중 연결 리스트 덱에서 가져옴)
*/

#include "data_structure.h"

/*
새로운 큐 생성
*/
LinkedQueue* createLinkedQueue()
{
	LinkedQueue *myQueue;

	myQueue = (LinkedQueue *)calloc(1, sizeof(LinkedQueue));
	if (!myQueue)
		return FALSE;
	return (myQueue);
}

/*
Enque: 큐의 리어에 새 노드 추가
*/
int enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element)
{
	LinkedQueueNode *rearNode;

	if (!pQueue)
		return FALSE;
	rearNode = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
	if (!rearNode)
		return FALSE;
	*rearNode = element;
	
	if (isLinkedQueueEmpty(pQueue))
		pQueue->pFrontNode = rearNode;
	else
		pQueue->pRearNode->pElement = rearNode;
	pQueue->pRearNode = rearNode;
	rearNode->pElement = NULL;
	
	pQueue->currentElementCount++;
	return (TRUE);
}

/*
Dequeue: 큐의 프론트 노드 삭제
*/
LinkedQueueNode*	dequeueLQ(LinkedQueue* pQueue)
{
	LinkedQueueNode *delNode;
	
	if (!pQueue)
		return NULL;
	if (isLinkedQueueEmpty(pQueue))
		return NULL;

	delNode = pQueue->pFrontNode;
	if (pQueue->currentElementCount == 1)
	{
		pQueue->pFrontNode = NULL;
		pQueue->pRearNode = NULL;
	}
	else
		pQueue->pFrontNode = delNode->pElement;
	pQueue->currentElementCount--;
	return (delNode);
}

/*
Peek: 큐의 프론트 노드 반환
*/
LinkedQueueNode* peekLQ(LinkedQueue* pQueue)
{
	LinkedQueueNode *frontNode;
	
	if (!pQueue)
		return NULL;
	frontNode = pQueue->pFrontNode;
	return (frontNode);
}

/*
큐가 비어있는가?
*/
int	isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	if (!pQueue)
		return FALSE;
	if (pQueue->currentElementCount == 0)
		return TRUE;
	else
		return FALSE;
}

/*
큐 삭제
*/
void	deleteLinkedQueue(LinkedQueue** pQueue)
{
	LinkedQueueNode	*curr;	
	LinkedQueueNode	*temp;
	
	if (!pQueue || !(*pQueue))
		return ;
	curr = (*pQueue)->pFrontNode;
	while (curr)
	{
		temp = curr;
		curr = curr->pElement;
		free(temp);
		temp = NULL;
	}
	free(*pQueue);
	*pQueue = NULL;
}

/*
(Custom) 큐의 모든 노드의 데이터 출력
*/
void	displayLinkedQueue(LinkedQueue *pQueue)
{
	LinkedQueueNode	*curr;
	int				i;
	
	if (!pQueue)
		return ;
	curr = pQueue->pFrontNode;
	i = 0;
	while (curr)
	{
		printf("Index : %d, Arrival time : %d\n", i, curr->data.arrivalTime);
		curr = curr->pElement;
		i++;
	}
	return ;
}