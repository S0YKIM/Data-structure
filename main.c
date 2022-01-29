#include "data_structure.h"

void	array_linked_list()
{
	LinkedList	*list;
	ListNode	node;

	list = createLinkedList();
	if (!list)
		return ;
	
	// Adding nodes from 100 to 900
	for (int i = 100; i < 200; i += 100)
	{
		node.data = i;
		addLLElement(list, 0, node);
	}
	displayLinkedList(list);

	// Reversing the whole linked list
	reverseLinkedList(list);
	displayLinkedList(list);
	// Removing the second node
	//removeLLElement(list, 1);
	//displayLinkedList(list);

	// Deleting the whole linked list
	//deleteLinkedList(&list);
	//displayLinkedList(list);
}

void	polynomial()
{
	LinkedList	*list1;
	LinkedList	*list2;
	ListNode	node;
	LinkedList	*new_list;

	// A 다항식 연결 리스트: 3x^6 + x^4 + 4x^2
	list1 = createLinkedList();
	if (!list1)
		return ;
	
	// x^4
	node.degree = 4;
	node.coef = 1;
	addPolyElement(list1, node);

	// 3x^6
	node.degree = 6;
	node.coef = 3;
	addPolyElement(list1, node);

	// 4x^2
	node.degree = 2;
	node.coef = 4;
	addPolyElement(list1, node);
	displayPolyList(list1);

	// B 다항식 연결 리스트: x^5 + 2x^4 + 3x^2 + 4
	list2 = createLinkedList();
	if (!list2)
		return ;
	
	// x^5
	node.degree = 5;
	node.coef = 1;
	addPolyElement(list2, node);

	// 2x^4
	node.degree = 4;
	node.coef = 2;
	addPolyElement(list2, node);

	// 3x^2
	node.degree = 2;
	node.coef = 3;
	addPolyElement(list2, node);

	// 4
	node.degree = 0;
	node.coef = 4;
	addPolyElement(list2, node);
	displayPolyList(list2);

	// A + B
	new_list = addPolyLists(list1, list2);
	displayPolyList(new_list);
}

int	main(int argc, char **argv)
{
	int	number;

	if (argc != 2)
	{
		printf("Two arguments needed.");
		return (0);
	}
	number = argv[1][0] - '0';

	switch (number)
	{
		// 1. array
		// 1.linked_list
		case 1 :
			array_linked_list();
			break ;
		case 2 :
			polynomial();
			break ;
		default :
			break ;		
	}
	// 2.circular_linked_list


	// 2. double_linked_list


	// 2. polynomial_addition


	// 2. reverse_linked_list


	// 3. stack array


	// 3. stack_linked_list


	// 4. maze


	// 5. circular queue


	// 5. deque


	// 5. queue


	// 6. queue_simulation


	// 7. binary_tree_traversal


	// 7. binary tree

	// 8. binary search tree


	// 8. heap


	// 9. linked_list_graph

	// 10.dijkstra

	// 10. floyd

	// 10. krusckal


	// 10. minimum spanning tree


	// 10. prim

	// 11. sort

	// 12. search



	return (0);
}
