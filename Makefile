# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 14:12:10 by andrefranci       #+#    #+#              #
#    Updated: 2022/11/21 14:12:33 by andrefranci      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \

LIB = ft_printf.h	

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC= cc 

RM = rm -rf 

all:	$(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

run: 
	$(CC) $(CFLAGS) $(NAME) -o main
	./main

clean:	
			$(RM) $(OBJS)

re: fclean $(NAME)

fclean:	clean
				$(RM) $(NAME) main

.PHONY: all clean fclean re bonus