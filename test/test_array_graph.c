#include "data_structure.h"

void	test_array_graph()
{
	ArrayGraph	*myGraph;

	myGraph = createArrayGraph(5);
	addVertexAG(myGraph, 0);
	addVertexAG(myGraph, 1);
	addVertexAG(myGraph, 2);
	addVertexAG(myGraph, 3);
	addVertexAG(myGraph, 4);
	
	// 0->1->2->3->4
	addEdgeAG(myGraph, 0, 1);
	addEdgeAG(myGraph, 1, 2);
	addEdgeAG(myGraph, 2, 3);
	addEdgeAG(myGraph, 3, 4);
	
	removeVertexAG(myGraph, 2);
	
	deleteArrayGraph(&myGraph);

	displayArrayGraph(myGraph);
}