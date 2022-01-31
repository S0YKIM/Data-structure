#include "data_structure.h"

/*
연결 리스트 스택 생성
*/
LinkedStack*	createLinkedStack()
{
	LinkedStack	*stack;

	stack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (stack == NULL)
		return (NULL);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

/*
연결 리스트 스택의 노드 추가
*/
int	pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*new;
	StackNode	*prev;

	if (!pStack)
		return (FALSE);
	new = (StackNode *)malloc(sizeof(StackNode));
	if (!new)
		return (FALSE);
	*new = element;
	prev = peekLS(pStack);
	new->pLink = prev;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

/*
연결 리스트 스택의 탑 노드 제거
*/
StackNode*	popLS(LinkedStack* pStack)
{
	StackNode	*element;

	element = peekLS(pStack);
	if (!element)
		return (NULL);
	if (pStack->currentElementCount == 1)
		pStack->pTopElement = NULL;
	else
		pStack->pTopElement = element->pLink;
	pStack->currentElementCount--;
	return (element);
}

/*
연결 리스트 스택의 탑 노드 주소 반환
*/
StackNode*	peekLS(LinkedStack* pStack)
{
	if (!pStack)
		return (NULL);
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement);
}

/*
연결 리스트 스택 제거
*/
void	deleteLinkedStack(LinkedStack** pStack)
{
	StackNode	*curr;
	StackNode	*next;

	if (!pStack)
		return ;
	curr = (*pStack)->pTopElement;
	while ((*pStack)->currentElementCount)
	{
		next = curr->pLink;
		free(curr);
		curr = next;
		(*pStack)->currentElementCount--;
	}
	free(*pStack);
	*pStack = NULL;
}

/*
연결 리스트 스택이 비어 있는지 확인
*/
int	isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (ERROR);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

/*
(Bonus) 연결 리스트 스택의 모든 데이터 출력
*/
void	displayLinkedStack(LinkedStack* pStack)
{
	StackNode	*curr;

	if (!pStack)
		return ;
	curr = pStack->pTopElement;
	if (!curr)
	{
		printf("Empty stack.");
		return ;
	}
	while (curr)
	{
		printf("%c ", curr->data);
		curr = curr->pLink;
	}
	printf("\n");
}