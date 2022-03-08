/*
그래프에서 모든 정점으로부터 모든 정점까지의 최단 경로 구하기
*/

#include "data_structure.h"

ArrayGraph	*floyd(ArrayGraph *graph)
{
	int			infinity = 100000;
	ArrayGraph	*path;

	// 인접하지 않은 노드까지의 경로 길이 무한대로 초기화
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

	// 경유지를 저장하는 이차원 배열 초기화
	path = createArrayGraph(graph->maxVertexCount);
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		addVertexAG(path, i);
		for (int j = 0; j < graph->maxVertexCount; j++)
			path->ppAdjEdge[i][j] = 0;
	}

	// c: 경유지, start: 시작지, end: 도착지
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

// start ~ end 사이의 최단 경로 출력
void	print_minimum_path(ArrayGraph *path, int start, int end)
{
	if (!path)
		return ;
	printf("%i -> ", start);
	print_passed_path(path, start, end);
	printf("%i\n", end);
}
