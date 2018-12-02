# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blsegal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 12:14:54 by blsegal           #+#    #+#              #
#    Updated: 2017/12/26 09:32:34 by tmilon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = matrixhandler.c read_and_check.c setup_tetriminos.c \
	  extract_tetriminos.c set_val.c backtracking.c main.c
INC  = .
OBJ = $(SRC:.c=.o)

LIST_OBJS = $(LIST_SRCS:$(SRCS)/%.c=$(OBJS)/%.o)
CFLAGS = -Werror -Wextra -Wall
LIBFT = libft/
INC_LIBFT = $(LIBFT)

all : $(NAME)

$(NAME) : libft $(OBJ)
	make -C libft
	gcc $(CFLAGS) -I $(INC) -I $(INC_LIBFT) -L $(LIBFT) -lft $(OBJ) -o $(NAME)

clean :
	/bin/rm -f $(OBJ)
	make clean -C libft

fclean : clean
		 make fclean -C libft
		 /bin/rm -f $(NAME)

re : fclean all
