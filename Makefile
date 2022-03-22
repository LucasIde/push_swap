# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 17:18:58 by lide              #+#    #+#              #
#    Updated: 2022/03/22 20:44:19 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap_file/push_swap.c\
				push_swap_file/verif.c\
				push_swap_file/move.c\
				push_swap_file/push.c\
				push_swap_file/first_sort.c\
				push_swap_file/chunk.c\
				push_swap_file/sort_chunk.c\
				push_swap_file/write.c\
				push_swap_file/sort_tiny.c

SRCS_BONUS	=	checker_file/get_next_line_bonus.c\
				checker_file/get_next_line_utils_bonus.c\
				checker_file/checker_bonus.c\
				checker_file/verif_bonus.c\
				checker_file/move_bonus.c\
				checker_file/check_move_bonus.c\
				checker_file/push_bonus.c

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
			@ar -rc ${NAME2} ${OBJS_BONUS}
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
