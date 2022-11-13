NAME	=	gol

RM	=	rm -f

IDIR	=	include/

CC	=	gcc

CFLAGS	+=	-I $(IDIR)
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-Wpedantic -Wno-long-long -g

CELLS_DIR	=	cells/
CELLS_FILES	=	display_cells.c			\
				get_cells_from_file.c	\
				get_nbr_neighbours.c	\
				destroy_cells.c			\
				kill_cell.c				\
				new_cell.c				\
				duplicate_cells.c		\
				is_alive.c

CELLS	=	$(addprefix $(CELLS_DIR), $(CELLS_FILES))

UTILS_DIR	=	utils/
UTILS_FILES	=	read_file.c			\
				str_to_word_array.c	\
				init_window.c

UTILS	=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

SRCS_DIR	=	src/
SRCS_FILES	=	main.c			\
				gol.c			\
				$(CELLS)		\
				$(UTILS)

SRCS	=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
