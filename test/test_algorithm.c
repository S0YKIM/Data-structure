#include "data_structure.h"

void	test_floyd()
{
	ArrayGraph	*myGraph;
	ArrayGraph	*path;

	myGraph = createArrayGraph(6);
	addVertexAG(myGraph, 0);
	addVertexAG(myGraph, 1);
	addVertexAG(myGraph, 2);
	addVertexAG(myGraph, 3);
	addVertexAG(myGraph, 4);
	addVertexAG(myGraph, 5);

	addEdgewithWeightAG(myGraph, 0, 1, 1);
	addEdgewithWeightAG(myGraph, 0, 2, 4);
	addEdgewithWeightAG(myGraph, 1, 2, 2);
	addEdgewithWeightAG(myGraph, 2, 3, 1);
	addEdgewithWeightAG(myGraph, 3, 4, 8);
	addEdgewithWeightAG(myGraph, 3, 5, 3);
	addEdgewithWeightAG(myGraph, 4, 5, 4);

	path = floyd(myGraph);
	displayArrayGraph(myGraph);
	displayArrayGraph(path);
	print_minimum_path(path, 0, 4);
	//deleteArrayGraph(&myGraph);
	//deleteArrayGraph(&path);
}
