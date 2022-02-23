/*
AVL Tree
*/

#include "data_structure.h"

AVLTree		*makeAVLTree(AVLTreeNode rootNode)
{
	AVLTree	*bintree;
	AVLTreeNode *newNode;

	bintree = (AVLTree *)calloc(1, sizeof(AVLTree));
	if (!bintree)
		return NULL;
	newNode = (AVLTreeNode *)calloc(1, sizeof(AVLTreeNode));
	newNode->data = rootNode.data;
	bintree->pRootNode = newNode;
	return (bintree);
}

AVLTreeNode	*getRootNodeAVL(AVLTree* pAVLTree)
{
	if (!pAVLTree)
		return NULL;
	return (pAVLTree->pRootNode);
}

/*
	1) data가 parentnode->data보다 크면 : 
		1-1) rightchildnode != NULL
			rightchildnode를 새 parentnode로 재귀
		1-2) rightchildnode == NULL
			insertRightChildNodeAVL();
	2) data가 parentnode->Data보다 작으면
		2-1) leftchildnode != NULL
			leftchildnode를 새 parentnode로 재귀
		2-2) leftchildnode == NULL
			insertLeftChildNode();
	3) 같으면 에러 출력
*/

static void	insertLeftChildNodeAVL(AVLTreeNode* pParentNode, int data)
{
	AVLTreeNode	*newnode;

	newnode = (AVLTreeNode *)calloc(1, sizeof(AVLTreeNode));
	if (!newnode)
		return ;
	newnode->data = data;
	pParentNode->pLeftChild = newnode;
}

static void	insertRightChildNodeAVL(AVLTreeNode* pParentNode, int data)
{
	AVLTreeNode	*newnode;

	newnode = (AVLTreeNode *)calloc(1, sizeof(AVLTreeNode));
	if (!newnode)
		return ;
	newnode->data = data;
	pParentNode->pRightChild = newnode;
}


AVLTreeNode	*getLeftChildNodeAVL(AVLTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pLeftChild);
}

AVLTreeNode	*getRightChildNodeAVL(AVLTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pRightChild);
}

static int	getHeight(AVLTreeNode *pParentNode)
{
	int leftChildHeight;
	int rightChildHeight;
	if (pParentNode == NULL)
		return (-1);
	leftChildHeight = getHeight(pParentNode->pLeftChild);
	rightChildHeight = getHeight(pParentNode->pRightChild);
	if (leftChildHeight > rightChildHeight)
		return (leftChildHeight + 1);
	return (rightChildHeight + 1);
}

static int	getBalanceFactor(AVLTreeNode *pParentNode)
{
	int	leftChildHeight;
	int	rightChildHeight;

	leftChildHeight = getHeight(pParentNode->pLeftChild);
	rightChildHeight = getHeight(pParentNode->pRightChild);
	return (leftChildHeight - rightChildHeight);
}

static AVLTreeNode	*rotateLL(AVLTreeNode *pPivotNode)
{
	AVLTreeNode	*tmp;

	tmp = pPivotNode->pLeftChild;
	pPivotNode->pLeftChild = tmp->pRightChild;
	tmp->pRightChild = pPivotNode;
	return (tmp);
}

static AVLTreeNode	*rotateRR(AVLTreeNode *pPivotNode)
{
	AVLTreeNode	*tmp;

	tmp = pPivotNode->pRightChild;
	pPivotNode->pRightChild = tmp->pLeftChild;
	tmp->pLeftChild = pPivotNode;
	return (tmp);
}

