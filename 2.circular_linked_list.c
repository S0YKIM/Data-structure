#include "data_structure.h"

/*
연결리스트 생성
*/
LinkedList* createCircularList()
{
    LinkedList* lst;

    lst = (LinkedList*)malloc(sizeof(LinkedList));
    if (!lst)
        return (NULL);
    lst->currentElementCount = 0;
    lst->headerNode.data = 0;
    lst->headerNode.pLink = 0;
    return (lst);
}

/*
연결 리스트의 요소 [i]번째에 추가
*/
int addCircularElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*new_node;
	ListNode	*ptr;

	if (position < 0)
		return (FALSE);

	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (!(new_node))
		return (FALSE);
	new_node->data = element.data;
	ptr = pList->headerNode.pLink;

	if (position <= pList->currentElementCount)
	{
		// 맨 앞 삽입
		if (position == 0)
		{
			new_node->pLink = pList->headerNode.pLink;
			pList->headerNode.pLink = new_node;
		}
		// 맨 뒤 삽입
		else if (position == pList->currentElementCount)
		{
			while (position--)
			{
				ptr = ptr->pLink;
			}
			ptr = new_node;
			new_node->pLink = NULL;
		}
		// 중간 삽입
		else
		{
			while (position--)
			{
				ptr = ptr->pLink;
			}
			new_node->pLink = ptr;
			ptr = new_node;
		}
		pList->currentElementCount++;
		return (TRUE);
	}
	return (FALSE);
}

/*
연결리스트의 [i]번째 요소 제거
*/
int removeCircularElement(LinkedList* pList, int position)
{
	ListNode	*ptr;
	ListNode	*next;
	ListNode	*tmp;

	if (position < 0)
		return (FALSE);
	ptr = pList->headerNode.pLink;
	if (position < pList->currentElementCount)
	{
		// 첫 번째 노드 제거
		if (position == 0)
		{
			pList->headerNode.pLink = ptr->pLink;
			free(ptr->pLink);
			free(ptr);
			ptr = NULL;
		}
		// 마지막 노드 제거
		else if (position == pList->currentElementCount - 1)
		{
			while (position--)
			{
				ptr = ptr->pLink;
			}
			ptr->pLink = NULL;
			free(ptr);
			ptr = NULL;
		}
		// 중간 노드 제거
		else
		{
			while (position--)
			{
				ptr = ptr->pLink;
			}
			next = ptr->pLink;
			tmp = ptr;
			ptr = next;
			tmp->pLink = NULL;
			free(tmp);
			tmp = NULL;
		}
		return (TRUE);
	}
	return (FALSE);
}

/*
연결리스트의 [i]번째 요소 반환
*/
ListNode* getCircularElement(LinkedList* pList, int position)
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
void clearCircularList(LinkedList* pList)
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
int getCircularListLength(LinkedList* pList)
{
	int	len;

	len = pList->currentElementCount;
	return (len);
}

/*
연결리스트의 모든 요소 free
*/
void deleteList(LinkedList* pList)
{
	ListNode	*ptr;
	ListNode	*tmp;
	
	ptr = pList->headerNode.pLink;
	while (ptr)
	{
		tmp = ptr->pLink;
		ptr->pLink = NULL;
		free(ptr);
		ptr = tmp;
	}
	free(pList);
	pList = NULL;
}
