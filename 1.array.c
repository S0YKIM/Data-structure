typedef struct ArrayListNodeType
{
  int data;
} ArrayListNode;

typedef struct ArrayListType
{
  int maxElementCount;		// 최대 원소 개수 (예: 10개)
  int currentElementCount;	// 현재 원소 개수 (예: add -> +1   remove -> -1)
  ArrayListNode *pElement;	// 원소 저장을 위한 배열 포인터 (예: malloc(sizeof(ArrayListNode) * 10))
} ArrayList;


#include "data_structure.h"

/*
ArrayList를 생성하고 maxElementCount만큼 ArrayListNode를 할당하여 리턴
*/
ArrayList* createArrayList(int maxElementCount)
{
    ArrayList *array;

    array = (ArrayList *)malloc(sizeof(ArrayList));
    if (!array)
        return (NULL);
    array->maxElementCount = maxElementCount;
    array->currentElementCount = 0;
    array->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    if (!array->pElement)
        return (NULL);
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

/*
배열의 원소 추가
예: 네 번째 인덱스에 5 추가
0 1 2 3 x x // 0 1 2 x 3 x // 0 1 2 5 3 x // currentElementCount + 1
*/
int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
    if ((position <= pList->currentElementCount) && !(isArrayListFull(pList)))
    {
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

/*
배열의 원소 삭제
예: 맨 앞의 인덱스 0 제거
0 1 2 3 // 1 1 2 3 // 1 2 2 3 // 1 2 3 3 // 1 2 3 0 // currentElementCount - 1
*/

int removeALElement(ArrayList* pList, int position)
{
    if (position < pList->currentElementCount)
    {
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
    if (position < pList->currentElementCount)
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
