#include "data_structure.h"

/*
연결리스트 생성
*/
LinkedList	*createLinkedList()
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
int	addLLElement(LinkedList* pList, int position, ListNode element)
{	
	ListNode	*new_node;
	ListNode	*ptr;

	if (position < 0)
		return (FALSE);

	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (!(new_node))
		return (FALSE);
	*new_node = element;
	ptr = pList->headerNode.pLink;

	if (position <= pList->currentElementCount)
	{
		// 맨 앞 삽입
		if (position == 0)
		{
			new_node->pLink = pList->headerNode.pLink;
			pList->headerNode.pLink = new_node;
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
int	removeLLElement(LinkedList* pList, int position)
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
			while (--position)
			{
				ptr = ptr->pLink;
			}
			free(ptr->pLink);
			ptr->pLink = NULL;
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
		pList->currentElementCount--;
		return (TRUE);
	}
	return (FALSE);
}

/*
연결리스트의 [i]번째 요소 반환
*/
ListNode	*getLLElement(LinkedList* pList, int position)
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
void	clearLinkedList(LinkedList* pList)
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
int	getLinkedListLength(LinkedList* pList)
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
void	displayLinkedList(LinkedList *pList)
{
	ListNode	*ptr;

	if (!pList)
		return ;
	ptr = pList->headerNode.pLink;
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
int	iterateLinkedList(LinkedList *pList)
{
	ListNode	*ptr;
	int			cnt;

	if (!pList)
		return (-1);
	cnt = 0;
	ptr = pList->headerNode.pLink;
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
void	reverseLinkedList(LinkedList* pList)
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

/*
(Bonus) 다항식 연결 리스트 만들기
*/
int	addPolyElement(LinkedList* pList, ListNode element)
{
	ListNode	*ptr;
	int			position;

	if (!pList)
		return (FALSE);
	ptr = pList->headerNode.pLink;
	position = 0;
	while (ptr)
	{
		if (element.degree > ptr->degree)
			break ;
		position++;
		ptr = ptr->pLink;
	}
	return (addLLElement(pList, position, element));
}

/*
(Bonus) 다항식 연결 리스트 출력
*/
void	displayPolyList(LinkedList *pList)
{
	ListNode	*ptr;

	if (!pList)
		return ;
	ptr = pList->headerNode.pLink;
	while (ptr)
	{
		printf("%.1f", ptr->coef);
		if (ptr->degree)
			printf("x^%i", ptr->degree);
		ptr = ptr->pLink;
		if (ptr)
			printf(" + ");
	}
	printf("\n");
}

/*
(Bonus) 두 개의 다항식 연결 리스트 더하기
*/
LinkedList	*addPolyLists(LinkedList *list1, LinkedList *list2)
{
	LinkedList	*new_list;
	ListNode	element;
	ListNode	*ptr1;
	ListNode	*ptr2;

	if (!list1 || !list2)
		return (NULL);

	// A 와 B 다항식을 더한 결과를 담을 새로운 연결 리스트
	new_list = (LinkedList *)malloc(sizeof(LinkedList));
	if (!new_list)
		return (NULL);
	
	// A 다항식 연결리스트 포인터
	ptr1 = list1->headerNode.pLink;

	// B 다항식 연결리스트 포인터
	ptr2 = list2->headerNode.pLink;
	
	// A 와 B 현재 항의 차수를 비교하여 새로운 연결리스트에 노드 추가해주기
	while (ptr1 && ptr2)
	{
		if (ptr1->degree > ptr2->degree)
		{
			element = *ptr1;
			ptr1 = ptr1->pLink;
		}
		else if (ptr1->degree == ptr2->degree)
		{
			element = *ptr1;
			element.coef += ptr2->coef;
			ptr1 = ptr1->pLink;
			ptr2 = ptr2->pLink;
		}
		else
		{
			element = *ptr2;
			ptr2 = ptr2->pLink;
		}
		addLLElement(new_list, new_list->currentElementCount, element);
	}

	// A 와 B 둘 중 하나가 탐색이 끝난 경우 나머지 남은 노드들을 새로운 연결리스트에 붙여주기
	while (ptr1)
	{
		element = *ptr1;
		addLLElement(new_list, new_list->currentElementCount, element);
		ptr1 = ptr1->pLink;
	}
	while (ptr2)
	{
		element = *ptr2;
		addLLElement(new_list, new_list->currentElementCount, element);
		ptr2 = ptr2->pLink;
	}
	return (new_list);
}