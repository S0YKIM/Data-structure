#include "data_structure.h"

/*
연결리스트 생성
*/
LinkedList* createLinkedList()
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
int addLLElement(LinkedList* pList, int position, ListNode element)
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
			while (--position)
			{
				ptr = ptr->pLink;
			}
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
int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*ptr;
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
			ptr->pLink = NULL;
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
			while (--position)
			{
				ptr = ptr->pLink;
			}
			tmp = ptr->pLink;
			ptr->pLink = tmp->pLink;
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
ListNode* getLLElement(LinkedList* pList, int position)
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
void clearLinkedList(LinkedList* pList)
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
int getLinkedListLength(LinkedList* pList)
{
	int	len;

	len = pList->currentElementCount;
	return (len);
}

/*
연결리스트의 모든 요소 free
*/
void deleteLinkedList(LinkedList** pList)
{
	ListNode	*ptr;
	ListNode	*tmp;
	
	ptr = (*pList)->headerNode.pLink;
	while (ptr)
	{
		tmp = ptr->pLink;
		ptr->pLink = NULL;
		free(ptr);
		ptr = tmp;
	}
	free(*pList);
	*pList = NULL;
}

/*
(Bonus) 연결리스트의 모든 데이터 출력
*/
void displayLinkedList(LinkedList *list)
{
	ListNode	*ptr;

	if (!list)
		return ;
	ptr = list->headerNode.pLink;
	while (ptr)
	{
		printf("%i ", ptr->data);
		ptr = ptr->pLink;
	}
	printf("\n");
}

/*
(Bonus) 연결리스트의 노드 개수 반환
*/
int	iterateLinkedList(LinkedList *list)
{
	ListNode	*ptr;
	int			cnt;

	if (!list)
		return (-1);
	cnt = 0;
	ptr = list->headerNode.pLink;
	while (ptr)
	{
		cnt++;
		ptr = ptr->pLink;
	}
	return (cnt);
}

/*
(Bonus) 연결 리스트와 연결 리스트 잇기
*/

/*
(Bonus) 연결 리스트 역순 만들기
*/
void reverseLinkedList(LinkedList* pList)
{
	ListNode	*prev;
	ListNode	*current;
	ListNode	*next;

	if (!pList)
		return ;
	prev = NULL;
	current = pList->headerNode.pLink;

	for (int i = 0; i < pList->currentElementCount; i++)
	{
		next = current->pLink;
		current->pLink = prev;
		prev = current;
		current = next;
	}
	pList->headerNode.pLink = prev;
}