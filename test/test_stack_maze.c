# include "data_structure.h"

void    test_maze()
{
	StackNode	startPos;
	LinkedStack	*stack;
	int			result;
	int			map[HEIGHT][WIDTH] = {
					{3, 0, 1, 1, 1, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 1},
					{1, 1, 1, 0, 1, 1, 1, 1},
					{1, 1, 1, 0, 1, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 1, 1, 1, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 0},
					{1, 1, 1, 1, 1, 1, 1, 4},
				};

	// int map[HEIGHT][WIDTH] = {
	// 		{4, 0, 1, 1, 1, 1, 1, 1},
	// 		{1, 0, 0, 0, 0, 0, 0, 1},
	// 		{1, 1, 1, 0, 1, 1, 1, 1},
	// 		{1, 1, 1, 0, 1, 1, 1, 1},
	// 		{1, 0, 0, 0, 0, 0, 0, 1},
	// 		{1, 0, 1, 1, 1, 1, 1, 1},
	// 		{1, 0, 0, 0, 0, 0, 0, 0},
	// 		{1, 1, 1, 1, 1, 1, 1, 3},
	// 	};

	// int map[HEIGHT][WIDTH] = {
	// 		{4, 0, 1, 1, 1, 1, 1, 1},
	// 		{1, 0, 0, 0, 0, 0, 0, 1},
	// 		{1, 1, 1, 0, 1, 1, 1, 1},
	// 		{1, 1, 1, 0, 1, 1, 1, 1},
	// 		{1, 0, 0, 3, 0, 0, 0, 1},
	// 		{1, 0, 1, 1, 1, 1, 1, 1},
	// 		{1, 0, 0, 0, 0, 0, 0, 0},
	// 		{1, 1, 1, 1, 1, 1, 1, 1},
	// 	};
	
	result = findPosition(map, &startPos, START);
	if (!result)
		exitError("Failed to find the start position.", NULL);
	stack = createLinkedStack();
	if (!stack)
		exitError("Failed to create the stack.", stack);
	findPath(map, startPos, stack);
}