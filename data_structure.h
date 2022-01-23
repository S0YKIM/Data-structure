#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H

# include <stdio.h>
# include <stdlib.h>
# include "arraylist.h"
# include "linkedlist.h"

typedef struct singleNodeType
{
	int data;
	struct singleNodeType* next;
} singleNode;

typedef struct doubleNodeType
{
	int data;
	struct doubleNodeType* prev;
	struct doubleNodeType* next;
} doubleNode;

#endif
