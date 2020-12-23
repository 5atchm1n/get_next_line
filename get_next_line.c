/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:24 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/23 08:17:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* FAILED FUNCTION ?!!!!!!!! */
/*
static t_list		*ft_set_head(t_list *gnline, int fd)
{
	if (gnline == NULL)
	{
		gnline = malloc(sizeof(t_list));
		if (!gnline)
			return (NULL);
		gnline->ifd = fd;
		gnline->buff = ft_strdup("");
		gnline->head = gnline;
		gnline->next = NULL;
	}
	gnline = gnline->head;
	return (gnline);
}

static t_list		*ft_get_gnline(t_list *gnline, int fd)
{
	while (gnline->next != NULL)
	{
		if (gnline->ifd == fd)
			return (gnline);
		gnline = gnline->next;
	}
	if (gnline->ifd == fd)
		return (gnline);
	gnline->next = malloc(sizeof(t_list));
	if (!gnline->next)
		return (NULL);
	gnline->next->ifd = fd;
	gnline->next->buff = ft_strdup("");
	gnline->next->head = gnline->head;
	gnline->next->next = NULL;
	return (gnline->next);
}
*/

static t_list		*ft_set_gnline(t_list *gnline, int fd)
{
	if (gnline == NULL)
	{
		gnline = malloc(sizeof(t_list));
		gnline->ifd = fd;
		gnline->buff = ft_strdup("");
		gnline->head = gnline;
		gnline->next = NULL;
		return (gnline);
	}
	gnline = gnline->head;
	while (gnline->next != NULL)
	{
		if (gnline->ifd == fd)
			return (gnline);
		gnline = gnline->next;
	}
	if (gnline->ifd == fd)
		return (gnline);
	gnline->next = malloc(sizeof(t_list));
	gnline->next->ifd = fd;
	gnline->next->buff = ft_strdup("");
	gnline->next->head = gnline->head;
	gnline->next->next = NULL;
	return (gnline->next);
}


static char			*ft_set_line(char *str, char **line)
{
	char			*nbuffer;
	size_t			i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[0] == '\0')
	{
		*line = NULL;
		nbuffer = ft_strdup("");
		return (nbuffer);
	}
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

/* FAIL FUNCTION ?!!!!                    */
/*
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
*/
/*FAILED FUNCTION ?!!!! */
/*
static int			ft_return(int n, char **buff, char **line, char **tmp)
{
	if (n == 0 && ft_strlen(*buff) == 0)
	{
		*line = ft_strdup("");
		if (!line)
			return (-1);
		return (0);
	}
	*tmp = ft_set_line(*buff, line);
	free(*buff);
	*buff = *tmp;
	if (!buff)
		return (-1);
	return (1);
}
*/
static int			ft_return(int n, t_list *data, char **line, char **tmp)
{
	if (!tmp)
		return (-1);
	*tmp = ft_set_line(data->buff, line);
	free(data->buff);
	data->buff = *tmp;
	if (data->buff == NULL)
		return (-1);
	if (n == 0 && ft_strlen(data->buff) == 0)
		return (0);
	return (1);
}
int					get_next_line(int fd, char **line)
{
	static t_list	*gnline;
	char			buffer[BUFFER_SIZE + 1];
	char			*tmp;
	int				n;
/* FAILED FUNCTION ?!!!!! */
/*
	gnline = ft_set_head(gnline, fd);
	gnline = ft_get_gnline(gnline, fd);
*/
	gnline = ft_set_gnline(gnline, fd);
	if ((read(fd, buffer, 0) < 0) || fd == 0 || !line || BUFFER_SIZE < 1
	|| !gnline || !gnline->buff)
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		tmp = ft_strjoin(gnline->buff, buffer);
		free(gnline->buff);
		gnline->buff = tmp;
		if (!tmp)
			return (-1);
		if (ft_strchr(gnline->buff, '\n'))
			break ;
	}
	n = ft_return(n, gnline, line, &tmp);
	return (n);
}