static AVLTreeNode	*balanceAVLTree(AVLTreeNode *pPivotNode)
{
	int	parentBF;
	int	leftChildBF;
	int rightChildBF;

	parentBF = getBalanceFactor(pPivotNode);
	leftChildBF = getBalanceFactor(pPivotNode->pLeftChild);
	rightChildBF = getBalanceFactor(pPivotNode->pRightChild);

	if (parentBF == 2)
	{
		// LL
		if (leftChildBF == 1)
			pPivotNode = rotateLL(pPivotNode);
		// LR
		else 
		{
			pPivotNode->pLeftChild = rotateRR(pPivotNode->pLeftChild);
			pPivotNode = rotateLL(pPivotNode);
		}
	}
	else if (parent == -2)
	{
		// RR
		if (rightChildBF == -1)
			pPivotNode = rotateRR(pPivotNode);
		// RL
		else
		{
			pPivotNode->pRightChild = rotateLL(pPivotNode->pRightChild);
			pPivotNode = rotateRR(pPivotNode);
		}
	}
	return (pPivotNode);
}

AVLTreeNode	*insertAVLTreeNode(AVLTreeNode *pParentNode, int data)
{
	if (!pParentNode)
		return ;
	if (data > pParentNode->data)
	{
		if (getRightChildNodeAVL(pParentNode))
			parentNode->pRightChild = insertAVLTreeNode(pParentNode->pRightChild, data);
		else
			insertRightChildNodeAVL(pParentNode, data);
	}
	else if (data < pParentNode->data)
	{
		if (getLeftChildNodeAVL(pParentNode))
			parentNode->pLeftChild = insertAVLTreeNode(pParentNode->pLeftChild, data);
		else
			insertLeftChildNodeAVL(pParentNode, data);
	}
	else
		printf("ERROR : Node overlapped\n");
	pParentNode = balanceAVLTree(pParentNode);
	return (pParentNode);
}

/*
0: 자식 노드 없음
1: 오른쪽 자식 노드만 있음
2: 왼쪽 자식 노드만 있음
3: 양쪽 자식 노드 전부 있음
*/
// static int	getChildNodeInfo(AVLTreeNode* pNode)
// {
// 	int		cnt;

// 	if (!pNode)
// 		return (ERROR);
// 	cnt = 0;
// 	if (getRightChildNodeAVL(pNode))
// 		cnt += 1;
// 	if (getLeftChildNodeAVL(pNode))
// 		cnt += 2;
// 	return (cnt);
// }

/*
(오른쪽 자식 노드를 전달한 후에) 해당 서브 트리에서 가장 값이 작은 노드 반환
successor 를 가리키던 부모 노드의 포인터를 successor 의 오른쪽 자식을 가리키도록 변경
*/
static AVLTreeNode	*getSuccessor(AVLTreeNode *pRightChild)
{
	AVLTreeNode	*parentNode;
	AVLTreeNode *successorNode;

	parentNode = pRightChild;
	if (!parentNode->pLeftChild)
		return (parentNode);
	while (parentNode->pLeftChild)
	{
		successorNode = parentNode->pLeftChild;
		if (!successorNode->pLeftChild)
		{
			parentNode->pLeftChild = successorNode->pRightChild;
			return (successorNode);
		}
		parentNode = parentNode->pLeftChild;
	}
	return (NULL);
}

AVLTreeNode	*deleteAVLTreeNode(AVLTree *pAVLTree, AVLTreeNode *pParentNode, int key)
{
	AVLTreeNode	*successor;

	if (key < pParentNode->data)
		deleteAVLTreeNode(pAVLTree, pParentNode->pLeftChild, key);
	else if (key > pParentNode->data)
		deleteAVLTreeNode(pAVLTree, pParentNode->pRightChild, key);
	else
	{
		if (pParentNode->pRightChild)
		{
			successor = getSuccessor(pParentNode->pRightChild);

		}
		else
			return (pParentNode->pLeftChild);
		
	}
	
}

/*
노드를 삭제하고 그 자리를 successor 로 대체 
*/
// static AVLTreeNode	*replaceDeleteNodetoSuccessor(AVLTreeNode** pNode)
// {
// 	AVLTreeNode	*tmp;
// 	AVLTreeNode	*successor;

// 	if (!pNode)
// 		return NULL;
// 	tmp = *pNode;

