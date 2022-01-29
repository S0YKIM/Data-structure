#ifndef _LINKEDLIST_
#define _LINKEDLIST_

/*
단방향 연결 리스트
*/
typedef struct ListNodeType
{
	int 	data;
	int		degree;
	float	coef;
	struct ListNodeType* pLink; // 다음 노드의 주소
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList	*createLinkedList();
int			addLLElement(LinkedList* pList, int position, ListNode element);
int			removeLLElement(LinkedList* pList, int position);
ListNode	*getLLElement(LinkedList* pList, int position);

void	clearLinkedList(LinkedList* pList);
int		getLinkedListLength(LinkedList* pList);
void	deleteLinkedList(LinkedList** pList);

/*
커스텀 함수
*/
void	displayLinkedList(LinkedList *list);
int		iterateLinkedList(LinkedList *list);
void	reverseLinkedList(LinkedList* pList);

/*
다항식의 덧셈 연결리스트
*/
int		addPolyElement(LinkedList* pList, ListNode element);
void	displayPolyList(LinkedList *list);
LinkedList	*addPolyLists(LinkedList *list1, LinkedList *list2);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
