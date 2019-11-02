/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:40:11 by iklimov           #+#    #+#             */
/*   Updated: 2019/10/30 22:13:27 by iklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_node
{
	char			*str;
	int				fd;
	struct s_node	*next;
}					t_node;

static t_node	*findfd(t_node *head, int fd)
{
	t_node *tmp;
	t_node *out;

	if(head && head->fd == fd)
		return head;
	if (!(out = malloc(sizeof(*out))))
		return (NULL);
	//printf("\nMALLOKED THIS%p\n", out);
	out->fd = fd;
	out->next = head;
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
			//printf("\nFREED THIS%p\n", head);
			free(head);
			return (out);
		}
		tmp = tmp->next;
	}
	out->str = NULL;
	return (out);
}

static char	*strchr(char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && *s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int i;

	i = 0;
	while (src && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s1);
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}

static char	*ft_strjoinreal(char **s1, char *s2)
{
	char		*out;
	const int	l1 = __builtin_strlen(*s1 ? *s1 : "");
	const int	l2 = __builtin_strlen(s2);

	if (!(out = malloc(l1 + l2 + 1)))
		return (NULL);
	__builtin_memcpy(out, *s1 ? *s1 : "", l1);
	__builtin_memcpy((out + l1), s2, l2);
	out[l1 + l2] = '\0';
	free(*s1);
	*s1 = NULL;
	return (out);
}

int	get_next_line(const int fd, char **line)
{
	static t_node	*rem = NULL;
	t_node	*remv;
	char			buff[BUFF_SIZE + 1];
	char			*nloc;
	int				bitesread;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) || !(rem = findfd(rem, fd)))
		return (-1);
	while (!(nloc = strchr(rem->str, '\n')))
	{
		//printf("\nbytesread = %d\n\n", bitesread);
		if ((bitesread = read(fd, buff, BUFF_SIZE)) <= 0)
			break;
		buff[bitesread >= 0 ? bitesread : 0] = '\0';
		rem->str = ft_strjoinreal(&rem->str, buff);
	}
	*line = nloc ? __builtin_strndup(rem->str, nloc - rem->str) : ft_strdup(rem->str);
	tmp = rem->str;
	rem->str = nloc ? __builtin_strdup(nloc + 1) : __builtin_strdup("");
	if (**line == '\0' && !bitesread)
	{
		remv = rem;
		rem = rem->next;
		free(remv->str);
		free(remv);
		//printf("\nFREED THIS%p\n", remv);
	}
	free(tmp);
	return (**line == '\0' && !bitesread) ? 0 : 1;
}
