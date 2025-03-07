# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 03:10:13 by seongkim          #+#    #+#              #
#    Updated: 2025/03/07 20:43:49 by seongkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# CFLAGS = -Wall -Wextra -Werror -
CFLAGS = -g

LFLAGS = -Lmlx_linux -lmlx_Linux -Llibft -lft -lXext -lX11 -lm -lz
INCLUDE = -Imlx_linux
NAME = cub3d

LIB_DIR = \
	libft		\
	mlx_linux

LIB_A = $(patsubst %,%.a,$(LIB_DIR))


MANDATORY_SRCS = \
	draw/draw_map.c		\
	draw/draw_cam.c		\
	draw/draw_utils.c	\
	\
	parsing/init.c		\
	parsing/texture.c	\
	\
	utils/ft_math.c		\
	utils/utils.c		\
	\
	event.c				\
	main.c

MANDATORY_OBJS = $(patsubst %.c,%.o,$(MANDATORY_SRCS))

SRCS = $(MANDATORY_SRCS)
OBJ = $(MANDATORY_OBJS)

.PHONY: all clean_lib clean fclean re rclean

all : $(NAME)

$(NAME) : $(OBJ) $(LIB_A)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) $(INCLUDE) -o $(NAME)

$(LIB_A) : $(LIB_DIR)
	make -C $<

%.o : %.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@


clean_lib: $(LIB_DIR)
	make -C $< fclean
	

clean:
	rm -rf $(BONUS_OBJS) $(MANDATORY_OBJS)

fclean: clean clean_lib
	rm -rf $(NAME)

re: 
	@make fclean
	@make all

rclean: re 
	@make all
	@make clean
