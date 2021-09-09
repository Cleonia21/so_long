NAME		= 	so_long

SRC_S		=	main.c\

SRC_RES		= 	check_characters.c ft_strlen.c game_exit.c\
				initial_game.c initial_map_obj.c\
				my_hook.c render.c\

SRC_GNL		=	get_next_line.c get_next_line_utils.c\

OBJR		=	${addprefix Resources/,${SRC_RES:.c=.o}}
OBJG		=	${addprefix get_next_line/,${SRC_GNL:.c=.o}}
OBJS		=	${SRC_S:.c=.o}

MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${OBJR} ${OBJG}
			${CC} ${CFLAGS} ${OBJS} ${OBJR} ${OBJG} ${MLX_FLAGS} -o ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJR} ${OBJG} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all