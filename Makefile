# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 17:18:58 by lide              #+#    #+#              #
#    Updated: 2022/03/19 18:28:48 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/push_swap/push_swap.c\
				srcs/push_swap/verif.c\
				srcs/push_swap/move.c\
				srcs/push_swap/push.c\
				srcs/push_swap/first_sort.c\
				srcs/push_swap/chunk.c\
				srcs/push_swap/sort_chunk.c\
				srcs/push_swap/write.c\
				srcs/push_swap/sort_tiny.c

SRCS_BONUS	=	gnl/get_next_line.c\
				gnl/get_next_line_utils.c\
				srcs/checker/test.c

NAME1		= push_swap.a
NAME2		= checker.a
EXEC1		= push_swap
EXEC2		= checker
OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
CC			= @gcc
CFLAGS		= -Wall -Wextra -Werror

${NAME1}:	${OBJS}
			@ar -rc ${NAME1} ${OBJS}
			@${CC} ${CFLAGS} ${NAME1} -o ${EXEC1}
			@echo "Push_swap Created"

${NAME2}:	${OBJS_BONUS}
			@ar -rc ${NAME2} ${OBJS}
			@${CC} ${CFLAGS} ${NAME2} -o ${EXEC2}
			@echo "checker Created"

all:	${NAME1}

bonus:	${NAME2}

clean:
			@rm -f ${OBJS} ${OBJS_BONUS}
			@echo "Clean executed"

fclean:
			@rm -f ${OBJS} ${OBJS_BONUS}
			@rm -f ${NAME1} ${EXEC1}
			@rm -f ${NAME2} ${EXEC2}
			@echo "Fclean executed"

re:			fclean all

.PHONY: all clean fclean re bonus
