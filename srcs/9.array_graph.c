/*
배열로 그래프 구현하기
*/

#include "data_structure.h"

ArrayGraph	*createArrayGraph(int maxVertexCount)
{
	ArrayGraph	*myGraph;
	
	myGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (!myGraph)
		return (NULL);
	myGraph->pVertex = (int *)calloc(1, sizeof(int) * maxVertexCount);
	if (!myGraph->pVertex)
		return (NULL);
	myGraph->ppAdjEdge = (int **)calloc(1, sizeof(int *) * maxVertexCount);
	if (!myGraph->ppAdjEdge)
		return (NULL);
	for (int i = 0; i < maxVertexCount; i++)
	{
		myGraph->ppAdjEdge[i] = (int *)calloc(1, sizeof(int) * maxVertexCount);
		if (!myGraph->ppAdjEdge[i])
			return (NULL);
	}
	myGraph->maxVertexCount = maxVertexCount;
	myGraph->currentVertexCount = 0;
	myGraph->graphType = GRAPH_UNDIRECTED;
	return (myGraph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph	*myGraph;
	
	myGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (!myGraph)
		return (NULL);
	myGraph->pVertex = (int *)calloc(1, sizeof(int) * maxVertexCount);
	if (!myGraph->pVertex)
		return (NULL);
	myGraph->ppAdjEdge = (int **)calloc(1, sizeof(int *) * maxVertexCount);
	if (!myGraph->ppAdjEdge)
		return (NULL);
	for (int i = 0; i < maxVertexCount; i++)
	{
		myGraph->ppAdjEdge[i] = (int *)calloc(1, sizeof(int) * maxVertexCount);
		if (!myGraph->ppAdjEdge[i])
			return (NULL);
	}
	myGraph->maxVertexCount = maxVertexCount;
	myGraph->currentVertexCount = 0;
	myGraph->graphType = GRAPH_DIRECTED;
	return (myGraph);
}

int	print_error_message(char *msg)
{
	printf("%s\n", msg);
	return (ERROR);
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

// 해당 노드의 유효성 점검
static int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (vertexID < 0 || vertexID > pGraph->maxVertexCount - 1)
		return (FALSE);
	return (TRUE);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (!checkVertexValid(pGraph, vertexID))
		return (print_error_message("Invalid vertex ID."));
	if (pGraph->pVertex[vertexID] == USED)
		return (print_error_message("Already used vertex ID."));
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

/*
간선 추가
*/
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (pGraph->pVertex[fromVertexID] == NOT_USED || !checkVertexValid(pGraph, fromVertexID))
		return (print_error_message("Invalid from vertex ID."));
	if (pGraph->pVertex[toVertexID] == NOT_USED || !checkVertexValid(pGraph, toVertexID))
		return (print_error_message("Invalid to vertex ID."));
	if (fromVertexID == toVertexID)
		return (print_error_message("Duplicated vertex ID."));
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = USED;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = USED;
	return (TRUE);
}

// 0->0
/*
가중치 간선 추가
*/
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (pGraph->pVertex[fromVertexID] == NOT_USED || !checkVertexValid(pGraph, fromVertexID))
		return (print_error_message("Invalid from vertex ID."));
	if (pGraph->pVertex[toVertexID] == NOT_USED || !checkVertexValid(pGraph, toVertexID))
		return (print_error_message("Invalid to vertex ID."));
	if (fromVertexID == toVertexID)
		return (print_error_message("Duplicated vertex ID."));
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (TRUE);
}

// 간선 제거
int	removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (pGraph->pVertex[fromVertexID] == NOT_USED || !checkVertexValid(pGraph, fromVertexID))
		return (print_error_message("Invalid from vertex ID."));
	if (pGraph->pVertex[toVertexID] == NOT_USED || !checkVertexValid(pGraph, toVertexID))
		return (print_error_message("Invalid to vertex ID."));
	if (fromVertexID == toVertexID)
		return (print_error_message("Duplicated vertex ID."));
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = NOT_USED;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = NOT_USED;
	return (TRUE);
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (isEmptyAG(pGraph))
		return (print_error_message("Empty graph."));
	if (!checkVertexValid(pGraph, vertexID))
		return (print_error_message("Invalid vertex ID."));
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[vertexID][i] = NOT_USED;
		pGraph->ppAdjEdge[i][vertexID] = NOT_USED;
	}
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (TRUE);
}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph** pGraph)
{
	if (!pGraph || !(*pGraph))
		return ;
	free((*pGraph)->pVertex);
	for (int i = 0; i < (*pGraph)->maxVertexCount; i++)
		free((*pGraph)->ppAdjEdge[i]);
	free((*pGraph)->ppAdjEdge);
	free(*pGraph);
	*pGraph = NULL;
}

// 그래프 정보 출력
int displayArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (isEmptyAG(pGraph))
		return (print_error_message("Empty graph"));

	printf("  ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		printf("%d ", i);
	printf("\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("%d ", i);
		for(int j = 0; j < pGraph->maxVertexCount; j++)
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		printf("\n");
	}
	return (TRUE);
}
