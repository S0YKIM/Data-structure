#include "data_structure.h"

int findPosition(int map[HEIGHT][WIDTH], StackNode *position, int element)
{
	int i;
	int j;

	if (!map || !(*map) || !position)
		return (FALSE);
	if (element != START && element != END)
		return (FALSE);
	
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (map[i][j] == element)
			{
				position->h = i;
				position->w = j;
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode	*current;
	int			i;
	int			j;
	char		footprint;
	char		map[HEIGHT][WIDTH] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	current = peekLS(pStack);
	if (!current)
		return ;

	while (current)
	{
		if (current->direction == RIGHT)
			footprint = '>';
		else if (current->direction == DOWN)
			footprint = 'v';
		else if (current->direction == LEFT)
			footprint = '<';
		else if (current->direction == UP)
			footprint = '^';
		map[current->h][current->w] = footprint;
		current = current->pLink;
	}

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (mazeArray[i][j] == WALL)
			{
				map[i][j] = '*';
			}
			else if (mazeArray[i][j] == START)
			{
				map[i][j] = 'S';
			}
			else if (mazeArray[i][j] == END)
			{
				map[i][j] = 'E';
			}
			j++;
		}
		i++;
	}

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// // 맵 출력
void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			printf("%c ", mazeArray[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int findNotVisited(int mazeArray[HEIGHT][WIDTH], StackNode *player, LinkedStack *pStack)
{
	int h;
	int w;

	player->direction = RIGHT;
	while (player->direction <= UP)
	{
		h = player->h + DIRECTION_OFFSETS[player->direction][0];
		w = player->w + DIRECTION_OFFSETS[player->direction][1];
		if (mazeArray[h][w] == END)
		{
			printf("Success!\n");
			showPath(pStack, mazeArray);
			system("leaks data_structure");
			exit(0);
		}
		else if (mazeArray[h][w] == START)
		{
			printf("Fail!\n");
			printMaze(mazeArray);
			exit(0);
		}
		else if (mazeArray[h][w] == NOT_VISITED)
		{
			player->h = h;
			player->w = w;
			pushLS(pStack, *player);
			return (TRUE);
		}
		player->direction++;
	}
	return (FALSE);
}

int findVisited(int mazeArray[HEIGHT][WIDTH], StackNode *player, LinkedStack *pStack)
{
	int 		h;
	int	 		w;
	StackNode	*element;

	player->direction = UP;
	while (player->direction >= RIGHT)
	{
		h = player->h + DIRECTION_OFFSETS[player->direction][0];
		w = player->w + DIRECTION_OFFSETS[player->direction][1];
		
		if (mazeArray[h][w] == VISITED)
		{
			element = popLS(pStack);
			free(element);
			element = NULL;
			return (TRUE);
		}
		player->direction--;
	}
	return (FALSE);
}

void findPath(int mazeArray[HEIGHT][WIDTH], StackNode startPos, LinkedStack *pStack)
{
	StackNode 	player;
	int       	result;
	StackNode	*top;

	player.h = startPos.h;
	player.w = startPos.w;
	player.direction = RIGHT;

	result = pushLS(pStack, player);
	if (!result)
	{
		printError("Failed to push the map position into the stack.");
		return ;
	}

	while (1)
	{
		result = findNotVisited(mazeArray, &player, pStack);
		if (!result)
		{
			findVisited(mazeArray, &player, pStack);
		}
		top = peekLS(pStack);
		printf("top->h: %i\n", top->h);
		printf("top->w: %i\n", top->w);
		if (!top)
			exit(1);
		mazeArray[top->h][top->w] = VISITED;
		player = *top;
	}
}