SRC		= ft_printf.c ft_putchar.c ft_putnbr_hex_min.c print_s.c \
		  ft_atoi.c print_c.c print_di.c print_u.c \
		  print_p.c print_xmin.c print_xmaj.c print_percent.c \

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
