# include "data_structure.h"

void	test_stack_array()
{
	ArrayStack		*stack;
	ArrayStackNode	element;
	ArrayStackNode	*result;

	stack = createArrayStack(3);
	element.data = 'a';
	pushAS(stack, element);
	element.data = 'b';
	pushAS(stack, element);
	element.data = 'c';
	pushAS(stack, element);
	element.data = 'd';
	pushAS(stack, element);
	displayArrayStack(stack);

	result = peekAS(stack);
	printf("peek: %c\n", result->data);

	result = popAS(stack);
	printf("pop: %c\n", result->data);
	result = popAS(stack);
	printf("pop: %c\n", result->data);
	result = popAS(stack);
	printf("pop: %c\n", result->data);
	result = popAS(stack);
	if (result)
		printf("pop: %c\n", result->data);
	displayArrayStack(stack);

	deleteArrayStack(&stack);
	displayArrayStack(stack);
}

void	test_stack_linkedlist()
{
	LinkedStack		*stack;
	StackNode		element;
	StackNode		*result;

	stack = createLinkedStack();
	element.data = 'a';
	pushLS(stack, element);
	element.data = 'b';
	pushLS(stack, element);
	element.data = 'c';
	pushLS(stack, element);
	displayLinkedStack(stack);

	result = peekLS(stack);
	printf("peek: %c\n", result->data);

	result = popLS(stack);
	printf("pop: %c\n", result->data);
	free(result);
	result = popLS(stack);
	printf("pop: %c\n", result->data);
	free(result);
	result = popLS(stack);
	printf("pop: %c\n", result->data);
	free(result);
	result = popLS(stack);
	if (result)
		printf("pop: %c\n", result->data);
	
	displayLinkedStack(stack);

	deleteLinkedStack(&stack);
	displayLinkedStack(stack);
}