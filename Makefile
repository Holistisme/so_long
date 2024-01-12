# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:39:50 by aheitz            #+#    #+#              #
#    Updated: 2024/01/12 19:29:51 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

MAIN = main.c
SRC = list_mgmt.c \
	checks.c \
	checks_utils.c
GNL = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

OBJS = ${SRC:.c=.o} ${GNL:.c=.o} ${MAIN:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re