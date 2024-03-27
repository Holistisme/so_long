# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:39:50 by aheitz            #+#    #+#              #
#    Updated: 2024/03/27 17:52:11 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror -pthread -g3
MLX			= ./lib/MLX42
GNL			= ./get_next_line
CHECKS		= ./program/checks
ERRORS		= ./program/errors
MAP			= ./program/map
MEMORY		= ./program/memory

LIBS		= ${MLX}/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS		= program/main.c \
			${GNL}/get_next_line.c \
			${GNL}/get_next_line_utils.c \
			${CHECKS}/argument.c \
			${CHECKS}/elements.c \
			${CHECKS}/map.c \
			${CHECKS}/pathway.c \
			${ERRORS}/occurences.c \
			${ERRORS}/print.c \
			${MAP}/cells.c \
			${MAP}/saving.c \
			${MAP}/setup.c \
			${MAP}/sizes.c \
			${MEMORY}/allocation.c \
			${MEMORY}/freeing.c \
			program/utils/is_inside.c
OBJS		= ${SRCS:.c=.o}
BER_FILE	?= france.ber

all: mlx ${NAME}

mlx:
	@cmake ${MLX} -B ${MLX}/build && make -C ${MLX}/build -j4

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $<

${NAME}: ${OBJS}
	@${CC} ${OBJS} ${LIBS} -o ${NAME}

clean:
	@rm -rf ${OBJS} ${MLX}/build

fclean: clean
	@rm -rf ${NAME}

re: clean all

execute: all
	@echo -n "Logfile date: " >> temp.log; date >> temp.log; echo "" >> temp.log
	@echo "Submitted argument: ${BER_FILE}" >> temp.log
	@echo "" >> temp.log
	@make >> temp.log 2>&1 || true
	@echo "" >> temp.log
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long ${BER_FILE} >> temp.log 2>&1 || true
	@echo "" >> temp.log
	@if [ ! -e so_long.log ]; then touch so_long.log; fi
	@cat so_long.log >> temp.log
	@mv temp.log so_long.log
	@make fclean
	@clear

.PHONY: all, clean, fclean, re, libmlx, execute