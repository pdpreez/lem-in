# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppreez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 09:23:32 by ppreez            #+#    #+#              #
#    Updated: 2018/08/17 09:39:13 by ppreez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIB_PATH = ./libft/

SRC_FILE = lem-in.c error.c struct.c data_check.c room_type.c \
			matrix.c connection.c utils.c pathfinder.c save_path.c \

OBJ_FILE = $(SRC_FILE:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

CCFLAGS = -Wall -Wextra -Werror
CC = gcc $(CCFLAGS)
LIBF = $(LIB_PATH)libft.a

all: $(NAME) $(LIBF)

$(NAME): $(OBJ) $(COMPILE)
	make -C ./libft/
	$(CC) -o $@ $(LIBF) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) -I$(INC_PATH) -o $@ -c $<

clean: cleanlib
	/bin/rm -rf $(OBJ)

fclean: clean fcleanlib
	/bin/rm $(NAME)

cleanlib:
	make clean -C$(LIB_PATH)
	
fcleanlib:
	make fclean -C $(LIB_PATH)

re: fclean all

.PHONY: re fclean clean all
