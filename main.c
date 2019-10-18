/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:54:09 by iklimov           #+#    #+#             */
/*   Updated: 2019/10/17 14:50:09 by iklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *line;
	int fd;
	int fd2;
	int i;

	line = "";
	fd = open("text.txt", O_RDONLY);
	//fd2 = open("numbers.txt", O_RDONLY);
	i = 0;
	get_next_line(fd, &line);
	printf("%s", line);

	// while(get_next_line(fd, &line))
	// {
	// 	get_next_line(fd, &line);
	// 	printf("%s", line);
	// 	// get_next_line(fd2, &line);
	// 	// printf("%s", line);
	// 	i++;
	// }
	printf("%s", line);
}
