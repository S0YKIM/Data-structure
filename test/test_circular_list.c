# include "data_structure.h"

void	test_circular_list()
{
	LinkedList	*list;
	ListNode	node;

	list = createCircularList();
	if (!list)
		return ;
	
	// Adding nodes from 100 to 900
	for (int i = 100; i < 1000; i += 100)
	{
		node.data = i;
		addCircularElement(list, 0, node);
	}
	displayCircularList(list);

	// Removing the second node
	removeCircularElement(list, 1);
	displayCircularList(list);

	// Deleting the whole linked list
	deleteCircularList(&list);
	displayCircularList(list);
}
