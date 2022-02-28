#include "data_structure.h"

/*
인접한 노드를 덱에 push
*/
void	getAdjacentNode(LinkedDeque *pDeque, LinkedGraph *pGraph, int target)
{
	ListNode	*ptr;
	DequeNode	node;

	ptr = pGraph->ppAdjEdge[target]->headerNode.pLink;
	while (ptr)
	{
		node.data = ptr->data;
		if (pGraph->pVertex[ptr->data] != VISITED)
		{
			insertRearLD(pDeque, node);
			pGraph->pVertex[ptr->data] = VISITED;
		}
		ptr = ptr->pLink;
	}
	return ;
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
깊이 우선 탐색(DFS)
*/
int	graph_traversal_DFS(LinkedGraph *pGraph, int index)
{
	LinkedDeque *myStack;
	DequeNode	node;
	DequeNode	*target;
	
	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (isEmptyLG(pGraph))
		return (print_error_message("Empty graph"));
	if (pGraph->pVertex[index] == NOT_USED || !checkVertexValid(pGraph, index))
		return (print_error_message("Invalid from vertex ID."));
	
	myStack = createLinkedDeque();
	node.data = index;
	insertRearLD(myStack, node);
	pGraph->pVertex[index] = VISITED;
	while (!isLinkedDequeEmpty(myStack))
	{
		target = deleteRearLD(myStack);
		printf("pop! %d ", target->data);
		getAdjacentNode(myStack, pGraph, target->data);
		free(target);
	}
	printf("\n");
	return (TRUE);
}

/*
너비 우선 탐색(BFS)
*/
int	graph_traversal_BFS(LinkedGraph *pGraph, int index)
{
	LinkedDeque *myQueue;
	DequeNode	node;
	DequeNode	*target;

	if (!pGraph)
		return (print_error_message("Invalid graph."));
	if (isEmptyLG(pGraph))
		return (print_error_message("Empty graph"));
	if (pGraph->pVertex[index] == NOT_USED || !checkVertexValid(pGraph, index))
		return (print_error_message("Invalid from vertex ID."));
	
	myQueue = createLinkedDeque();
	node.data = index;
	insertRearLD(myQueue, node);
	pGraph->pVertex[index] = VISITED;
	while (!isLinkedDequeEmpty(myQueue))
	{
		target = deleteFrontLD(myQueue);
		printf("pop! %d ", target->data);
		getAdjacentNode(myQueue, pGraph, target->data);
		free(target);
	}
	printf("\n");
	return (TRUE);
}
