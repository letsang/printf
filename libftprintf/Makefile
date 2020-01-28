SRC		= print_space.c convert_print.c ft_printf.c ft_strlen.c ft_putchar.c print_s.c \
		  ft_strdup.c ft_atoi.c count_digit.c print_c.c print_di.c print_u.c \
		  count_hex.c print_p.c print_xmin.c print_xmaj.c print_percent.c \
		  init_list_fmt.c init_list_flag.c is_spec.c is_spec_in_fmt.c \

OBJS	= ${SRC:.c=.o}

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

${NAME}:	ft_printf.h ${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

%.o: %.c
	${CC} -I. -o $@ -c $? ${CFLAGS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
