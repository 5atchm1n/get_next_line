/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:24 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/23 06:13:34 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int					get_next_line(int fd, char **line)
{
	static char		*buffer;
	char			tmp[BUFFER_SIZE + 1];
	char			*buff;
	int				n;

	if ((read(fd, tmp, 0) < 0) || fd == 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buff = "";
	while ((n = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[n] = '\0';
		buff = ft_strjoin(tmp, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	buffer = ft_set_line(buff, line);
	free(buff);
	if (n == 0 && ft_strlen(buffer) == 0)
		return (0);
	return (1);
}
