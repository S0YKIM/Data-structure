#ifndef _MAP_DEF_
# define _MAP_DEF_

# define WIDTH 8
# define HEIGHT 8

# define NUM_DIRECTIONS 4

# define TRUE 1
# define FALSE 0
# define ERROR -1

// offset: h, w
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, 1},			// 0: 오른쪽으로 이동
	{1, 0},			// 1: 아래로 이동
	{0, -1},		// 2: 왼쪽으로 이동
	{-1, 0}			// 3: 위로 이동
};

enum	PosStatus { NOT_VISITED = 0, WALL = 1, VISITED = 2, START = 3, END = 4 };
enum	PosDirection { RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3 };

void findPath(int mazeArray[HEIGHT][WIDTH], StackNode startPos, LinkedStack *pStack);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

/* Custom */

int findPosition(int map[HEIGHT][WIDTH], StackNode *position, int element);
int findNotVisited(int mazeArray[HEIGHT][WIDTH], StackNode *player, LinkedStack *pStack);
int findVisited(int mazeArray[HEIGHT][WIDTH], StackNode *player, LinkedStack *pStack);
void	exitError(char *message, LinkedStack *pStack);
void    exitSuccess(char *message, LinkedStack *pStack);

#endif