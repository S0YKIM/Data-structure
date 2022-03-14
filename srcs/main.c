#include "data_structure.h"

int	main(int argc, char **argv)
{
	int	number;

	if (argc != 2)
	{
		printf("Two arguments needed.");
		return (0);
	}
	number = atoi(argv[1]);

	switch (number)
	{
		case 1 :
			test_linked_list();
			break ;
		case 2 :
			//test_circular_list();
			test_double_list();
			//test_polynomial();
			break ;
		case 3 :
			test_stack_array();
			test_stack_linkedlist();
			break ;
		case 4 :
			test_maze();
			break ;
		case 5 :
			//test_queue_stack();
			test_deque();
			break ;
		case 6 :
			test_queue_simulation();
			break ;
		case 7 :
			// test_binary_tree();
			test_avl_tree();
			break ;
		case 8 :
			//test_max_heap();
			test_min_heap();
			break ;
		case 9 :
			//test_array_graph();
			//test_linked_graph();
			test_graph_traversal();
			break ;
		case 10 :
			test_floyd();
			// test_dijkstra();
			break ;
		case 11 :
			//test_merge_sort();
			//test_quick_sort();
			test_insertion_sort();
			break ;
		default :
			break ;
	}

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
