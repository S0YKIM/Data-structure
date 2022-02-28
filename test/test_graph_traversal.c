#include "data_structure.h"

void	test_graph_traversal()
{
	LinkedGraph	*myGraph;

	myGraph = createLinkedGraph(8);
	addVertexLG(myGraph, 0);
	addVertexLG(myGraph, 1);
	addVertexLG(myGraph, 2);
	addVertexLG(myGraph, 3);
	addVertexLG(myGraph, 4);
	addVertexLG(myGraph, 5);
	addVertexLG(myGraph, 6);
	addVertexLG(myGraph, 7);
	
	// 0-1-2-3-4-5-6-7
	addEdgeLG(myGraph, 0, 1);
	addEdgeLG(myGraph, 0, 2);
	addEdgeLG(myGraph, 2, 6);
	addEdgeLG(myGraph, 2, 5);
	
	addEdgeLG(myGraph, 1, 4);
	addEdgeLG(myGraph, 1, 3);
	addEdgeLG(myGraph, 3, 7);

	//graph_traversal_DFS(myGraph, 0);
	graph_traversal_BFS(myGraph, 0);

	deleteLinkedGraph(&myGraph);
}
