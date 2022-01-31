# include "data_structure.h"

void	test_linked_list()
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
