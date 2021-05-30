# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 10:43:37 by nmbabazi          #+#    #+#              #
#    Updated: 2020/01/31 17:46:11 by nmbabazi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

CFLAGS	= -g -Wall -Wextra -Werror

RM	= rm -f

NAME	=	libftprintf.a

SRCS = 	ft_printf.c\
		conversion/ft_convertint.c\
		conversion/ft_convertstr.c\
		conversion/ft_convertchar.c\
		conversion/ft_convertu.c\
		conversion/ft_convertx.c\
		conversion/ft_convertxup.c\
		conversion/ft_convertp.c\
		conversion/ft_convertmod.c\
		lib/ft_lib1.c\
		lib/ft_lib2.c\
		lib/ft_lib3.c\

OBJS	= ${SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
