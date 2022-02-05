#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef struct StackNodeType
{
	char data;
	int	h;
	int	w;
	int	direction;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 연결 리스트 스택의 노드 개수
	StackNode* pTopElement;		// 스택의 탑 노드 주소
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack** pStack);
// int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

/* Custom */
void	displayLinkedStack(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif