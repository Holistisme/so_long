# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:39:50 by aheitz            #+#    #+#              #
#    Updated: 2024/03/15 16:37:36 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -pthread
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		setup/save_map.c \
		setup/set_map.c \
		checking/argument.c \
		checking/elements.c \
		checking/map.c \
		checking/pathway.c \
		error/free.c \
		error/management.c \
		game/setup.c \
		game/graphics.c \
		game/map_char.c \
		game/play.c \
		animation/management.c \
		animation/grass.c \
		animation/mills.c \
		animation/instances.c \
		animation/seasons.c \
		main.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx