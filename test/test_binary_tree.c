#include "data_structure.h"

void	test_binary_tree()
{
	BinTree 	*tree;
	BinTreeNode	rootNode;

	rootNode.data = 10;
	rootNode.visited = 0;
	rootNode.pLeftChild = NULL;
	rootNode.pRightChild = NULL;

	tree = makeBinTree(rootNode);
	insert(tree->pRootNode, 5);
	insert(tree->pRootNode, 15);
	//preorderTraversalBinTree(tree->pRootNode);
	levelOrderTraversalBinTree(tree->pRootNode);
	deleteBinTree(tree);
	return ;
}