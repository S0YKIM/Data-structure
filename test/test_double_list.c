# include "data_structure.h"

void	test_double_list()
{
	DoublyList	*list;
	DoublyListNode	node;

	list = createDoublyList();
	if (!list)
		return ;
	
	// Adding nodes from 100 to 900
	for (int i = 100; i < 1000; i += 100)
	{
		node.data = i;
		addDLElement(list, 0, node);
	}
	// Adding node into second place
	node.data = 1004;
	addDLElement(list, 1, node);
	displayDoublyList(list);

	// Removing the second node
	removeDLElement(list, 1);
	displayDoublyList(list);

	// Deleting the whole linked list
	deleteDoublyList(&list);
	displayDoublyList(list);
}
