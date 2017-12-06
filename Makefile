# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecloete <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/25 09:10:48 by ecloete           #+#    #+#              #
#    Updated: 2017/09/25 09:54:39 by ecloete          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c draw_line.c prep.c

LIB = libft/libft.a

FLAG = -lmlx -framework opengl -framework appkit

ERROR = -Werror -Wall -Wextra

all:
	@echo "Checking if libft needs to be compiled"
	@make -C ./libft
	@echo "Compiling Fdf"
	@gcc -o $(NAME) $(SRC) $(FLAG) $(ERROR) $(LIB)
	@echo "Fdf Compiled"

clean:
	$(MAKE) -C ./libft clean
	@rm -f $(NAME)

fclean: clean
	$(MAKE) -C ./libft fclean
	@rm -f $(LIB)

re: fclean lib all

lib:
	@echo "Re-compiling libft"
	$(MAKE) -C ./libft all
