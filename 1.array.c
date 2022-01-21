/*
배열 구현하기

배열에 넣기
배열에 빼기
오버플로우 처리
*/

#include "data_structure.h"
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList* arr;

	arr = (ArrayList *)malloc(sizeof(ArrayList) * 1);
	arr->currentElementCount = 0;
	arr->maxElementCount = maxElementCount;
	arr->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
}

// 모든 노드 free
void deleteArrayList(ArrayList* pList)
{
	ArrayList* ptr;
	ArrayList* tmp;

	ptr = pList;
	while (ptr)
	{
		tmp = ptr->pElement;
	}
}

// Array가 maxElementCount만큼 다 찼는지 확인
int isArrayListFull(ArrayList* pList)
{
	if (pList->currentElementCount >= pList->maxElementCount)
		return TRUE;
	else
		return FALSE;
}


int addALElement(ArrayList* pList, int position, ArrayListNode element)
{

}


int removeALElement(ArrayList* pList, int position)
{

}


ArrayListNode* getALElement(ArrayList* pList, int position)
{

}


void displayArrayList(ArrayList* pList)
{

}


void clearArrayList(ArrayList* pList)
{

}


int getArrayListLength(ArrayList* pList)
{

}
