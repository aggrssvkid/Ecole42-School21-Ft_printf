SRCS = $(wildcard lib/*.c) $(wildcard len/*.c) $(wildcard lib/*.c)
OBJS = $(SRCS:%.c=%.o)
HEADER = libftprintf.h
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

all		:		$(NAME)

$(NAME)	:	$(OBJS)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJS)

fclean	:		clean
	$(RM) $(NAME)

re		:		fclean all

.PHONY :	all clean fclean re bonus

