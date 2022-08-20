SRC_DIR	= src

SRC_FILES	= 

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
			@make --no-print-directory -C parsing
			@make --no-print-directory -C exec
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:		
			${RM} ${OBJS} ${OBJSBON}

fclean:		clean
			${RM} ${NAME}
			@make clean --no-print-directory  -C parsing/

re:			fclean all

.PHONY:		all clean fclean re bonus

