SRC_DIR	= src

SRC_FILES	=	main.c\
				printer.c\
				tool.c\
				tool_2.c\
				tool_3.c\
				check_error.c\
				check_error_2.c\
				gest_error.c\
				parsing.c\
				split_arg.c\
				split_env.c\
				strlen.c\
				tool_arg.c\
				esp_quote_tool.c\
				pipe_redir_tool.c\
				token_generator.c\
				expand.c\
				expand_2.c\
				expand_3.c\
				after_expand_tool.c\

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

INC		= -I includes -I /usr/include

OBJS	= ${SRCS:.c=.o}

NAME 	= parsing

CC 		= clang

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g#-fsanitize=address -O3 

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