// 	switch (getChildNodeInfo(*pNode))
// 	{
// 		case 0 :
// 			free(*pNode);
// 			*pNode = NULL;
// 			return NULL;
// 			break ;
// 		case 1 :
// 			*pNode = (*pNode)->pRightChild;
// 			free(tmp);
// 			tmp = NULL;
// 			return NULL;
// 			break ;
// 		case 2 :
// 			*pNode = (*pNode)->pLeftChild;
// 			free(tmp);
// 			tmp = NULL;
// 			return NULL;
// 			break ;
// 		case 3 :
// 			*pNode = getSwapNode((*pNode)->pRightChild);
// 			successor = *pNode;
// 			(*pNode)->pLeftChild = tmp->pLeftChild;
// 			if (successor != tmp->pRightChild)
// 				(*pNode)->pRightChild = tmp->pRightChild;
// 			free(tmp);
// 			tmp = NULL;
// 			return (successor);
// 			break ;
// 		default :
// 			return NULL;
// 			break ;
// 	}
// }



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
// static AVLTreeNode	*getParentNodeOfDeleteData(AVLTreeNode *node, int data)
// {
// 	AVLTreeNode *temp;

// 	if (!node)
// 		return (NULL);

// 	// 삭제할 노드가 root 노드인 경우
// 	if (data == node->data)
// 		return (node);
// 	// 삭제할 노드가 왼쪽 자식인 경우
// 	if (node->pLeftChild)
// 	{
// 		if (data == node->pLeftChild->data)
// 			return (node);
// 	}
// 	// 삭제할 노드가 오른쪽 자식인 경우
// 	if (node->pRightChild)
// 	{
// 		if (data == node->pRightChild->data)
// 			return (node);
// 	}

// 	temp = getParentNodeOfDeleteData(node->pLeftChild, data);
// 	if (temp)
// 		return (temp);

// 	temp = getParentNodeOfDeleteData(node->pRightChild, data);
// 	if (temp)
// 		return (temp);

// 	return (NULL);
// }


// /*
// 해당 data 를 가진 노드를 삭제, 삭제한 자리는 successor 로 대체
// */
// void	deleteAVLTreeNode(AVLTree *pAVLTree, int data)
// {
// 	AVLTreeNode	*parentNode;
// 	AVLTreeNode	*successor;

// 	parentNode = getParentNodeOfDeleteData(pAVLTree->pRootNode, data);

// 	// root 노드를 삭제하는 경우
// 	if (parentNode->data == data)
// 	{
// 		successor = replaceDeleteNodetoSuccessor(&parentNode);
// 		pAVLTree->pRootNode = successor;
// 		return ;
// 	}
// 	// 부모 노드의 왼쪽 자식이 삭제할 노드인 경우
// 	if (parentNode->pLeftChild)
// 	{
// 		if (parentNode->pLeftChild->data == data)
// 		{
// 			replaceDeleteNodetoSuccessor(&(parentNode->pLeftChild));
// 			return ;
// 		}
// 	}
// 	// 부모 노드의 오른쪽 자식이 삭제할 노드인 경우
// 	if (parentNode->pRightChild)
// 	{
// 		if (parentNode->pRightChild->data == data)
// 		{
// 			replaceDeleteNodetoSuccessor(&(parentNode->pRightChild));
// 			return ;
// 		}
// 	}
// 	return ;
// }

/*
후위 순회를 통해 모든 노드 free
*/
static void	deleteAVLTreeNodeByPostorder(AVLTreeNode *node)
{
	if (!node)
		return ;
	deleteAVLTreeNodeByPostorder(node->pLeftChild);
	deleteAVLTreeNodeByPostorder(node->pRightChild);
	free(node);
}

/*
후위 순회를 통해 모든 노드 free, 전체 트리도 free
*/
void		deleteAVLTree(AVLTree* pAVLTree)
{
	if (!pAVLTree || !pAVLTree->pRootNode)
		return ;
	deleteAVLTreeNodeByPostorder(pAVLTree->pRootNode);
	free(pAVLTree);
}
