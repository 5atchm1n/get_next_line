/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:24 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/16 05:44:12 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list		*ft_set_head(t_list *data, int fd)
{
	if (data == NULL)
	{
		data = malloc(sizeof(t_list));
		data->ifd = fd;
		data->buff = ft_strdup("");
		data->head = data;
		data->next = NULL;
	}
	data = data->head;
	return (data);
}

static t_list		*ft_get_data(t_list *data, int fd)
{
	while (data->next != NULL)
	{
		if (data->ifd == fd)
			return (data);
		data = data->next;
	}
	if (data->ifd == fd)
		return (data);
	data->next = malloc(sizeof(t_list));
	data->next->ifd = fd;
	data->next->buff = ft_strdup("");
	data->next->head = data->head;
	data->next->next = NULL;
	return (data->next);
}

static char			*ft_set_line(char *str, char **line)
{
	char			*nbuffer;
	size_t			i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		*line = ft_substr(str, 0, i);
		nbuffer = ft_strdup(&str[i + 1]);
	}
	if (str[i] == '\0')
	{
		*line = ft_substr(str, 0, i);
		nbuffer = ft_strdup("");
	}
	return (nbuffer);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*data;
	char			buffer[BUFFER_SIZE + 1];
	char			*tmp;
	int				n;

	data = ft_set_head(data, fd);
	data = ft_get_data(data, fd);
	if ((read(fd, buffer, 0) < 0) || fd == 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		tmp = ft_strjoin(data->buff, buffer);
		free(data->buff);
		data->buff = tmp;
		if (ft_strchr(data->buff, '\n'))
			break ;
	}
	tmp = ft_set_line(data->buff, line);
	free(data->buff);
	data->buff = tmp;
	if (n == 0 && ft_strlen(data->buff) == 0)
		return (0);
	return (1);
}
