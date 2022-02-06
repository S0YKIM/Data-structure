# include "data_structure.h"

void    printError(char *message)
{
    fprintf(stderr, "%s\n", message);
}

void    test_maze()
{
    int map[HEIGHT][WIDTH] = {
            {3, 0, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 4},
        };
    StackNode startPos;
    // StackNode endPos;
    LinkedStack *stack;
    int result;
    
    result = findPosition(map, &startPos, START);
    if (!result)
    {
        printError("Failed to find the start position.");
        return ;
    }
    // result = findPosition(map, &endPos, END);
    // if (!result)
    // {
    //     printError("Failed to find the end position.");
    //     return ;
    // }

    stack = createLinkedStack();
    if (!stack)
    {
        printError("Failed to create the stack.");
        return ;
    }
    findPath(map, startPos, stack);
}