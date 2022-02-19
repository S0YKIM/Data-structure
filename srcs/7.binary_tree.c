/*
이진 트리
*/

#include "data_structure.h"

BinTree		*makeBinTree(BinTreeNode rootNode)
{
	BinTree	*bintree;
	BinTreeNode *newNode;

	bintree = (BinTree *)calloc(1, sizeof(BinTree));
	if (!bintree)
		return NULL;
	newNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	newNode->data = rootNode.data;
	bintree->pRootNode = newNode;
	return (bintree);
}

BinTreeNode	*getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return NULL;
	return (pBinTree->pRootNode);
}

/*
	1) data가 parentnode->data보다 크면 : 
		1-1) rightchildnode != NULL
			rightchildnode를 새 parentnode로 재귀
		1-2) rightchildnode == NULL
			insertRightChildNodeBT();
	2) data가 parentnode->Data보다 작으면
		2-1) leftchildnode != NULL
			leftchildnode를 새 parentnode로 재귀
		2-2) leftchildnode == NULL
			insertLeftChildNode();
	3) 같으면 에러 출력
*/

static void	insertLeftChildNodeBT(BinTreeNode* pParentNode, int data)
{
	BinTreeNode	*newnode;

	newnode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (!newnode)
		return ;
	newnode->data = data;
	pParentNode->pLeftChild = newnode;
}

static void	insertRightChildNodeBT(BinTreeNode* pParentNode, int data)
{
	BinTreeNode	*newnode;

	newnode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (!newnode)
		return ;
	newnode->data = data;
	pParentNode->pRightChild = newnode;
}


BinTreeNode	*getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pLeftChild);
}

BinTreeNode	*getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pRightChild);
}

void	insertBinTreeNode(BinTreeNode *pParentNode, int data)
{
	if (!pParentNode)
		return ;
	if (data > pParentNode->data)
	{
		if (getRightChildNodeBT(pParentNode))
			insertBinTreeNode(pParentNode->pRightChild, data);
		else
			insertRightChildNodeBT(pParentNode, data);
	}
	else if (data < pParentNode->data)
	{
		if (getLeftChildNodeBT(pParentNode))
			insertBinTreeNode(pParentNode->pLeftChild, data);
		else
			insertLeftChildNodeBT(pParentNode, data);
	}
	else
		printf("ERROR : Node overlapped\n");
}

/*
0: 자식 노드 없음
1: 오른쪽 자식 노드만 있음
2: 왼쪽 자식 노드만 있음
3: 양쪽 자식 노드 전부 있음
*/
static int	getChildNodeInfo(BinTreeNode* pNode)
{
	int		cnt;

	if (!pNode)
		return (ERROR);
	cnt = 0;
	if (getRightChildNodeBT(pNode))
		cnt += 1;
	if (getLeftChildNodeBT(pNode))
		cnt += 2;
	return (cnt);
}

/*
(오른쪽 자식 노드를 전달한 후에) 해당 서브 트리에서 가장 값이 작은 노드 반환
successor 를 가리키던 부모 노드의 포인터를 successor 의 오른쪽 자식을 가리키도록 변경
*/
static BinTreeNode	*getSwapNode(BinTreeNode *pRightChild)
{
	BinTreeNode	*parentNode;
	BinTreeNode *swapNode;

	parentNode = pRightChild;
	if (!parentNode->pLeftChild)
		return (parentNode);
	while (parentNode->pLeftChild)
	{
		swapNode = parentNode->pLeftChild;
		if (!swapNode->pLeftChild)
		{
			parentNode->pLeftChild = swapNode->pRightChild;
			return (swapNode);
		}
		parentNode = parentNode->pLeftChild;
	}
	return (NULL);
}

