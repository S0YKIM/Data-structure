# include "data_structure.h"

void	test_polynomial()
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