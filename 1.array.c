/*
배열 구현하기

배열에 넣기
배열에 빼기
오버플로우 처리
*/

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


#include "data_structure.h"

/*
ArrayList를 생성하고 maxElementCount만큼 ArrayListNode를 할당하여 리턴
*/
ArrayList* createArrayList(int maxElementCount)
{
    ArrayList *array;

    array = (ArrayList *)malloc(sizeof(ArrayList));
    array->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    return (array);
}

/*
ArrayList 안에 pElement 메모리 해제
ArrayList 메모리 해제
*/
void deleteArrayList(ArrayList* pList)
{
    free(pList->pElement);
    free(pList);
}

/*
Array가 maxElementCount만큼 다 찼는지 확인
*/
int isArrayListFull(ArrayList* pList)
{
    if (pList->currentElementCount == pList->maxElementCount)
        return (TRUE);
    return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
    if ((position <= pList->currentElementCount) && !(isArrayListFull(pList)))
    {
		// element.data 0 1 2 // 3 0 1 2
		// 0 1 2 2 3// 0 1 5 2 3
        for (int i = pList->currentElementCount; i > position; i--)
        {
            pList->pElement[i].data = pList->pElement[i-1].data;
        }
    	pList->pElement[position].data = element.data;
        pList->currentElementCount++;
        return (TRUE);
    }
    return (FALSE);
}

int removeALElement(ArrayList* pList, int position)
{
    if (position < pList->currentElementCount)
    {
		// 0 1 2 3 에서 0 제거 // 1 1 2 3 // 1 2 2 3 // 1 2 3 3 // 1 2 3 0 // currentElementCount - 1
        for (int i = position; i < pList->currentElementCount - 1; i++)
        {
            pList->pElement[i].data = pList->pElement[i+1].data;
        }
        pList->pElement[pList->currentElementCount - 1].data = 0;
        pList->currentElementCount--;
        return (TRUE);
    }
    return (FALSE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{

}

/*
pList 원소 출력
*/
void displayArrayList(ArrayList* pList)
{

}

/*
pList 원소 초기화
*/
void clearArrayList(ArrayList* pList)
{

}

int getArrayListLength(ArrayList* pList)
{

}
