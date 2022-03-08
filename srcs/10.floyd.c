/*
그래프에서 모든 정점으로부터 모든 정점까지의 최단 경로 구하기
*/

#include "data_structure.h"

ArrayGraph	*floyd(ArrayGraph *graph)
{
	int			infinity = 100000;
	ArrayGraph	*path;

	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		for (int j = 0; j < graph->maxVertexCount; j++)
		{
			if (i == j)
				continue;
			if (graph->ppAdjEdge[i][j] == 0)
				graph->ppAdjEdge[i][j] = infinity;
		}
	}
	path = createArrayGraph(graph->maxVertexCount);
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		addVertexAG(path, i);
		for (int j = 0; j < graph->maxVertexCount; j++)
			path->ppAdjEdge[i][j] = 0;
	}

	for (int c = 0; c < graph->maxVertexCount; c++)
	{
		for (int start = 0; start < graph->maxVertexCount; start++)
		{
			for (int end = 0; end < graph->maxVertexCount; end++)
			{
				if (start == end || c == start || c == end)
					continue ;
				if (graph->ppAdjEdge[start][c] + graph->ppAdjEdge[c][end] < graph->ppAdjEdge[start][end])
				{
					path->ppAdjEdge[start][end] = c;
					graph->ppAdjEdge[start][end] = graph->ppAdjEdge[start][c] + graph->ppAdjEdge[c][end];
				}
			}
		}
	}
	return (path);
}

static void	print_passed_path(ArrayGraph *path, int start, int end)
{
	if (path->ppAdjEdge[start][end] != 0)
	{
		print_passed_path(path, start, path->ppAdjEdge[start][end]);
		printf("%i -> ", path->ppAdjEdge[start][end]);
		print_passed_path(path, path->ppAdjEdge[start][end], end);
	}
}

void	print_minimum_path(ArrayGraph *path, int start, int end)
{
	if (!path)
		return ;
	printf("%i -> ", start);
	print_passed_path(path, start, end);
	printf("%i\n", end);
}
