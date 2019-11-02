/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:40:11 by iklimov           #+#    #+#             */
/*   Updated: 2019/11/01 23:52:45 by iklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static t_node	*findfd(t_node *head, int fd)
{
	t_node *tmp;
	t_node *out;

	if (head && head->fd == fd)
		return (head);
	if (!(out = malloc(sizeof(*out))))
		return (NULL);
	out = ft_memcpy(out, &(t_node){NULL, fd, head}, sizeof(*out));
	tmp = head;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			out->str = tmp->str;
			tmp->str = (tmp->next) ? tmp->next->str : NULL;
			tmp->fd = (tmp->next) ? tmp->next->fd : -1;
			head = tmp->next;
			tmp->next = (tmp->next) ? tmp->next->next : NULL;
			free(head);
			return (out);
		}
		tmp = tmp->next;
	}
	out->str = NULL;
	return (out);
}

int				get_next_line(const int fd, char **line)
{
	static t_node	*rem = NULL;
	char			buff[BUFF_SIZE + 1];
	char			*nl;
	int				bitesread;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) || !(rem = findfd(rem, fd)))
		return (-1);
	while (!(nl = ft_strchr(rem->str, '\n')))
	{
		if ((bitesread = read(fd, buff, BUFF_SIZE)) <= 0)
			break ;
		buff[bitesread >= 0 ? bitesread : 0] = '\0';
		rem->str = ft_strjoinreal(&rem->str, buff);
	}
	*line = nl ? ft_strsub(rem->str, 0, nl - rem->str) : ft_strdup(rem->str);
	tmp = rem->str;
	rem->str = nl ? ft_strdup(nl + 1) : ft_strdup("");
	free(tmp);
	return (**line == '\0' && !bitesread) ? 0 : 1;
}
