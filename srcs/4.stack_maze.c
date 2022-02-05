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

// 스택에 플레이어 정보(현재 위치, 움직인 방향) 넣어주기



// 스택에 들어있는 값 이용해서 맵 모양 발자국 출력하기
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode	*current;
	char		map[HEIGHT][WIDTH] = {{' '}, };
	int			i;
	int			j;
	char		footprint;

	current = peekLS(pStack);
	if (!current)
		return ;
	
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
			j++;
		}
		i++;
	}

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

int findNotVisited(int mazeArray[HEIGHT][WIDTH], StackNode player, LinkedStack *pStack)
{
	int h;
	int w;

	while (player.direction <= UP)
	{
		h = player.h + DIRECTION_OFFSETS[player.direction][0];
		w = player.w + DIRECTION_OFFSETS[player.direction][1];
		if (mazeArray[h][w] == NOT_VISITED)
		{
			player.h = h;
			player.w = w;
			player.direction = RIGHT;
			pushLS(pStack, player);
			return (TRUE);
		}
		player.direction++;
	}
	return (FALSE);
}

int findVisited(int mazeArray[HEIGHT][WIDTH], StackNode player, LinkedStack *pStack)
{
	int 		h;
	int	 		w;
	StackNode	*element;

	while (player.direction >= RIGHT)
	{
		h = player.h + DIRECTION_OFFSETS[player.direction][0];
		w = player.w + DIRECTION_OFFSETS[player.direction][1];
		if (mazeArray[h][w] == VISITED)
		{
			element = popLS(pStack);
			free(element);
			element = NULL;
			return (TRUE);
		}
		player.direction--;
	}
	return (FALSE);
}

void findPath(int mazeArray[HEIGHT][WIDTH], StackNode startPos, StackNode endPos, LinkedStack *pStack)
{
	StackNode 	player;
	int       	result;
	StackNode	*top;

	// 플레이어 처음 위치 초기화
	// 맵에서 3(START)을 찾는 함수 만들어 구조체에 값 대입
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
		result = findNotVisited(mazeArray, player, pStack);
		if (!result)
		{
			findVisited(mazeArray, player, pStack);
		}
		top = peekLS(pStack);
		printf("top->h: %i\n", top->h);
		printf("top->w: %i\n", top->w);
		if (!top)
			exit(1);
		if ((top->h == endPos.h) && (top->w == endPos.w))
		{
			printf("Success!\n");
			showPath(pStack, mazeArray);
			exit(0);
		}
		else if ((top->h == startPos.h) && (top->w == startPos.w))
		{
			printf("Fail!\n");
			printMaze(mazeArray);
			exit(0);
		}
		mazeArray[top->h][top->w] = VISITED;
		player = *top;
	}
}