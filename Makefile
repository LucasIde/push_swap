# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 17:18:58 by lide              #+#    #+#              #
#    Updated: 2022/03/14 21:02:47 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# RED = \033[16m
PINK = \033[35m
CYAN = \033[36m
RESET = \033[0m

SRCS		=	push_swap.c\
				verif.c\
				move.c\
				push.c\
				first_sort.c\
				chunk.c\
				write.c

NAME =		push_swap.a
CC =		@gcc
CFLAGS =	-Wall -Wextra -Werror
OBJS =		${SRCS:.c=.o}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}
			@${CC} ${CFLAGS} ${NAME} -o ${NAME}
			@echo "${CYAN}Push_swap.a Created${RESET}"

all:		${NAME}

clean:
			@rm -f ${OBJS}
			@echo "${PINK}Push_swap Cleaned${RESET}"

fclean:		clean
			@rm -f ${NAME}
			@echo "${RED}push_swap Fcleaned${RESET}"

re:			fclean all

.PHONY: all clean fclean re
