# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 14:58:58 by hyeonjik          #+#    #+#              #
#    Updated: 2022/02/24 17:39:22 by hyeonjik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CGLAGES = -Wall -Wextra -Werror
NAME = bsq
OBJS = $(SRCS:.c=.o)
SRCS = *.c

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CGLAGES) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
