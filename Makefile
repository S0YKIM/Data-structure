NAME = data_structure

CC = gcc
CFLAGS = -Wall -Werror -Wextra

FILES = main \
	   1.array \
	   1.linked_list \
	   2.circular_linked_list \
	   2.double_linked_list \
	   3.stack_array \
	   3.stack_linked_list \
	   4.stack_maze \
	   5.circular_queue \
	   5.deque \
	   5.queue \
	   6.queue_simulation \
	   7.binary_tree_traversal \
	   7.binary_tree \
	   8.binary_search_tree \
	   8.heap \
	   9.array_graph \
	   9.linked_list_graph \
	   10.dijkstra \
	   10.floyd \
	   10.kruskal \
	   10.minimum_spanning_tree \
	   10.prim \
	   11.sort \
	   12.search

FILES_TEST = test_linked_list \
	   		test_polynomial \
	   		test_stack \
			test_stack_maze

SRCS_DIR = srcs/
SRCS_TEST_DIR = test/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_TEST = $(addprefix $(SRCS_TEST_DIR), $(addsuffix .c, $(FILES_TEST)))

OBJS_DIR = srcs/
OBJS_TEST_DIR = test/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_TEST = $(addprefix $(OBJS_TEST_DIR), $(addsuffix .o, $(FILES_TEST)))

INC_FLAGS = -I includes

RM = rm -f

.c.o: $(SRCS) $(SRCS_TEST)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS_TEST)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_TEST)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re