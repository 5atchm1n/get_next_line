/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:24 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/04 02:44:36 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_addtolist(char *str, char **list)
{
	
}


#include "get_next_next.h"

int					get_next_line(int fd, char **line)
{
	static t_list	*lstdata;
	char			buffer[BUFFER_SIZE + 1];
	int				n;

	lstdata = ft_set_head(lstdata, fd);
	lstdata = ft_get_fd(lstdata, fd);
	if ((read(fd, buffer, 0) < 0) || fd = 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!lstdata->sbuffer)
		lstdata->sbuffer = ft_strdup("");
	while ((n = read(fd, buff, BUFFSIZE)) == 1)
	{
		buffer[n] = '\0';
		tmp = ft_strjoin(lstdata->sbuffer, buff);
		free(lstdata->sbuffer);
		lstdata->sbuffer = tmp;
		if (ft_strchr(lstdata->sbuffer, '\n')
				break ;
	}
	if (rd == 0 && ft_strlen(node->s))
		return (0);
	tmp = ft_addtolist(lstdata->sbuffer, line);
	free(lstdata->sbuffer);
	lstdata->sbuffer = tmp;
	return(1);
}