/*
노드를 삭제하고 그 자리를 successor 로 대체 
*/
static BinTreeNode	*replaceDeleteNodetoSuccessor(BinTreeNode** pNode)
{
	BinTreeNode	*tmp;
	BinTreeNode	*successor;

	if (!pNode)
		return NULL;
	tmp = *pNode;

	switch (getChildNodeInfo(*pNode))
	{
		case 0 :
			free(*pNode);
			*pNode = NULL;
			return NULL;
			break ;
		case 1 :
			*pNode = (*pNode)->pRightChild;
			free(tmp);
			tmp = NULL;
			return NULL;
			break ;
		case 2 :
			*pNode = (*pNode)->pLeftChild;
			free(tmp);
			tmp = NULL;
			return NULL;
			break ;
		case 3 :
			*pNode = getSwapNode((*pNode)->pRightChild);
			successor = *pNode;
			(*pNode)->pLeftChild = tmp->pLeftChild;
			if (successor != tmp->pRightChild)
				(*pNode)->pRightChild = tmp->pRightChild;
			free(tmp);
			tmp = NULL;
			return (successor);
			break ;
		default :
			return NULL;
			break ;
	}
}
/*
data를 가진 node를 찾아서 삭제(순회 방식: 전위 순회)
전위 : Tree복제
중위 : 값을 오름차순이나 내림차순으로 탐색(?)
후위 : 트리 삭제
-> 레벨 순회 선택
*/

/*
삭제할 노드의 부모 노드를 반환
*/
static BinTreeNode	*getParentNodeOfDeleteData(BinTreeNode *node, int data)
{
	BinTreeNode *temp;

	if (!node)
		return (NULL);

	// 삭제할 노드가 root 노드인 경우
	if (data == node->data)
		return (node);
	// 삭제할 노드가 왼쪽 자식인 경우
	if (node->pLeftChild)
	{
		if (data == node->pLeftChild->data)
			return (node);
	}
	// 삭제할 노드가 오른쪽 자식인 경우
	if (node->pRightChild)
	{
		if (data == node->pRightChild->data)
			return (node);
	}

	temp = getParentNodeOfDeleteData(node->pLeftChild, data);
	if (temp)		
		return (temp);

	temp = getParentNodeOfDeleteData(node->pRightChild, data);
	if (temp)
		return (temp);

	return (NULL);
}


/*
해당 data 를 가진 노드를 삭제, 삭제한 자리는 successor 로 대체
*/
void	deleteBinTreeNode(BinTree *pBinTree, int data)
{
	BinTreeNode	*parentNode;
	BinTreeNode	*successor;

	parentNode = getParentNodeOfDeleteData(pBinTree->pRootNode, data);

	// root 노드를 삭제하는 경우
	if (parentNode->data == data)
	{
		successor = replaceDeleteNodetoSuccessor(&parentNode);
		pBinTree->pRootNode = successor;
		return ;
	}
	// 부모 노드의 왼쪽 자식이 삭제할 노드인 경우
	if (parentNode->pLeftChild)
	{
		if (parentNode->pLeftChild->data == data)
		{
			replaceDeleteNodetoSuccessor(&(parentNode->pLeftChild));
			return ;
		}
	}
	// 부모 노드의 오른쪽 자식이 삭제할 노드인 경우
	if (parentNode->pRightChild)
	{
		if (parentNode->pRightChild->data == data)
		{
			replaceDeleteNodetoSuccessor(&(parentNode->pRightChild));
			return ;
		}
	}
	return ;
}

/*
후위 순회를 통해 모든 노드 free
*/
static void	deleteBinTreeNodeByPostorder(BinTreeNode *node)
{
	if (!node)
		return ;
	deleteBinTreeNodeByPostorder(node->pLeftChild);
	deleteBinTreeNodeByPostorder(node->pRightChild);
	free(node);
}

/*
후위 순회를 통해 모든 노드 free, 전체 트리도 free
*/
void		deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree || !pBinTree->pRootNode)
		return ;
	deleteBinTreeNodeByPostorder(pBinTree->pRootNode);
	free(pBinTree);
}
