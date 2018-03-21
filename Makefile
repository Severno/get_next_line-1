# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 20:21:22 by dhojt             #+#    #+#              #
#    Updated: 2018/03/08 03:17:28 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@clear
	@echo -----------BEGIN     libft     COMPILATION-----------
	@make -C libft/
	@echo -----------END     libft     COMPILATION-----------
	@echo -----------
	@echo -----------
	@echo -----------BEGIN     get_next_line     COMPILATION-----------
	@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	@echo -----------END     get_next_line     COMPILATION-----------
	@echo -----------
	@echo -----------
	@echo -----------BEGIN     main     COMPILATION-----------
	@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	@echo -----------END     main     COMPILATION-----------
	@echo -----------
	@echo -----------
	@echo -----------BEGIN     test_gnl     COMPILATION-----------
	@clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
	@echo -----------END     test_gnl     COMPILATION-----------
	@clear
	@./test_gnl | cat -e

clean:
	rm -rf *.o
	rm -rf test_gnl

fclean: clean
	@make -C libft/ fclean

re: fclean all
