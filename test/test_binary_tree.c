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
	// insert(tree->pRootNode, 5);
	// insert(tree->pRootNode, 21);
	// insert(tree->pRootNode, 3);
	// insert(tree->pRootNode, 7);
	// insert(tree->pRootNode, 12);
	// insert(tree->pRootNode, 24);
	// insert(tree->pRootNode, 4);
	// insert(tree->pRootNode, 6);
	// insert(tree->pRootNode, 14);
	// insert(tree->pRootNode, 11);
	// insert(tree->pRootNode, 22);
	// insert(tree->pRootNode, 23);
	// insert(tree->pRootNode, 25);

	insert(tree->pRootNode, 1);
	insert(tree->pRootNode, 2);
	insert(tree->pRootNode, 3);
	insert(tree->pRootNode, 4);
	insert(tree->pRootNode, 5);
	insert(tree->pRootNode, 6);
	insert(tree->pRootNode, 7);
	insert(tree->pRootNode, 8);
	insert(tree->pRootNode, 9);
	insert(tree->pRootNode, 10);
	insert(tree->pRootNode, 11);
	insert(tree->pRootNode, 12);
	insert(tree->pRootNode, 13);

	// printf("Root node : %d\n", tree->pRootNode->data);
	//preorderTraversalBinTree(tree->pRootNode);
	preorderTraversalBinTree(tree->pRootNode);
	printf("\n");
	deleteBinTreeNode(tree, 10);
	preorderTraversalBinTree(tree->pRootNode);
	printf("\n");
	printf("Root node : %d\n", tree->pRootNode->data);
	deleteBinTree(tree);
	return ;
}