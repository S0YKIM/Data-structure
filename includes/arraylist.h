#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data; // 사실상 4 bytes
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;		// 최대 원소 개수 10
	int currentElementCount;	// 현재 원소 개수 add -> +1 remove -> -1 =>
	ArrayListNode *pElement;	// 원소 저장을 위한 1차원 배열 10 malloc(sizeof(ArrayListNode) * 10)
} ArrayList;

ArrayList* createArrayList(int maxElementCount); // ArrayList 에 malloc
void deleteArrayList(ArrayList* pList); // pElement, ArrayList 를 free
int isArrayListFull(ArrayList* pList); // maxElementCount == currentElementCount
int addALElement(ArrayList* pList, int position, ArrayListNode element); // data 넣어주기 isArrayListFull 사용해서 남아있으면 ADD하고 자료 뒤로 밀기
int removeALElement(ArrayList* pList, int position); // 지우고, 앞으로 밀기
ArrayListNode* getALElement(ArrayList* pList, int position); // 특정 포지션의 ListNode return -> ArrayListNode + (position * sizeof(ArrayListNode))
void displayArrayList(ArrayList* pList); // ArrayList 에 있는 모든 요소 출력
void clearArrayList(ArrayList* pList); // ArrayList 의 데이터를 0으로 초기화하되 free 는 하지 않음
int getArrayListLength(ArrayList* pList); // pList length -> return currentElementCount

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
