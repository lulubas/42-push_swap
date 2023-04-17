# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 22:10:10 by lbastien          #+#    #+#              #
#    Updated: 2023/01/23 19:11:00 by lbastien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard variables

NAME		=	push_swap.a
INCLUDE_DIR	= 	include
PRINTF		=	ft_printf/
SRC_DIR 	=	src/
OBJ_DIR		=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs
CMD_OUT		=	gcc push_swap.a && ./a.out

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES =	push_swap parse_input utils

SRCS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#exe

OBJ_F		=	.cache_exists

all:		$(NAME)

run:		all
			@echo "$(WHITE)///////ARGUMENTS (OPTIONAL)///////$(DEF_COLOR)"
			@read -p "Enter input: " input; \
			echo "User input: $$input"; \
    		USER_INPUT=$$input; \
			echo "$(WHITE)///////OUTPUT///////$(DEF_COLOR)"; \
			$(CMD_OUT) $$USER_INPUT

$(NAME):	$(OBJS)
			@make -C $(PRINTF)
			@cp ft_printf/libftprintf.a .
			@mv libftprintf.a $(NAME)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)All compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_F)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

$(OBJ_F):
			@mkdir -p $(OBJ_DIR)
clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(PRINTF)
			@echo "$(BLUE)Objects files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@make fclean -C $(PRINTF)
			@echo "$(CYAN)Executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything!$(DEF_COLOR)"

norm:
	@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY: all, clean, fclean, re, norm, out
