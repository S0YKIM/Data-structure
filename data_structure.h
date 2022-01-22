#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H

# include <stdio.h>
# include <stdlib.h>
# include "arrayList.h"
# include "linkedlist.h"

typedef struct s_singleNode {
	int data;
	struct t_singleNode* next;
} t_singleNode;

typedef struct s_doubleNode {
	int data;
	struct node* prev;
	struct t_doubleNode* next;
} t_doubleNode;

#endif