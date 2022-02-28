/*
연결리스트로 구현한 그래프
*/

#include "data_structure.h"

/*
무방향 그래프 생성
*/
LinkedGraph	*createLinkedGraph(int maxVertexCount)
{
	LinkedGraph	*myGraph;
	
	myGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	if (!myGraph)
		return (NULL);
	myGraph->pVertex = (int *)calloc(1, sizeof(int) * maxVertexCount);
	if (!myGraph->pVertex)
		return (NULL);
	myGraph->ppAdjEdge = (LinkedList **)calloc(1, sizeof(LinkedList *) * maxVertexCount);
	if (!myGraph->ppAdjEdge)
		return (NULL);
	for (int i = 0; i < maxVertexCount; i++)
	{
		myGraph->ppAdjEdge[i] = (LinkedList *)calloc(1, sizeof(LinkedList) * maxVertexCount);
		if (!myGraph->ppAdjEdge[i])
			return (NULL);
	}
	myGraph->maxVertexCount = maxVertexCount;
	myGraph->currentVertexCount = 0;
	myGraph->currentEdgeCount = 0;
	myGraph->graphType = GRAPH_UNDIRECTED;
	return (myGraph);
}

/*
방향 그래프 생성
*/
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph	*myGraph;
	
	myGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	if (!myGraph)
		return (NULL);
	myGraph->pVertex = (int *)calloc(1, sizeof(int) * maxVertexCount);
	if (!myGraph->pVertex)
		return (NULL);
	myGraph->ppAdjEdge = (LinkedList **)calloc(1, sizeof(LinkedList *) * maxVertexCount);
	if (!myGraph->ppAdjEdge)
		return (NULL);
	for (int i = 0; i < maxVertexCount; i++)
	{
		myGraph->ppAdjEdge[i] = (LinkedList *)calloc(1, sizeof(LinkedList) * maxVertexCount);
		if (!myGraph->ppAdjEdge[i])
			return (NULL);
	}
	myGraph->maxVertexCount = maxVertexCount;
	myGraph->currentVertexCount = 0;
	myGraph->currentEdgeCount = 0;
	myGraph->graphType = GRAPH_DIRECTED;
	return (myGraph);
}

/*
그래프 공백 여부 판단
*/
int isEmptyLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

/*
해당 노드의 유효성 점검
*/
static int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (vertexID < 0 || vertexID > pGraph->maxVertexCount - 1)
		return (FALSE);
	return (TRUE);
}

/*
노드 추가
*/
int addVertexLG(LinkedGraph* pGraph, int vertexID)
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
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	ListNode	temp;

	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (pGraph->pVertex[fromVertexID] == NOT_USED || !checkVertexValid(pGraph, fromVertexID))
		return (print_error_message("Invalid from vertex ID."));
	if (pGraph->pVertex[toVertexID] == NOT_USED || !checkVertexValid(pGraph, toVertexID))
		return (print_error_message("Invalid to vertex ID."));
	if (fromVertexID == toVertexID)
		return (print_error_message("Duplicated vertex ID."));
	
	temp.data = toVertexID;
	temp.weight = 1;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, temp);
	pGraph->currentEdgeCount++;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		temp.data = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, temp);
		pGraph->currentEdgeCount++;
	}
	return (TRUE);
}

/*
가중치 간선 추가
*/
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode	temp;

	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (pGraph->pVertex[fromVertexID] == NOT_USED || !checkVertexValid(pGraph, fromVertexID))
		return (print_error_message("Invalid from vertex ID."));
	if (pGraph->pVertex[toVertexID] == NOT_USED || !checkVertexValid(pGraph, toVertexID))
		return (print_error_message("Invalid to vertex ID."));
	if (fromVertexID == toVertexID)
		return (print_error_message("Duplicated vertex ID."));
	
	temp.data = toVertexID;
	temp.weight = weight;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, temp);
	pGraph->currentEdgeCount++;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		temp.data = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, temp);
		pGraph->currentEdgeCount++;
	}
	return (TRUE);
}

