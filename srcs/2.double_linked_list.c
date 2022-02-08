#include "data_structure.h"

/*
연결리스트 생성
*/
DoublyList	*createDoublyList()
{
		DoublyList* lst;

		lst = (DoublyList*)malloc(sizeof(DoublyList));
		if (!lst)
				return (NULL);
		lst->currentElementCount = 0;
		lst->headerNode.data = 0;
		lst->headerNode.pLLink = NULL;
		lst->headerNode.pRLink = NULL;
		return (lst);
}

/*
연결 리스트의 요소 [i]번째에 추가
*/
int	addDLElement(DoublyList* pList, int position, DoublyListNode element)
{	
	DoublyListNode	*new_node;
	DoublyListNode	*ptr;
	DoublyListNode	*last;

	if (position < 0)
		return (FALSE);

	new_node = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (!(new_node))
		return (FALSE);
	*new_node = element;
	ptr = pList->headerNode.pRLink;

	if (position <= pList->currentElementCount)
	{
		// 처음 노드 추가
		if (pList->currentElementCount == 0)
		{
			new_node->pLLink = new_node;
			new_node->pRLink = new_node;
			pList->headerNode.pRLink = new_node;
		}
		// 맨 앞 삽입
		else if (position == 0)
		{
			last = getDLElement(pList, pList->currentElementCount - 1);
			new_node->pLLink = last;
			new_node->pRLink = pList->headerNode.pRLink;
			pList->headerNode.pRLink->pLLink = new_node;
			last->pRLink = new_node;
			pList->headerNode.pRLink = new_node;
		}
		// 중간 삽입
		else
		{
			ptr = getDLElement(pList, position - 1);
			new_node->pLLink = ptr;
			new_node->pRLink = ptr->pRLink;
			new_node->pRLink->pLLink = new_node;
			ptr->pRLink = new_node;
		}
		pList->currentElementCount++;
		return (TRUE);
	}
	return (FALSE);
}

/*
연결리스트의 [i]번째 요소 제거
*/
int	removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*ptr;
	DoublyListNode	*tmp;
	DoublyListNode	*last;

	if (position < 0)
		return (FALSE);
	ptr = pList->headerNode.pRLink;
	if (position < pList->currentElementCount)
	{
		// 유일한 노드 제거
		if (pList->currentElementCount == 1)
		{
			pList->headerNode.pRLink = NULL;
			free(ptr);
			ptr = NULL;
		}
		// 첫 번째 노드 제거
		else if (position == 0)
		{
			last = getDLElement(pList, pList->currentElementCount - 1);
			ptr->pRLink->pLLink = last;
			last->pRLink = ptr->pRLink;
			pList->headerNode.pRLink = ptr->pRLink;
			free(ptr);
			ptr = NULL;
		}
		// 중간이나 마지막 노드 제거
		else
		{
			ptr = getDLElement(pList, position - 1);
			tmp = ptr->pRLink;
			ptr->pRLink = tmp->pRLink;
			tmp->pLLink = ptr;
			tmp->pRLink = NULL;
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
DoublyListNode	*getDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*ptr;

	ptr = pList->headerNode.pRLink;
	while (position--)
	{
		ptr = ptr->pRLink;
	}
	return (ptr);
}

/*
연결리스트의 모든 데이터 0 으로 초기화
*/
void	clearDoublyList(DoublyList* pList)
{
	DoublyListNode	*ptr;
	int				i;

	ptr = pList->headerNode.pRLink;
	i = pList->currentElementCount;
	while (i)
	{
		ptr->data = 0;
		ptr = ptr->pRLink;
		i--;
	}
}

/*
연결리스트의 요소 개수 반환
*/
int	getDoublyListLength(DoublyList* pList)
{
	int	len;

	len = pList->currentElementCount;
	return (len);
}

/*
연결리스트의 모든 요소 free
*/
void deleteDoublyList(DoublyList** pList)
{
	DoublyListNode	*ptr;
	DoublyListNode	*tmp;
	int				i;
	
	i = (*pList)->currentElementCount;
	ptr = (*pList)->headerNode.pRLink;
	while (i)
	{
		tmp = ptr->pRLink;
		ptr->pRLink = NULL;
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
void	displayDoublyList(DoublyList *pList)
{
	DoublyListNode	*ptr;
	int				i;

	if (!pList)
		return ;
	ptr = pList->headerNode.pRLink;
	i = pList->currentElementCount;
	while (i)
	{
		printf("%i ", ptr->data);
		ptr = ptr->pRLink;
		i--;
	}
	printf("\n");
}