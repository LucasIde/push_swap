# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 17:18:58 by lide              #+#    #+#              #
#    Updated: 2022/03/02 17:40:30 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= push_swap.c

NAME =		libftpush_swap.a
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
OBJS =		${SRCS:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re
