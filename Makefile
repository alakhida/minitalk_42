# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 00:28:38 by alakhida          #+#    #+#              #
#    Updated: 2023/03/27 02:40:57 by alakhida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = minitalk.h
SERVER   = server
CLIENT   = client
CC	     = gcc
CFLAGS    = -Wall -Werror -Wextra
OBJ		= client.o server.o

all :  $(SERVER) $(CLIENT)

$(SERVER) : server.o minitalk_utils.c $(INC)
	cc $(CFLAGS) server.c minitalk_utils.c -o server

$(CLIENT) : client.o minitalk_utils.c $(INC) 
	cc $(CFLAGS) client.c minitalk_utils.c -o client

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf server client

re : fclean all
