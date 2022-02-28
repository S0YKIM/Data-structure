#include "data_structure.h"

void	test_avl_tree()
{
	AVLTree 	*tree;
	AVLTreeNode	rootNode;

	rootNode.data = 10;
	rootNode.visited = 0;
	rootNode.pLeftChild = NULL;
	rootNode.pRightChild = NULL;

	tree = makeAVLTree(rootNode);
	// insertAVLTreeNode(tree->pRootNode, 5);
	// insertAVLTreeNode(tree->pRootNode, 21);
	// insertAVLTreeNode(tree->pRootNode, 3);
	// insertAVLTreeNode(tree->pRootNode, 7);
	// insertAVLTreeNode(tree->pRootNode, 12);
	// insertAVLTreeNode(tree->pRootNode, 24);
	// insertAVLTreeNode(tree->pRootNode, 4);
	// insertAVLTreeNode(tree->pRootNode, 6);
	// insertAVLTreeNode(tree->pRootNode, 14);
	// insertAVLTreeNode(tree->pRootNode, 11);
	// insertAVLTreeNode(tree->pRootNode, 22);
	// insertAVLTreeNode(tree->pRootNode, 23);
	// insertAVLTreeNode(tree->pRootNode, 25);

	insertAVLTreeNode(tree->pRootNode, 1);
	insertAVLTreeNode(tree->pRootNode, 2);
	insertAVLTreeNode(tree->pRootNode, 3);
	insertAVLTreeNode(tree->pRootNode, 4);
	insertAVLTreeNode(tree->pRootNode, 5);
	insertAVLTreeNode(tree->pRootNode, 6);
	insertAVLTreeNode(tree->pRootNode, 7);
	insertAVLTreeNode(tree->pRootNode, 8);
	insertAVLTreeNode(tree->pRootNode, 9);
	insertAVLTreeNode(tree->pRootNode, 10);
	insertAVLTreeNode(tree->pRootNode, 11);
	insertAVLTreeNode(tree->pRootNode, 12);
	insertAVLTreeNode(tree->pRootNode, 13);

	// printf("Root node : %d\n", tree->pRootNode->data);
	//preorderTraversalAVLTree(tree->pRootNode);
	//preorderTraversalAVLTree(tree->pRootNode);
	printf("\n");
	deleteAVLTreeNode(tree, tree->pRootNode, 10);
	//preorderTraversalAVLTree(tree->pRootNode);
	printf("\n");
	printf("Root node : %d\n", tree->pRootNode->data);
	deleteAVLTree(tree);
	return ;
}