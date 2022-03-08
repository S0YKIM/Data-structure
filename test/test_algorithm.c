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

	printf("------------- Original Graph -------------\n");
	displayArrayGraph(myGraph);
	printf("------------------------------------------\n");
	path = floyd(myGraph);
	printf("------------- Floyd-warshall -------------\n");
	displayArrayGraph(myGraph);
	printf("------------------------------------------\n");
	printf("---------------- All Paths ---------------\n");
	displayArrayGraph(path);
	printf("------------------------------------------\n");
	printf("------------- Shortest Path --------------\n");
	print_minimum_path(path, 0, 4);
	printf("------------------------------------------\n");
}

void	test_dijkstra()
{
	LinkedGraph	*myGraph;

	myGraph = createLinkedGraph(6);
	addVertexLG(myGraph, 0);
	addVertexLG(myGraph, 1);
	addVertexLG(myGraph, 2);
	addVertexLG(myGraph, 3);
	addVertexLG(myGraph, 4);
	addVertexLG(myGraph, 5);

	addEdgewithWeightLG(myGraph, 0, 1, 1);
	addEdgewithWeightLG(myGraph, 0, 2, 4);
	addEdgewithWeightLG(myGraph, 1, 2, 2);
	addEdgewithWeightLG(myGraph, 2, 3, 1);
	addEdgewithWeightLG(myGraph, 3, 4, 8);
	addEdgewithWeightLG(myGraph, 3, 5, 3);
	addEdgewithWeightLG(myGraph, 4, 5, 4);

	dijkstra(myGraph, 0);
	//deleteArrayGraph(&myGraph);
	//deleteArrayGraph(&path);
}