#ifndef _CIRCULAR_LINKED_LIST_
# define _CIRCULAR_LINKED_LIST_

LinkedList* createCircularList();
int addCircularElement(LinkedList* pList, int position, ListNode element);
int removeCircularElement(LinkedList* pList, int position);
ListNode* getCircularElement(LinkedList* pList, int position);

void clearCircularList(LinkedList* pList);
int getCircularListLength(LinkedList* pList);
void deleteCircularList(LinkedList** pList);

/*커스텀 함수*/
void	displayCircularList(LinkedList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif