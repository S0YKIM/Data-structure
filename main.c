#include "data_structure.h"

int	main(int argc, char **argv)
{
	int			number;
	LinkedList	*list;
	ListNode	node;

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
		list = createLinkedList();
		if (!list)
			return (0);
		
		// Adding nodes from 100 to 900
		for (int i = 100; i < 1000; i += 100)
		{
			node.data = i;
			addLLElement(list, 0, node);
		}
		displayLinkedList(list);

		// Removing the second node
		removeLLElement(list, 1);
		displayLinkedList(list);

		// Deleting the whole linked list
		deleteLinkedList(&list);
		displayLinkedList(list);
		return (0);
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
