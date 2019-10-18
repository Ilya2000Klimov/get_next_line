# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 16:54:21 by iklimov           #+#    #+#              #
#    Updated: 2019/10/17 14:25:55 by iklimov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Werror -Wextra -Wall main.c get_next_line.c libft/libft.a -I get_next_line.h
debug:
	gcc -g main.c get_next_line.c libft/libft.a -I get_next_line.h
object:
	gcc -c -Werror -Wextra -Wall get_next_line.c