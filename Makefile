# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:39:50 by aheitz            #+#    #+#              #
#    Updated: 2024/01/09 17:04:09 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
EXEC = so_long
CFLAGS = -Wall -Wextra -Werror -g3

SRC = list_mgmt.c
GNL = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

OBJS = ${SRC:.c=.o} ${GNL:.c=.o}

all: ${NAME} ${EXEC}

${NAME} : ${OBJS}
	${AR} rcs ${NAME} ${OBJS}

${EXEC} : main.o ${NAME}
	${CC} ${CFLAGS} main.o ${NAME} -o ${EXEC}

clean:
	${RM} ${OBJS} ${EXEC} main.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re