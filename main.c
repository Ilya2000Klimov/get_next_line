/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:54:09 by iklimov           #+#    #+#             */
/*   Updated: 2019/10/30 21:59:19 by iklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

// int main()
// {
// 	char *line;
// 	int fd;
// 	int fd2;
// 	int i;
// 	//struct stat name;

// 	line = "";
// 	// fd = open("text.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	fd = open("test1.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		if (get_next_line(fd, &line) > 0)
// 		printf("f1[%s]\n", line);
// 		if (get_next_line(fd2, &line) > 0)
// 		printf("f2[%s]\n", line);
// 		i++;
// 		printf("%d\n\n", i);
// 	}

// 	// while(get_next_line(fd, &line))
// 	// {
// 	// 	get_next_line(fd, &line);
// 	// 	printf("%s", line);
// 	// 	// get_next_line(fd2, &line);
// 	// 	// printf("%s", line);
// 	// 	i++;
// 	// }
// 	//printf("%s", line);
// 	return(0);
// }

// 	// while (i < 10)
// 	// {
// 	// 	if (get_next_line(fd, &line) > 0)
// 	// 	printf("%s\n", line);
// 	// 	if (get_next_line(fd2, &line) > 0)
// 	// 	printf("%s\n", line);
// 	// 	i++;
// 	// }

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char *str;
	int i;

	str = NULL;
	i = 1;
	if (argc < 2)
		printf("File name missing.\n");
	while (argc > i)
	{
	 	fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			printf("Error, cannot open file\n");
			return (1);
		}
		printf("File: %s, fd %d\n\n", argv[i], fd);
		while ((ret = get_next_line(fd, &str)) > 0)
		{
			printf("[%s]\n", str);
			free(str);
		}
		free(str);
		printf("\n\n:End of File \"%s\"\n\n", argv[i]);
		if (ret == -1)
		{
			printf("Error, cannot close file\n");
			return (1);
		}
		i++;
	}
	while(1);
	return (0);
}