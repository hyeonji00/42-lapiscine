# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 14:58:58 by hyeonjik          #+#    #+#              #
#    Updated: 2022/02/21 20:47:51 by hyeonjik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CGLAGES = -Wall -Wextra -Werror
NAME = bsq
OBJS = $(SRCS:.c=.o)
SRCS = *.c

%.o : %.c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CGLAGES) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
