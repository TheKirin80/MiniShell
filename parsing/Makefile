SRC_DIR	= src

SRC_FILES	= main.c parsing.c split_arg.c split_env.c strlen.c tool_list_data.c tool_list_env.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

INC		= -I includes -I /usr/include

OBJS	= ${SRCS:.c=.o}

NAME 	= parsing

CC 		= clang

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address -O3 

all:		${NAME}

.c.o :
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

${NAME}:	${OBJS}
			$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

clean:		
			${RM} ${OBJS} ${OBJSBON}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

