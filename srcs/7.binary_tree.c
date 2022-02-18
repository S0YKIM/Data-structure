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
	// *(bintree->pRootNode) = rootNode;
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

void	insert(BinTreeNode *pParentNode, int data)
{
	if (!pParentNode)
		return ;
	if (data > pParentNode->data)
	{
		if (getRightChildNodeBT(pParentNode))
			insert(pParentNode->pRightChild, data);
		else
			insertRightChildNodeBT(pParentNode, data);
	}
	else if (data < pParentNode->data)
	{
		if (getLeftChildNodeBT(pParentNode))
			insert(pParentNode->pLeftChild, data);
		else
			insertLeftChildNodeBT(pParentNode, data);
	}
	else
		printf("ERROR : Node overlapped");
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

/*
0: 자식 노드 없음
1: 오른쪽 자식 노드만 있음
2: 왼쪽 자식 노드만 있음
3: 양쪽 자식 노드 전부 있음
*/
// static int	getChildNodeInfo(BinTreeNode* pNode)
// {
// 	int		cnt;

// 	if (!pNode)
// 		return (ERROR);
// 	cnt = 0;
// 	if (getRightChildNodeBT(pNode))
// 		cnt += 1;
// 	if (getLeftChildNodeBT(pNode))
// 		cnt += 2;
// 	return (cnt);
// }

// /*
// (오른쪽 자식 노드를 전달한 후에) 가장 값이 작은 노드 반환
// */
// static BinTreeNode	*getMinimumNode(BinTreeNode *pRightChild)
// {
// 	BinTreeNode *currNode;

// 	currNode = pRightChild;
// 	while (currNode->pLeftChild)
// 		currNode = currNode->pLeftChild;
// 	return (currNode);
// }

// /*
// 오른쪽 자식 노드의 가장 작은 값을 successor 로 채택
// */
// static void	deleteBinTreeNode(BinTreeNode** pNode)
// {
// 	BinTreeNode	*tmp;

// 	if (!pNode)
// 		return ;
// 	tmp = *pNode;

// 	switch (getChildNodeInfo(*pNode))
// 	{
// 		case 0 :
// 			free(*pNode);
// 			*pNode = NULL;
// 			break ;
// 		case 1 :
// 			*pNode = (*pNode)->pRightChild;
// 			free(tmp);
// 			tmp = NULL;
// 			break ;
// 		case 2 :
// 			*pNode = (*pNode)->pLeftChild;
// 			free(tmp);
// 			tmp = NULL;
// 			break ;
// 		case 3 :
// 			*pNode = getMinimumNode((*pNode)->pRightChild);
// 			free(tmp);
// 			tmp = NULL;
// 			break ;
// 	}
// }
// /*
//  * data를 가진 node를 찾아서 삭제(순회 방식: 전위 순회)
// */

// void		delete(BinTree *pBinTree, int data)
// {
// 	// data 탐색
// 	deleteBinTreeNode();
// 	return ;
// }

/*
후위 순회를 통해 모든 노드 free, 전체 트리도 free
*/
static void	deleteBinTreeNodeByPostorder(BinTreeNode *node)
{
	if (!node)
		return ;
	deleteBinTreeNodeByPostorder(node->pLeftChild);
	deleteBinTreeNodeByPostorder(node->pRightChild);
	free(node);
}

void		deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree || !pBinTree->pRootNode)
		return ;
	deleteBinTreeNodeByPostorder(pBinTree->pRootNode);
	free(pBinTree);
}
