# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 16:46:23 by cgreenpo          #+#    #+#              #
#    Updated: 2024/09/14 11:36:40 by cgreenpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	=	push_swap.c  	actions.c  		sort.c \
			init.c 			operations.c 	count.c \
			count_utils.c 	action_utils.c 	stack_utils.c \
			atoi.c			minisort.c

OBJ = $(SRCS:.c=.o)

HEADER = push_swap.h

# FLAGS	= -fsanitize=address # -Wall -Wextra -Werror

FLAGS	= -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(HEADER) $(OBJ) Makefile
	clang $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER) Makefile
	clang $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
 
.PHONY: all clean fclean re