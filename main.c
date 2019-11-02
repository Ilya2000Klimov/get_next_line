/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:54:09 by iklimov           #+#    #+#             */
/*   Updated: 2019/11/02 10:24:20 by iklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

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
	return (0);
}