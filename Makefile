# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 14:05:13 by ymanzi            #+#    #+#              #
#    Updated: 2020/11/22 13:49:15 by ymanzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
GNL = ../../gnl
CFLAGS = #-Wall -Wextra -Werror 
SRCS = get_next_line.c get_next_line_utils.c 
OBJ = $(SRCS:.c=.o)
EXEC = b1 b2 b42 b1m 

all: copy b1 b2 b42 b1m 

copy:
	@cp $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c $(GNL)/get_next_line.h . 

b1:
	@gcc $(CFLAGS) main.c -D BUFFER_SIZE=1 -fsanitize=address $(SRCS) -o b1 && ./b1
b2:
	@gcc $(CFLAGS) main.c -D BUFFER_SIZE=2 -fsanitize=address $(SRCS) -o b2 && ./b2

b42:
	@gcc $(CFLAGS) main.c -D BUFFER_SIZE=42 -fsanitize=address $(SRCS) -o b42 && ./b42 

b1m:
	@gcc $(CFLAGS) main.c -D BUFFER_SIZE=1000000 -fsanitize=address $(SRCS) -o b1m && ./b1m 

clean:
		rm -f $(EXEC) $(SRCS) get_next_line.h 
fclean: clean
re: fclean all
