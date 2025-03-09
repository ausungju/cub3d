# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 03:10:13 by seongkim          #+#    #+#              #
#    Updated: 2025/03/10 01:47:26 by seongkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS = -g

LFLAGS = -Llib/mlx_linux -lmlx_Linux -Llib/libft -lft -lXext -lX11 -lm -lz
INCLUDE = -Imlx_linux
NAME = cub3d

LIB_DIR = \
	lib/libft		\
	lib/mlx_linux

LIB_A = $(patsubst %,%.a,$(LIB_DIR))


MANDATORY_SRCS = \
	src/draw/draw_map.c			\
	src/draw/draw_cam.c			\
	src/draw/draw_utils.c		\
	\
	src/parsing/init_main.c		\
	src/parsing/parameter.c		\
	src/parsing/parse_file.c	\
	src/parsing/parse_map.c		\
	src/parsing/utils.c			\
	\
	src/utils/ft_math.c			\
	src/utils/utils.c			\
	\
	src/utils/event1.c			\
	src/utils/event2.c			\
	src/main.c

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
