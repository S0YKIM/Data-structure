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

typedef struct singleNodeType
{
	int data;
	struct singleNodeType* next;
} singleNode;

typedef struct doubleNodeType
{
	int data;
	struct doubleNodeType* prev;
	struct doubleNodeType* next;
} doubleNode;



LinkedList* createLinkedList()
{
    LinkedList* address;

    address = (LinkedList*)malloc(sizeof(LinkedList));
    if (!address)
        return (NULL);
    address->currentElementCount = 0;
    address->headerNode = 0;
    return (address);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{

}

int removeLLElement(LinkedList* pList, int position)
{

}

ListNode* getLLElement(LinkedList* pList, int position)
{

}

void clearLinkedList(LinkedList* pList)
{

}

int getLinkedListLength(LinkedList* pList)
{

}

void deleteLinkedList(LinkedList* pList)
{

}