#ifndef _LINKEDLIST_
#define _LINKEDLIST_

/*
단방향 연결 리스트
*/
typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink; // 다음 노드의 주소
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList** pList);
void displayLinkedList(LinkedList *list);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
