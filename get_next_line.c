/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:24 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/04 13:51:59 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_set_head(t_list data, int fd)
{
//checks if head exists and sets it
}

ft_get_head(t_list data, int fd)
{
//finds the correct node
}

ft_set_line(char *str, char **list)
{
//copies the buff into line	
}


#include "get_next_next.h"

int					get_next_line(int fd, char **line)
{
	static t_list	*data;
	char			buffer[BUFFER_SIZE + 1];
	char			*temp;
	int				n;

	data = ft_set_head(data, fd);
	data = ft_get_fd(data, fd);
	if ((read(fd, buffer, 0) < 0) || fd = 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!data->buff)
		data->buff = ft_strdup("");
	while ((n = read(fd, buff, BUFFSIZE)) == 1)
	{
		buffer[n] = '\0';
		tmp = ft_strjoin(data->buff, buff);
		free(data->buff);
		data->buff = tmp;
		if (ft_strchr(data->buff, '\n')
				break ;
	}
	if (rd == 0 && ft_strlen(node->s))
		return (0);
	tmp = ft_set_line(data->buff, line);
	free(data->buff);
	data->buff = tmp;
	return(1);
}
