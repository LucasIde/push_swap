# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 17:18:58 by lide              #+#    #+#              #
#    Updated: 2022/03/18 19:11:18 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c\
				verif.c\
				move.c\
				push.c\
				first_sort.c\
				chunk.c\
				sort_chunk.c\
				write.c\
				sort_tiny.c

NAME =		push_swap.a
CC =		@gcc
CFLAGS =	-Wall -Wextra -Werror
OBJS =		${SRCS:.c=.o}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}
			@${CC} ${CFLAGS} ${NAME} -o push_swap
			@echo "Push_swap.a Created"

all:		${NAME}

clean:
			@rm -f ${OBJS}
			@echo "Push_swap Cleaned"

fclean:		clean
			@rm -f ${NAME} push_swap
			@echo "push_swap Fcleaned"

re:			fclean all

.PHONY: all clean fclean re
