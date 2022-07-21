# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 02:47:15 by catperei          #+#    #+#              #
#    Updated: 2022/07/07 14:44:36 by catperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	src/push_swap.c		\
		src/ft_argcheck.c	\
		src/ft_opers.c		\
		src/ft_exec_opers.c	\
		src/ft_costs.c		\
		src/ft_sort3.c		\
		src/ft_sortmore.c	\
		src/ft_sortutils.c	\
		src/ft_stcutils.c

NAME = push_swap
INC = inc
OBJ = $(SRCS:c=o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f
LIBFT = libft/libft.a
LIBFT_DIR = libft

.PHONY:	all clean fclean re debug

all: $(NAME)

.c.o:
	$(CC) -g $(CFLAGS) -I$(INC) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) -g $(CFLAGS) -I$(INC) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
		make -C $(LIBFT_DIR) --silent

debug:	$(LIBFT)
		$(CC) -G $(CFLAGS) -I$(INC) $(LIBFT) $(SRCS) -O $(NAME)

valgrind:
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 25 36 52 85 79 654 254 -125 4521 -5425

clean:
		$(RM) $(OBJ)
		make -s clean -C $(LIBFT_DIR)

fclean: clean
		$(RM) $(NAME)
		$(RM) -R push_swap.dSYM
		make -s fclean -C $(LIBFT_DIR)

re:		fclean all
