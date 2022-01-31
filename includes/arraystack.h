#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

typedef struct ArrayStackNodeType {
	char data;
} ArrayStackNode;

typedef struct ArrayStackType {
	int maxElementCount;		// 최대 스택 노드 개수
	int currentElementCount;	// 현재 스택 노드 개수
	ArrayStackNode *pElement;	// 배열 스택의 첫 번째 노드 주소
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAS(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popAS(ArrayStack* pStack);
ArrayStackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack** pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

/* Custom */
void	displayArrayStack(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif