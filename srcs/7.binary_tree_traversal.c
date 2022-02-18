/*
이진 트리 순회
*/

#include "data_structure.h"

/*
전위 순회: V L R
*/
void	preorderTraversalBinTree(BinTreeNode *node)
{
	if (!node)
		return ;
	printf("data: %i ", node->data);
	preorderTraversalBinTree(node->pLeftChild);
	preorderTraversalBinTree(node->pRightChild);
}

/*
중위 순회: L V R
*/
void	inorderTraversalBinTree(BinTreeNode *node)
{
	if (!node)
		return ;
	preorderTraversalBinTree(node->pLeftChild);
	printf("data: %i ", node->data);
	preorderTraversalBinTree(node->pRightChild);
}

/*
후위 순회: L R V
*/
void	postorderTraversalBinTree(BinTreeNode *node)
{
	if (!node)
		return ;
	preorderTraversalBinTree(node->pLeftChild);
	preorderTraversalBinTree(node->pRightChild);
	printf("data: %i ", node->data);
}

/*
레벨 순회: BFS
*/
void	levelOrderTraversalBinTree(BinTreeNode *root)
{
	t_LOQ		*queue;
	t_LOQNode	*frontNode;
	t_LOQNode	tmp;

	queue = createLOQ();
	if (!queue)
		return ;
	tmp.treeNode = *root;
	enqueueLOQ(queue, tmp);
	while (!isLOQEmpty(queue))
	{
		frontNode = dequeueLOQ(queue);
		printf("%i ", frontNode->treeNode.data);
		if (getLeftChildNodeBT(&frontNode->treeNode))
		{
			tmp.treeNode = *(getLeftChildNodeBT(&frontNode->treeNode));
			enqueueLOQ(queue, tmp);
		}
		if (getRightChildNodeBT(&frontNode->treeNode))
		{
			tmp.treeNode = *(getRightChildNodeBT(&frontNode->treeNode));
			enqueueLOQ(queue, tmp);
		}
		free(frontNode);
		frontNode = NULL;
	}
	free(queue);
	queue = NULL;
}