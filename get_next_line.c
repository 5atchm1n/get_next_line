/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:24 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/23 23:01:37 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_getfd(t_list *gnline, int fd)
{
	int				n;

	n = 0;
	if (gnline[n].ifd == 0)
	{
		gnline[n].ifd = fd;
		gnline[n].buff = "";
		return(n);
	}
	while (gnline[n].ifd != 0)
	{
		if (gnline[n].ifd == fd)
			return (n);
		n++;
	}
	gnline[n].ifd = fd;
	gnline[n].buff = "";
	return (n);
}

static char			*ft_set_line(char *str, char **line, char **tmp)
{
	size_t			i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[0] == '\0')
	{
		*line = NULL;
		return (NULL);
	}
	if (str[i] == '\n')
	{
		*line = ft_substr(str, 0, i);
		*tmp = &str[i + 1];
	}
	if (str[i] == '\0')
	{
		*line = ft_substr(str, 0, i);
		*tmp = "";
	}
	return (*tmp);
}


static int			ft_return(int n, char **fdbuff, char **line, char **tmp)
{
	*tmp = ft_set_line(*fdbuff, line, tmp);
	if (n == 0 && ft_strlen(*fdbuff) == 0)
	{
		free(*tmp);
		tmp = NULL;
		return (0);
	}
	*fdbuff = *tmp;
	if (*fdbuff == NULL)
		return (-1);
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static t_list	gnline[FDMAX];
	char			buffer[BUFFER_SIZE + 1];
	char			*tmp;
	int				n;
	int				ifd;
	int				start;

	if ((read(fd, buffer, 0) < 0) || fd == 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	ifd = ft_getfd(gnline, fd);
	n = 0;
	start = 1;
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		tmp = ft_strjoin(gnline[ifd].buff, buffer);
		gnline[ifd].buff = tmp;
		start = 0;
		if (ft_strchr(gnline[ifd].buff, '\n'))
			break ;
	}
	n = ft_return(n, &gnline[ifd].buff, line, &tmp);
	return (n);
}
