# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 16:54:21 by iklimov           #+#    #+#              #
#    Updated: 2019/11/01 23:03:30 by iklimov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -g -Werror -Wextra -Wall -Wshadow main.c get_next_line.c libft/libft.a -I get_next_line.h -o gnl
debug:
	make -C libft
	gcc -g -fsanitize=address -Wall -Wextra -Wshadow main.c get_next_line.c libft/libft.a -I get_next_line.h
sanitaise:
	gcc -g -Wall -Wextra -Wshadow -fsanitize=address main.c get_next_line.c libft/libft.a -I get_next_line.h -o gnl
object:
	gcc -c -Werror -Wextra -Wall get_next_line.c
nolbft:
	gcc -g -Wall -Wextra -Wshadow main.c get_next_line.c -I get_next_line.h -o gnl
