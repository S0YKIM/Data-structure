#include "data_structure.h"

/*
새로운 배열 스택 생성
*/
ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack  *stack;

	if (maxElementCount < 0)
		return (NULL);
	stack = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (stack == NULL)
		return (NULL);
	stack->maxElementCount = maxElementCount;
	stack->currentElementCount = 0;
	stack->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (stack->pElement == NULL)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	return (stack);
}

/*
배열 스택의 탑에 새로운 노드 추가
*/
int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	if (!pStack)
		return (FALSE);
	if (isArrayStackFull(pStack))
		return (FALSE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

/*
배열 스택의 탑 노드를 제거
*/
ArrayStackNode*	popAS(ArrayStack* pStack)
{
	ArrayStackNode	*element;

	element = peekAS(pStack);
	if (!element)
		return (NULL);
	pStack->currentElementCount--;
	return (element);
}

/*
배열 스택의 탑 노드의 주소 반환
*/
ArrayStackNode*	peekAS(ArrayStack* pStack)
{
	if (!pStack)
		return (NULL);
	if (isArrayStackEmpty(pStack))
		return (NULL);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

/*
배열 스택 제거
*/
void	deleteArrayStack(ArrayStack** pStack)
{
    if (!pStack || !(*pStack))
        return ;
	free((*pStack)->pElement);
	free(*pStack);
	*pStack = NULL;
}

/*
배열 스택이 꽉 찼는지 확인
*/
int	isArrayStackFull(ArrayStack* pStack)
{
	if (!pStack)
		return (ERROR);
	if (pStack->maxElementCount == pStack->currentElementCount)
		return (TRUE);
	else
		return (FALSE);
}

/*
배열 스택이 비어있는지 확인
*/
int	isArrayStackEmpty(ArrayStack* pStack)
{
	if (!pStack)
		return (ERROR);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

/*
(Bonus) 배열 스택의 모든 데이터 출력
*/
void	displayArrayStack(ArrayStack* pStack)
{
	int	i;

	if (!pStack)
		return ;
	if (!pStack->currentElementCount)
	{
		printf("Empty stack.");
		return ;
	}
	for (i = pStack->currentElementCount - 1; i >= 0 ; i--)
	{
		printf("%c ", pStack->pElement[i].data);
	}
	printf("\n");
}