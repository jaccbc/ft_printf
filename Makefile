# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joandre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 02:21:02 by joandre-          #+#    #+#              #
#    Updated: 2024/09/23 16:49:31 by joandre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft/libft.a
SRC = utils.c ft_printf.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
$(LIBFT):
	make -s -C ./libft
	
clean:
	rm -rf $(OBJ)
	make clean -s -C ./libft

fclean: clean
	rm -rf $(NAME) $(LIBFT)

re: fclean all
