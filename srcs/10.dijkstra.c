/*
다익스트라

출발 노드 설정
방문하지 않은 노드중 가장 비용이 적은 노드 선택
최소 비용 갱신


*/

#include "data_structure.h"

void	dijkstra(LinkedGraph *graph, int start)
{
	int			distance[graph->maxVertexCount];
	int			infinity = 100000;
	// LinkedList	**path;
	ListNode	*ptr;
	int			tmp;
	int			i;

	if (!graph)
		return ;
	// path = (LinkedList **)malloc(sizeof(LinkedList *) * graph->maxVertexCount);
	// for (int i = 0; i < graph->maxVertexCount; i++)
	//	path[i] = (LinkedList *)malloc(sizeof(LinkedList));
	for (int i = 0; i < graph->maxVertexCount; i++)
		distance[i] = infinity;
	distance[start] = 0;
	i = start;
	while (!isEmptyLG(graph))
	{
		ptr = &graph->ppAdjEdge[i]->headerNode;
		while (ptr)
		{
			if (distance[i] + ptr->weight < distance[ptr->data])
			{
				distance[ptr->data] = ptr->weight + distance[i];
				//path[i] = 
				//addLLElement(path[ptr->data], 0, path[i]);
			}
			else
			{
				distance[ptr->data] = ptr->weight;
				//addLLElement(path[i], 0, *ptr);
			}
			ptr = ptr->pLink;
		}
		tmp = i;
		i = graph->ppAdjEdge[i]->headerNode.pLink->data;
		for (int i = 0; i < graph->maxVertexCount; i++)
		{
			printf("%i ", distance[i]);
			printf("\n");
		}
		removeVertexLG(graph, tmp);
	}
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		printf("%i ", distance[i]);
	}
	printf("\n");
}

void	print_dijkstra(int *distance, int cnt)
{
	if (!distance)
		return ;
	for (int i = 0; i < cnt; i++)
	{
		printf("%i ", distance[i]);
		printf("\n");
	}
}
