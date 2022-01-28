NAME = data_structure

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c \
	   1.array.c \
	   1.linked_list.c \
	   2.circular_linked_list.c \
	   2.double_linked_list.c \
	   2.polynomial_addition.c \
	   2.reverse_linked_list.c \
	   3.stack_array.c \
	   3.stack_linked_list.c \
	   4.maze.c \
	   5.circular_queue.c \
	   5.deque.c \
	   5.queue.c \
	   6.queue_simulation.c \
	   7.binary_tree_traversal.c \
	   7.binary_tree.c \
	   8.binary_search_tree.c \
	   8.heap.c \
	   9.array_graph.c \
	   9.linked_list_graph.c \
	   10.dijkstra.c \
	   10.floyd.c \
	   10.kruskal.c \
	   10.minimum_spanning_tree.c \
	   10.prim.c \
	   11.sort.c \
	   12.search.c \

OBJS = $(SRCS:.c=.o)

INC_FLAGS = -I includes

RM = rm -f

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
