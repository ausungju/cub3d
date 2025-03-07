CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
NAME = libft.a

SRCS = \
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_isspecial.c	\
		ft_strlen.c		\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

SRCS_BONUS = \
		ft_lstnew.c				\
		ft_lstadd_front.c		\
		ft_lstsize.c			\
		ft_lstlast.c			\
		ft_lstadd_back.c		\
		ft_lstdelone.c			\
		ft_lstclear.c			\
		ft_lstiter.c			\
		ft_lstmap.c				\

SRCS_EXTRA = \
		get_next_line_utils.c	\
		get_next_line.c

OBJS = $(patsubst %.c,%.o,$(SRCS))
OBJS_BONUS = $(patsubst %.c,%.o,$(SRCS_BONUS))
OBJS_EXTRA = $(patsubst %.c,%.o,$(SRCS_EXTRA))

HEADERS = libft.h

ifdef WITH_BONUS
    OBJECTS = $(OBJS) $(OBJS_BONUS) $(OBJS_EXTRA)
else
    OBJECTS = $(OBJS) $(OBJS_EXTRA)
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) -o $@ $^

bonus:
	make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAGS) -c $^


clean:
	rm -rf $(OBJS) $(OBJS_BONUS) $(OBJS_EXTRA)

fclean:
	rm -rf $(OBJS) $(NAME) $(OBJS_BONUS) $(OBJS_EXTRA)

re: fclean all


.PHONY: all clean fclean re bonus
