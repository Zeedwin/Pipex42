# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 16:33:52 by jgirard-          #+#    #+#              #
#    Updated: 2022/07/30 12:07:49 by jgirard-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -Iheaders/
SRC=*.c
OBJ=*.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

