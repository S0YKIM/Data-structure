#include "data_structure.h"

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
		case 1 :
			test_linked_list();
			break ;
		case 2 :
			test_circular_list();
			//test_polynomial();
			break ;
		case 3 :
			test_stack_array();
			test_stack_linkedlist();
			break ;
		case 4 :
			test_maze();
			break ;
		default :
			break ;
	}

	// 2.circular_linked_list


	// 2. double_linked_list


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

	system("leaks data_structure");

	return (0);
}
