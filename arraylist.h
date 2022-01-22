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

ArrayList* createArrayList(int maxElementCount); // ArrayList malloc해주는 애
void deleteArrayList(ArrayList* pList); // pElement, ArrayList free 해주는 애
int isArrayListFull(ArrayList* pList); // maxElementCount == currentElementCount
int addALElement(ArrayList* pList, int position, ArrayListNode element); // data 넣어주기 isArrayListFull 사용해서 남아있으면 ADD하고 자료 뒤로 밀기
int removeALElement(ArrayList* pList, int position); // 지우고, 앞으로 밀기
ArrayListNode* getALElement(ArrayList* pList, int position); // 특정 포지션의 ListNode return -> pList + (position * sizeof(ArrayListNode))
void displayArrayList(ArrayList* pList); // array에 있는 것 다 출력
void clearArrayList(ArrayList* pList); // delete 와 clear의 차이점 => current->0 data->0 잠깐 보류
int getArrayListLength(ArrayList* pList); // pList length -> return currentElementCount

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
