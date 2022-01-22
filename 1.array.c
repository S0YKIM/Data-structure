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
    pList->pElement = 0;
    free(pList);
    pList = 0;
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
	if (position < 0)
		return (FALSE);
	if (position < pList->maxElementCount && !isArrayListFull(pList))
	{
		for (int i = pList->currentElementCount; i > position; i--)
		{
			pList->pElement[i].data = pList->pElement[i - 1].data;
		}
		pList->pElement[position].data = element.data;
		pList->currentElementCount++;
		return TRUE;
	}
	else
		return FALSE;
}

/*
배열의 원소 삭제
예: 맨 앞의 인덱스 0 제거
0 1 2 3 // 1 1 2 3 // 1 2 2 3 // 1 2 3 3 // 1 2 3 0 // currentElementCount - 1
*/

int removeALElement(ArrayList* pList, int position)
{
    if (pList->currentElementCount == 0)
        return (FALSE);
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

/*
특정 인덱스(position)에 해당하는 원소의 주소 구하기
*/

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    ArrayListNode*  address;

    if (position < pList->currentElementCount)
    {
        address = ArrayListNode + position * sizeof(ArrayListNode);
        return (address);
    }
    return (NULL);
}

/*
pList 원소 출력
*/
void displayArrayList(ArrayList* pList)
{
    if (pList->currentElementCount == 0)
    {
        printf("Max element count: %i\n", pList->maxElementCount);
        printf("No data added yet.\n");
        return ;
    }
    printf("Max element count: %i\n", pList->maxElementCount);
    printf("Current element count: %i\n", pList->currentElementCount);
    for (i = 0; i < pList->currentElementCount; i++)
    {
        printf("Element[%i]: %i\n", i, pList->pElement[i]);
    }
}

/*
pList 모든 원소 데이터 0으로 초기화
*/
void clearArrayList(ArrayList* pList)
{
    for (int i = 0; i < pList->currentElementCount; i++)
    {
        pList->pElement[i] = 0;
    }
    pList->maxElementCount = 0;
    pList->currentElementCount = 0;
}

/*
배열 리스트의 길이: 최대 원소 개수
*/

int getArrayListLength(ArrayList* pList)
{
    int result;

    result = pList->maxElementCount;
    return (result);
}
