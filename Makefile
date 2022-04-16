# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tojimene <tojimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 11:14:38 by tojimene          #+#    #+#              #
#    Updated: 2022/04/16 20:44:25 by tojimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_printf_utils.c

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC	=	gcc

RM	=	rm -f

FLAGS	=	-Wall -Werror - Wextra

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

.c.o:	${CC} ${FLAGS} -c $< -o ${<:.c=.o}


all:	${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re libft