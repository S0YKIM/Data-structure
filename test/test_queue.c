# include "data_structure.h"

void	test_queue()
{
	ArrayQueue		*myArray;
	ArrayQueueNode	*curr;
	ArrayQueueNode	node0 = {0};
	int max;
	int number = 0;
	int	pushNum = 0;
	
	printf("input maxsize: ");
	scanf("%d", &max);
	myArray = createArrayQueue(max);
	while(1)
	{
		printf("1 : Enqueue Arraynode\n2 : Dequeue Arraynode\n3 : Peek Arraynode\n4 : Display ArrayQueue\n5 : Delete ArrayQueue\n6 : is ArrayQueue Empty?\n7 : is ArrayQueue FUll?\n");
		printf(">> ");
		scanf(" %d", &number);
		switch (number)
		{
		case 1:
			printf("data: ");
			scanf("%d", &(node0.data));
			pushNum = enqueueAQ(myArray, node0);
			if (pushNum)
				printf("enqueued data : %d\n", myArray->pElement[myArray->rear].data);
			break;
		case 2:
			if (!isArrayQueueEmpty(myArray))
			{
				curr = dequeueAQ(myArray);
				printf("dequeued data : %d\n", curr->data);
				free(curr);
			}
			break;
		case 3:
			curr = peekAQ(myArray);
			if (curr)
				printf("Front's data : %d\n", curr->data);
			break;
		case 4:
			displayArrayQueue(myArray);
			break;
		case 5:
			deleteArrayQueue(&myArray);
			break;
		case 6:
			if (isArrayQueueEmpty(myArray))
				printf("arrayQueue is empty\n");
			break;
		case 7:
			if (isArrayQueueFull(myArray))
				printf("arrayQueue is full\n");
			break;
		default:
			break;
		}
		if (number == 5)
			break;
	}
}