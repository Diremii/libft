NAME = libft
SRCS = ft_atoi.c \
	ft_isalpha.c \
	ft_isprint.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strnstr.c \
	ft_toupper.c \
	ft_bzero.c \
	ft_isascii.c \
	ft_memchr.c \
	ft_memset.c \
	ft_strlen.c \
	ft_strrchr.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_memcpy.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_tolower.c \
	ft_memcmp.c
OBJS = $(SRCS:.c=.o)
ARR=ar -rcs
CFLAGS = -Werror -Wextra -Wall

all : $(NAME) $(OBJS)
$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re