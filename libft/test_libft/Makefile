# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 15:32:02 by dhojt             #+#    #+#              #
#    Updated: 2018/02/01 14:45:40 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmy.a

COMP = gcc -Wall -Werror -Wextra -c -o

CFIND = $(shell find ./srcs/ -maxdepth 1 -type f | grep -E "\.c$$")
CFILE = $(CFIND)
OFILE = $(notdir $(CFILE:%.c=%.o))

OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR), $(OFILE))

TEST = test

re: fclean all

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo Create: Object directory

$(NAME): $(OBJ)
	@make -C .. re
	@echo Create: libft.a
	@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
	ranlib $(NAME)
	@gcc -o $(TEST) ../libft.a $(NAME)
	@clear
	@./test help

$(OBJ): $(CFILE)
	@$(MAKE) $(OFILE)

$(OFILE):
	@echo Create: $(@:obj/%=%)
	@$(COMP) $(OBJ_DIR)$@ ./srcs/$(@:%.o=%.c)

clean:
	@make -C .. fclean
	@/bin/rm -rf $(OBJ_DIR)
	@echo Cleaned object files

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)
	@echo Cleaned $(TEST)
	@echo Cleaned $(NAME)

.PHONY: clean flcean re
