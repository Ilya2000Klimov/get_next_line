/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:06:28 by iklimov           #+#    #+#             */
/*   Updated: 2019/10/28 18:22:56 by iklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int get_next_line(const int fd, char **line) /*return 0 when file ends, -1, 1*/
{
	char			buff[BUFF_SIZE + 1];
	int				bites_read;
	char			*nloc;
	char			*tmp;
	static t_list	*lst;
	t_list			*tmplst;

	if ((fd < 0 || line == NULL || read(fd, buff, 0) < 0))
		return (-1);
	tmplst = ft_list_findsize(lst, (int)fd);
	tmp = (tmplst != NULL) ? ft_strdup(tmplst->content) : ft_strnew(0);
	ft_strdel((char**)&(tmplst->content));
	while(!(nloc = ft_strchr(tmp, '\n')) || nloc == NULL)
	{
		bites_read = read(fd, &buff, BUFF_SIZE);
		buff[bites_read] = '\0';
		tmp = ft_strjoinreal(tmp, buff);
		if (BUFF_SIZE != bites_read)
		{
			nloc = ft_strchr(tmp, '\n');
			break;
		}
	}
	bites_read = ft_strlen(tmp);
	nloc = (nloc == NULL) ? nloc = tmp + bites_read : nloc;
	*line = ft_strsub(tmp, 0, (nloc - tmp));
	if (tmplst == NULL)
	{
		tmplst = ft_lstnew("", (int)fd);
		ft_strdel((char**)&tmplst->content);
		ft_lstadd(&lst, tmplst);
	}
	//tmplst->content = strdup(tmp);
	tmplst->content = ft_strsub(tmp, (nloc + 1 - tmp), bites_read - ((nloc - tmp) % BUFF_SIZE));
	ft_strdel(&tmp);
	if (BUFF_SIZE != bites_read && tmplst->content == '\0')
	{
		ft_lstdelthis(&tmplst);
		return 0;
	}
	return 1;
}


// 	//*line = ft_strdup(rem[fd]);
// 	//check for read errors and invalid fd errors
// 	//iterate through lst to find the correct fd by using size as the fd (lst->size = fd)  == (*lst).size
// 	while (read(fd, buff, BUFF_SIZE) != BUFF_SIZE)
// 	{
// 		buff[BUFF_SIZE] = '\0';
// 		if (ft_strchr(buff, '\n'))
// 			break;
// 		//concatinate buff to static vars
// 	}
// 	//check for stuff stored in your static variables
// 	//collect the correct line to store in *line
// 	//remove the line given to *line from your static variable
// 	//check correct return type and return it
// 	while (ft_strchr(buff, '\n') == NULL)
// 	{
// 		bites_read = read(fd, &buff, BUFF_SIZE);
// 		*line = ft_strjoin(*line, buff);
// 		if (BUFF_SIZE != bites_read)
// 			return (0);
// 	}
// 	nloc = ft_strchr(buff, '\n');
// 	ft_strjoin(*line, ft_strsub(buff, 0, (nloc - buff)));
// 	//rem = ft_strsub(nloc, 0, bites_read - (nloc - buff));
// 	return (1);
// }

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

// int get_next_line(const int fd, char **line)
// {
// 	char buff[11];
// 	int bytes_read;
// 	buff[10] = '\0';
// 	//int static i = 10;

// 	bytes_read = read(fd, &buff, 10);
// 	// while (bytes_read == 10)
// 	// {
// 	// 	*line = ft_strjoin(*line, buff);
// 	// 	bytes_read = read(fd, &buff, 10);
// 	// }
// 	*line = ft_strdup(buff);
// 	if (bytes_read != 10)
// 		return 0;
// 	return 1;
// }

