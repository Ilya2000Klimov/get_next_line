/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:06:28 by iklimov           #+#    #+#             */
/*   Updated: 2019/10/17 23:23:52 by iklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int get_next_line(const int fd, char **line) /*return 0 when file ends, -1, 1*/
{
	char buff[BUFF_SIZE];
	int bites_read;
	char *nloc;
	static t_list *list;
	char static *rem[6096];
	//char static	*str = "";
	*line = ft_strdup(rem[fd]);
	//check for read errors and invalid fd errors
	//iterate through list to find the correct fd by using size as the fd (list->size = fd)  == (*list).size
	while (read(fd, buff, BUFF_SIZE) != BUFF_SIZE)
	{
		buff[BUFF_SIZE] = '\0';
		if (ft_strchr(buff, '\n'))
			break;
		//concatinate buff to static vars
	}
	//check for stuff stored in your static variables
	//collect the correct line to store in *line
	//remove the line given to *line from your static variable
	//check correct return type and return it
	while (ft_strchr(buff, '\n') == NULL)
	{
		bites_read = read(fd, &buff, BUFF_SIZE);
		*line = ft_strjoin(*line, buff);
		if (BUFF_SIZE != bites_read)
			return (0);
	}
	nloc = ft_strchr(buff, '\n');
	ft_strjoin(*line, ft_strsub(buff, 0, (nloc - buff)));
	//rem = ft_strsub(nloc, 0, bites_read - (nloc - buff));
	return (1);
}

// int get_next_line(const int fd, char **line)	/*return 0 when file ends, -1, 1*/
// {
// 	char		*buff;
// 	int			bites_read;
// 	char static	*str;
// 	char		*nloc;

// 	if (fd > 65535)
// 		return (-1);
// 	buff = ft_strdup(str);
// 	while (!(nloc = ft_strchr(buff, '\n')))
// 	{
// 		if (BUFF_SIZE != read(fd, &buff, BUFF_SIZE));
// 			return (-1);
// 	}

// 	*line = ft_strjoin(str, buff);
// 	*str = ft_strsub(buff, 0, bites_read);
// 	if (BUFF_SIZE != bites_read)
// 		return (0);
// 	return (1);
// }