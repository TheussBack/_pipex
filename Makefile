# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 00:51:00 by marvin            #+#    #+#              #
#    Updated: 2023/04/19 00:51:00 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# NAMEBONUS = checker

CC = cc


SRCS =	free.c \
		main.c \
		path_utils.c \
		utils.c \
		ft_split.c


# SRCSBONUS =

OBJS = ${SRCS:.c=.o}
# OBJSBONUS = ${SRCSBONUS:.c=.o}

INC = ./includes

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -I${INC} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
	    ${CC} ${FLAGS} ${OBJS} -o ${NAME}

# ${NAMEBONUS}:	${OBJS} ${OBJSBONUS} ${LIBFT}
# 		${CC} ${FLAGS} ${OBJS} ${OBJSBONUS} ${LIBFT} -o ${NAMEBONUS}

all:    ${NAME}

# bonus: ${NAMEBONUS}


clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
