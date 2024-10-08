NAME = libft
SRCS = ft_bzero.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_print.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_atoi.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_toupper.c
OBJS = $(SRCS:.c=.o)
ARR=ar -rcs
CFLAGS = -Werror -Wextra -Wall

all : $(NAME)
	cc $(CFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re