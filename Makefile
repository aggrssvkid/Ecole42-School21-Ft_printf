SRCS = ft_strchr.c ft_atoi.c ft_strdup.c ft_strlcpy.c ft_strlen.c analyze.c create_str.c find_type.c ft_itoa.c flags_init.c len_output.c kak_vivodim_nbr.c len_if_int.c zapolnenie_vir_int.c ft_printf.c zapolnim_novir_int.c len_if_un_int.c ft_strdup_len.c ten_to_sixteen.c up_symbols.c modern_string.c len_if_char.c vzaimodeystvie.c reverse.c len_if_str.c ft_itoa_unsigned_l.c ft_itoa_uten.c ten_to_sixteen_ll.c
OBJS = $(SRCS:%.c=%.o)
HEADER = libftprintf.h
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

all		:		$(NAME)

bonus	:		$(NAME)

ofiles	:
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME)	:	$(OBJS)
	ar rcs $(NAME) $?

clean	:
	$(RM) $(OBJS)

fclean	:		clean
	$(RM) $(NAME)

re		:		fclean all

.PHONY :	all clean fclean re bonus

