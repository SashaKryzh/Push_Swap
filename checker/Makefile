#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 10:11:34 by okryzhan          #+#    #+#              #
#    Updated: 2018/10/23 10:11:36 by okryzhan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = checker

FLAGS = -Wall -Wextra -Werror
CC = gcc

LIB_D = ../libft
LIB_HEAD = $(LIB_D)/includes
LIB_SRCS = -L $(LIB_D) -lft
LIBFT = $(addprefix $(LIB_D)/, libft.a)

INCLS = -I $(LIB_HEAD) -I ../includes

SRCS =	main.c \
		get_data.c \
		get_commands.c \
		execute.c \
		operations.c

OBJS_D = ./objs
OBJS = $(addprefix $(OBJS_D)/, $(SRCS:.c=.o))

all: $(OBJS_D) $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) all -C $(LIB_D)

$(OBJS_D): 
	@mkdir -p $(OBJS_D)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(LIB_SRCS) $(INCLS)

$(OBJS_D)/%.o: %.c ../includes/*.h ../libft/includes/*.h
	$(CC) -o $@ -c $< $(INCLS)

clean:
	@rm -rf $(OBJS_D)

fclean: clean
	@$(MAKE) fclean -C $(LIB_D)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re