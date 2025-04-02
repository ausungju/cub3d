# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bohchoi <bohchoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 03:10:13 by seongkim          #+#    #+#              #
#    Updated: 2025/04/02 15:00:12 by bohchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LFLAGS = -Llib/mlx_linux -lmlx -Llib/libft -lft -lXext -lX11 -lm -lz
INCLUDE = -Imlx_linux
NAME = cub3D

LIB_DIR = \
	lib/libft		\
	lib/mlx_linux

LIB_A = $(patsubst %,%.a,$(LIB_DIR))


MANDATORY_SRCS = \
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
	src/main.c

BONUS_SRCS = \
	src_bonus/draw/draw_map.c			\
	src_bonus/draw/draw_cam.c			\
	src_bonus/draw/draw_utils.c		\
	\
	src_bonus/parsing/init_main.c		\
	src_bonus/parsing/parameter.c		\
	src_bonus/parsing/parse_file.c	\
	src_bonus/parsing/parse_map.c		\
	src_bonus/parsing/utils.c			\
	\
	src_bonus/utils/ft_math.c			\
	src_bonus/utils/utils.c			\
	\
	src_bonus/utils/event1.c			\
	src_bonus/utils/event2.c			\
	src_bonus/main.c

MANDATORY_OBJS = $(patsubst %.c,%.o,$(MANDATORY_SRCS))
BONUS_OBJS = $(patsubst %.c,%.o,$(BONUS_SRCS))


ifdef WITH_BONUS
    OBJ = $(LIBFT_OBJS) $(BONUS_OBJS)
else
    OBJ = $(LIBFT_OBJS) $(MANDATORY_OBJS)
endif

.PHONY: all clean_lib clean fclean re rclean

all : $(NAME)

bonus:
	make WITH_BONUS=1 all

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
