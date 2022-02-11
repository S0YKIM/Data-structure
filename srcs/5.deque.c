/*
이중 연결 리스트 덱 구현
*/

#include "data_structure.h"

/*
새로운 덱 생성
*/
LinkedDeque* createLinkedDeque()
{
	LinkedDeque *myDeque;

	myDeque = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
	if (!myDeque)
		return FALSE;
	return (myDeque);
}

/*
Enque: 덱의 프론트에 새 노드 추가
*/
int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *frontNode;
	
	if (!pDeque)
		return FALSE;
	frontNode = (DequeNode *)calloc(1, sizeof(DequeNode));
	if (!frontNode)
		return FALSE;
	*frontNode = element;

    if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pRearNode = frontNode;
		frontNode->pRLink = NULL;
	}
	else
	{
		pDeque->pFrontNode->pLLink = frontNode;
		frontNode->pRLink = pDeque->pFrontNode;
	}

	pDeque->pFrontNode = frontNode;
	frontNode->pLLink = NULL;
	
	pDeque->currentElementCount++;
	return (TRUE);
}

/*
Enque: 덱의 리어에 새 노드 추가
*/
int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *rearNode;
	
	if (!pDeque)
		return FALSE;
	rearNode = (DequeNode *)malloc(sizeof(DequeNode));
	if (!rearNode)
		return FALSE;
	*rearNode = element;
	
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = rearNode;
		rearNode->pLLink = NULL;
	}
	else
	{
		pDeque->pRearNode->pRLink = rearNode;
		rearNode->pLLink = pDeque->pRearNode;
	}

	pDeque->pRearNode = rearNode;
	rearNode->pRLink = NULL;
	
	pDeque->currentElementCount++;
	return (TRUE);
}

/*
Deque: 덱의 프론트 노드 삭제
*/
DequeNode*		deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *delNode;
	
	if (!pDeque)
		return NULL;
	if (isLinkedDequeEmpty(pDeque))
		return NULL;

	delNode = pDeque->pFrontNode;

	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		pDeque->pFrontNode = delNode->pRLink;
		pDeque->pFrontNode->pLLink = NULL;
	}
	pDeque->currentElementCount--;
	return (delNode);
}

/*
Deque: 덱의 리어 노드 삭제
*/
DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *delNode;
	
	if (!pDeque)
		return NULL;
	if (isLinkedDequeEmpty(pDeque))
		return NULL;

	delNode = pDeque->pRearNode;

	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		pDeque->pRearNode = delNode->pLLink;
		pDeque->pRearNode->pRLink = NULL;
	}
	pDeque->currentElementCount--;
	return (delNode);
}

/*
Peek: 덱의 프론트 노드 반환
*/
DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	DequeNode *frontNode;
	
	if (!pDeque)
		return NULL;
	frontNode = pDeque->pFrontNode;
	return (frontNode);
}

/*
Peek: 덱의 리어 노드 반환
*/
DequeNode* peekRearLD(LinkedDeque* pDeque)
{
  DequeNode *rearNode;

  if (!pDeque)
    return NULL;
  rearNode = pDeque->pRearNode;
  return (rearNode);
}

/*
덱이 비어있는가?
*/
int	isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (!pDeque)
		return FALSE;
	if (pDeque->currentElementCount == 0)
		return TRUE;
	else
		return FALSE;
}

/*
덱 삭제
*/
void	deleteLinkedDeque(LinkedDeque** pDeque)
{
	DequeNode	*curr;	
	DequeNode	*temp;
	
	
	if (!pDeque || !(*pDeque))
		return ;
	curr = (*pDeque)->pFrontNode;
	while (curr)
	{
		temp = curr;
		curr = curr->pRLink;
		free(temp);
		temp = NULL;
	}
	free(*pDeque);
	*pDeque = NULL;
}

/*
(Custom) 덱의 모든 노드의 데이터 출력
*/
void			displayLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode	*curr;
	int			i = 0;
	
	if (!pDeque)
		return ;
	curr = pDeque->pFrontNode;
	while (curr)
	{
		printf("index : %d, data : %d\n", i, curr->data);
		curr = curr->pRLink;
		i++;
	}
	return ;
}