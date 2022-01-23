/*

linked list 구현하기

1. node 생성
2. node 맨 앞 연결
3. node 중간 연결
4. node 맨 뒤 연결
5. node 처음 삭제
6. node 중간 삭제
7. node 마지막 삭제

*/

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
연결 리스트의 요소 추가
*/
int addLLElement(LinkedList* pList, int position, ListNode element)
{	
	ListNode	*new_node;
	ListNode	*ptr;
	ListNode	*tmp;

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
			*(new_node->pLink) = pList->headerNode;
			pList->headerNode = *new_node;
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
				tmp = ptr;
			}
			ptr = new_node;
			new_node->pLink = tmp;
		}
		pList->currentElementCount++;
		return (TRUE);
	}
	return (FALSE);
}

int removeLLElement(LinkedList* pList, int position)
{

}

/*
연결리스트의 [i]번째 요소 반환
*/
ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*ptr;

	ptr = pList->headerNode.pLink;
	while (--position)
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
	pList->headerNode.data = 0;
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
void deleteLinkedList(LinkedList* pList)
{
	ListNode	*ptr;
	ListNode	*tmp;
	
	ptr = pList->headerNode.pLink;
	while (ptr)
	{
		tmp = ptr->pLink;
		free(ptr);
		ptr = tmp;
	}
	free(pList);
	pList = NULL;
}
