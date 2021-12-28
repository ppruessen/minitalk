# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 21:52:18 by pprussen          #+#    #+#              #
#    Updated: 2021/12/27 21:44:08 by pprussen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c

NAME_SERVER = server
NAME_CLIENT = client

OBJ_SRV = server.o utils.o
OBJ_CLIENT = client.o utils.o

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SRV)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SRV)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SRV)

fclean:	clean
	rm -f $(OBJ_CLIENT) $(OBJ_SRV) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: server client all re fclean clean