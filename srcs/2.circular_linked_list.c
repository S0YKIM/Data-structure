#include "data_structure.h"

/*
연결리스트 생성
*/
LinkedList	*createCircularList()
{
    LinkedList* lst;

    lst = (LinkedList*)malloc(sizeof(LinkedList));
    if (!lst)
        return (NULL);
    lst->currentElementCount = 0;
    lst->headerNode.data = 0;
    lst->headerNode.pLink = NULL;
    return (lst);
}

/*
연결 리스트의 요소 [i]번째에 추가
*/
int	addCircularElement(LinkedList* pList, int position, ListNode element)
{	
	ListNode	*new_node;
	ListNode	*ptr;
	ListNode	*last;

	if (position < 0)
		return (FALSE);

	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (!(new_node))
		return (FALSE);
	*new_node = element;
	ptr = pList->headerNode.pLink;

	if (position <= pList->currentElementCount)
	{
		// 처음 노드 추가
		if (pList->currentElementCount == 0)
		{
			new_node->pLink = new_node;
			pList->headerNode.pLink = new_node;
		}
		// 맨 앞 삽입
		else if (position == 0)
		{
			last = getCircularElement(pList, pList->currentElementCount - 1);
			new_node->pLink = pList->headerNode.pLink;
			pList->headerNode.pLink = new_node;
			last->pLink = new_node;
		}
		// 중간 삽입
		else
		{
			ptr = getCircularElement(pList, position);
			new_node->pLink = ptr->pLink;
			ptr->pLink = new_node;
		}
		pList->currentElementCount++;
		return (TRUE);
	}
	return (FALSE);
}

/*
연결리스트의 [i]번째 요소 제거
*/
int	removeCircularElement(LinkedList* pList, int position)
{
	ListNode	*ptr;
	ListNode	*tmp;
	ListNode	*last;

	if (position < 0)
		return (FALSE);
	ptr = pList->headerNode.pLink;
	if (position < pList->currentElementCount)
	{
		// 유일한 노드 제거
		if (pList->currentElementCount == 1)
		{
			pList->headerNode.pLink = NULL;
			ptr->pLink = NULL;
			free(ptr);
			ptr = NULL;
		}
		// 첫 번째 노드 제거
		else if (position == 0)
		{
			last = getCircularElement(pList, pList->currentElementCount - 1);
			pList->headerNode.pLink = ptr->pLink;
			ptr->pLink = NULL;
			free(ptr);
			ptr = NULL;
			last->pLink = pList->headerNode.pLink;
		}
		// 마지막 노드 제거
		else if (position == pList->currentElementCount - 1)
		{
			ptr = getCircularElement(pList, position - 1);
			free(ptr->pLink);
			ptr->pLink = pList->headerNode.pLink;
		}
		// 중간 노드 제거
		else
		{
			ptr = getCircularElement(pList, position - 1);
			tmp = ptr->pLink;
			ptr->pLink = tmp->pLink;
			tmp->pLink = NULL;
			free(tmp);
			tmp = NULL;
		}
		pList->currentElementCount--;
		return (TRUE);
	}
	return (FALSE);
}

/*
연결리스트의 [i]번째 요소 반환
*/
ListNode	*getCircularElement(LinkedList* pList, int position)
{
	ListNode	*ptr;

	ptr = pList->headerNode.pLink;
	while (position--)
	{
		ptr = ptr->pLink;
	}
	return (ptr);
}

/*
연결리스트의 모든 데이터 0 으로 초기화
*/
void	clearCircularList(LinkedList* pList)
{
	ListNode	*ptr;

	ptr = pList->headerNode.pLink;
	while (ptr)
	{
		ptr->data = 0;
		ptr = ptr->pLink;
	}
}

/*
연결리스트의 요소 개수 반환
*/
int	getCircularListLength(LinkedList* pList)
{
	int	len;

	len = pList->currentElementCount;
	return (len);
}

/*
연결리스트의 모든 요소 free
*/
void deleteCircularList(LinkedList** pList)
{
	ListNode	*ptr;
	ListNode	*tmp;
	int				i;
	
	i = (*pList)->currentElementCount;
	ptr = (*pList)->headerNode.pLink;
	while (i)
	{
		tmp = ptr->pLink;
		ptr->pLink = NULL;
		free(ptr);
		ptr = tmp;
		i--;
	}
	free(*pList);
	*pList = NULL;
}

/*
(Bonus) 연결리스트의 모든 데이터 출력
*/
void	displayCircularList(LinkedList *pList)
{
	ListNode	*ptr;
	int				i;

	if (!pList)
		return ;
	ptr = pList->headerNode.pLink;
	i = pList->currentElementCount;
	while (i)
	{
		printf("%i ", ptr->data);
		ptr = ptr->pLink;
		i--;
	}
	printf("\n");
}