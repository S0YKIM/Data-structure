#include "data_structure.h"

void	test_linked_graph()
{
	LinkedGraph	*myGraph;

	myGraph = createLinkedGraph(5);
	addVertexLG(myGraph, 0);
	addVertexLG(myGraph, 1);
	addVertexLG(myGraph, 2);
	addVertexLG(myGraph, 3);
	addVertexLG(myGraph, 4);
	
	// 0->1->2->3->4
	addEdgeLG(myGraph, 0, 1);
	addEdgeLG(myGraph, 1, 2);
	addEdgeLG(myGraph, 2, 3);
	addEdgeLG(myGraph, 3, 4);
	
	removeVertexLG(myGraph, 2);

	// addVertexLG(myGraph, 2);
	// addEdgeLG(myGraph, 2, 4);
	
	// removeEdgeLG(myGraph, 0, 1);
	
	deleteLinkedGraph(&myGraph);

	displayLinkedGraph(myGraph);
}