/*
해당 vertex ID 가진 노드 위치 반환
*/
int getGraphNodePosition(LinkedList *pList, int targetVertexID)
{
	ListNode	*ptr;
	int			i;

	ptr = pList->headerNode.pLink;
	i = 0;
	while (ptr)
	{
		if (targetVertexID == ptr->data)
			return (i);
		ptr = ptr->pLink;
		i++;
	}
	return (ERROR);
}

/*
간선 제거
*/
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int	position;

	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (pGraph->pVertex[fromVertexID] == NOT_USED || !checkVertexValid(pGraph, fromVertexID))
		return (print_error_message("Invalid from vertex ID."));
	if (pGraph->pVertex[toVertexID] == NOT_USED || !checkVertexValid(pGraph, toVertexID))
		return (print_error_message("Invalid to vertex ID."));
	if (fromVertexID == toVertexID)
		return (print_error_message("Duplicated vertex ID."));
	position = getGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	if (!removeLLElement(pGraph->ppAdjEdge[fromVertexID], position))
		return (ERROR);
	pGraph->currentEdgeCount--;	
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		position = getGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID);
		if (!removeLLElement(pGraph->ppAdjEdge[toVertexID], position))
			return (ERROR);
		pGraph->currentEdgeCount--;
	}
	return (TRUE);
}

/*
노드 제거 시 부속한 간선 모두 제거
*/
static int	deleteEveryEdge(LinkedList *pList)
{
	ListNode	*ptr;
	ListNode	*tmp;
	int			cnt;

	cnt = pList->currentElementCount;
	ptr = pList->headerNode.pLink;
	while (ptr)
	{
		tmp = ptr->pLink;
		ptr->pLink = NULL;
		free(ptr);
		ptr = tmp;
	}
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
	return (cnt);
}

/*
노드 제거
*/
int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	int	position;

	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (pGraph->pVertex[vertexID] == NOT_USED || !checkVertexValid(pGraph, vertexID))
		return (FALSE);
	pGraph->currentEdgeCount -= deleteEveryEdge(pGraph->ppAdjEdge[vertexID]);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		position = getGraphNodePosition(pGraph->ppAdjEdge[i], vertexID);
		if (removeLLElement(pGraph->ppAdjEdge[i], position))
			pGraph->currentEdgeCount--;
	}
	pGraph->currentVertexCount--;
	pGraph->pVertex[vertexID] = NOT_USED;
	return (TRUE);
}

/*
간선 개수 반환
*/
int	getEdgeCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentEdgeCount);
}

/*
노드 개수 반환
*/
int getVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount);
}

/*
최대 노드 개수 반환
*/
int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->maxVertexCount);
}

/*
그래프 종류 반환
*/
int getGraphTypeLG(LinkedGraph* pGraph)
{
	return (pGraph->graphType);
}

/*
그래프 정보 출력
*/
int displayLinkedGraph(LinkedGraph* pGraph)
{
	ListNode	*ptr;

	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (isEmptyLG(pGraph))
		return (print_error_message("Empty graph"));

	printf("Max vertex count: %d\n", pGraph->maxVertexCount);
	printf("Current vertex count: %d\n", pGraph->currentVertexCount);
	printf("Current edge count: %d\n", pGraph->currentEdgeCount);
	if (getGraphTypeLG(pGraph) == 1)
		printf("Graph type: Undirected graph\n");
	else
		printf("Graph type: Directed graph\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("[%d] : ", i);

		if (pGraph->pVertex[i] == NOT_USED)
		{
			printf("NOT USED\n");
			continue ;
		}
		if (!pGraph->ppAdjEdge[i])
			return (ERROR);
		ptr = pGraph->ppAdjEdge[i]->headerNode.pLink;
		while (ptr)
		{
			printf("(%d, %d) ", i, ptr->data);
			ptr = ptr->pLink;
		}
		printf("\n");
	}
	return (TRUE);		
}

/*
그래프 삭제
*/
int	deleteLinkedGraph(LinkedGraph** pGraph)
{
	if (!pGraph || !(*pGraph))
		return (print_error_message("Invalid graph."));
	for (int i = 0; i < (*pGraph)->maxVertexCount; i++)
		removeVertexLG(*pGraph, i);
	free((*pGraph)->pVertex);
	free(*pGraph);
	*pGraph = NULL;
	return (TRUE);
}
