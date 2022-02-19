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
	// insertBinTreeNode(tree->pRootNode, 5);
	// insertBinTreeNode(tree->pRootNode, 21);
	// insertBinTreeNode(tree->pRootNode, 3);
	// insertBinTreeNode(tree->pRootNode, 7);
	// insertBinTreeNode(tree->pRootNode, 12);
	// insertBinTreeNode(tree->pRootNode, 24);
	// insertBinTreeNode(tree->pRootNode, 4);
	// insertBinTreeNode(tree->pRootNode, 6);
	// insertBinTreeNode(tree->pRootNode, 14);
	// insertBinTreeNode(tree->pRootNode, 11);
	// insertBinTreeNode(tree->pRootNode, 22);
	// insertBinTreeNode(tree->pRootNode, 23);
	// insertBinTreeNode(tree->pRootNode, 25);

	insertBinTreeNode(tree->pRootNode, 1);
	insertBinTreeNode(tree->pRootNode, 2);
	insertBinTreeNode(tree->pRootNode, 3);
	insertBinTreeNode(tree->pRootNode, 4);
	insertBinTreeNode(tree->pRootNode, 5);
	insertBinTreeNode(tree->pRootNode, 6);
	insertBinTreeNode(tree->pRootNode, 7);
	insertBinTreeNode(tree->pRootNode, 8);
	insertBinTreeNode(tree->pRootNode, 9);
	insertBinTreeNode(tree->pRootNode, 10);
	insertBinTreeNode(tree->pRootNode, 11);
	insertBinTreeNode(tree->pRootNode, 12);
	insertBinTreeNode(tree->pRootNode, 13);

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