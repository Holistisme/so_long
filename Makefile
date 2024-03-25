# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:39:50 by aheitz            #+#    #+#              #
#    Updated: 2024/03/25 17:05:47 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror -pthread -g3
MLX			= ./lib/MLX42
GNL			= ./get_next_line

LIBS		= ${MLX}/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS		= program/main.c \
			${GNL}/get_next_line.c \
			${GNL}/get_next_line_utils.c \
			program/errors.c \
			program/memory.c
#			setup/save_map.c \
#			setup/set_map.c \
#			checking/argument.c \
#			checking/elements.c \
#			checking/map.c \
#			checking/pathway.c \
#			error/free.c \
#			error/management.c \
#			game/setup.c \
#			game/graphics.c \
#			game/map_char.c \
#			game/play.c \
#			animation/management.c \
#			animation/grass.c \
#			animation/mills.c \
#			animation/instances.c \
#			animation/seasons.c \
#			animation/fields.c \
#			animation/months.c \
#			graphics/castles.c \
#			graphics/paris.c \
#			graphics/random.c \
#			graphics/borders.c \
#			graphics/mountains.c \
#			guards/graphics.c \
#			guards/orders.c \
#			animation/utils.c \
#			animation/guards.c \
#			main.c
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

execute: re
	@echo -n "Logfile date: " >> temp.log; date >> temp.log; echo "" >> temp.log
	@echo "Submitted argument: ${BER_FILE}" >> temp.log
	@echo "" >> temp.log
	@make >> temp.log 2>&1 || true
	@echo "" >> temp.log
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long ${BER_FILE} >> temp.log 2>&1 || true
	@echo "" >> temp.log
	@cat so_long.log >> temp.log
	@mv temp.log so_long.log
	@make fclean
	@clear

.PHONY: all, clean, fclean, re, libmlx execute