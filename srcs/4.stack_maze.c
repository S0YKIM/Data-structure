#include "data_structure.h"

// 비정상 종료 (w/ memory free)
void	exitError(char *message, LinkedStack *pStack)
{
	fprintf(stderr, "%s\n", message);
	if (pStack)
		deleteLinkedStack(&pStack);
	system("leaks data_structure");
	exit(EXIT_FAILURE);
}

// 정상 종료 (w/ memory free)
void	exitSuccess(char *message, LinkedStack *pStack)
{
	printf("%s\n", message);
	deleteLinkedStack(&pStack);
	system("leaks data_structure");
	exit(EXIT_SUCCESS);
}

// START 와 END 위치 저장
int	findPosition(int map[HEIGHT][WIDTH], StackNode *position, int element)
{
	int i;
	int j;

	if (!position)
		return (FALSE);
	if (element != START && element != END)
		return (FALSE);
	i = 0;
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			if (map[i][j] == element)
			{
				position->h = i;
				position->w = j;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

// 출구까지의 최단 경로 발자국으로 출력
void	showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode	*current;
	int			i;
	int			j;
	char		footprint;
	char		map[HEIGHT][WIDTH];

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
			map[i][j] = ' ';
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

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			if (mazeArray[i][j] == WALL)
				map[i][j] = '*';
			else if (mazeArray[i][j] == START)
				map[i][j] = 'S';
			else if (mazeArray[i][j] == END)
				map[i][j] = 'E';
		}
	}

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
			printf("%c ", map[i][j]);
		printf("\n");
	}
}

// 맵 출력
void	printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int	i;
	int	j;

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
			printf("%i ", mazeArray[i][j]);
		printf("\n");
	}
}

// 아직 방문하지 않은 길이 있으면 가기 (스택 노드 추가/PUSH)
int	findNotVisited(int mazeArray[HEIGHT][WIDTH], StackNode *player, LinkedStack *pStack)
{
	int	h;
	int	w;

	player->direction = RIGHT;
	while (player->direction <= UP)
	{
		h = player->h + DIRECTION_OFFSETS[player->direction][0];
		w = player->w + DIRECTION_OFFSETS[player->direction][1];
		if (h >= HEIGHT || w >= WIDTH)
		{
			player->direction++;
			continue ;
		}
		else if (mazeArray[h][w] == NOT_VISITED || mazeArray[h][w] == END)
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

// 더 이상 방문하지 않은 길은 없다면 이미 방문한 길로 되돌아가기 (스택 노드 제거/POP) 
int	findVisited(int mazeArray[HEIGHT][WIDTH], StackNode *player, LinkedStack *pStack)
{
	int	h;
	int	w;
	StackNode	*element;

	player->direction = UP;
	while (player->direction >= RIGHT)
	{
		h = player->h + DIRECTION_OFFSETS[player->direction][0];
		w = player->w + DIRECTION_OFFSETS[player->direction][1];
		if (h >= HEIGHT || w >= WIDTH)
		{
			player->direction--;
			continue ;
		}
		else if (mazeArray[h][w] == VISITED || mazeArray[h][w] == START)
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

// 미로 출구 찾기
void findPath(int mazeArray[HEIGHT][WIDTH], StackNode startPos, LinkedStack *pStack)
{
	StackNode	player;
	int			result;
	StackNode	*top;

	player.h = startPos.h;
	player.w = startPos.w;
	player.direction = RIGHT;

	result = pushLS(pStack, player);
	if (!result)
		exitError("Failed to push the map position into the stack.", pStack);

	while (1)
	{
		result = findNotVisited(mazeArray, &player, pStack);
		if (!result)
			result = findVisited(mazeArray, &player, pStack);
		top = peekLS(pStack);
		if (!top)
			exitError("Failed to find the top node.", pStack);
		if (mazeArray[top->h][top->w] == END)
		{
			showPath(pStack, mazeArray);
			exitSuccess("Success!", pStack);
		}
		else if (mazeArray[top->h][top->w] == START && !result)
		{
			printMaze(mazeArray);
			exitSuccess("Invalid path to the wayout!", pStack);
		}
		if (mazeArray[top->h][top->w] != START)
			mazeArray[top->h][top->w] = VISITED;
		player = *top;
	}
}