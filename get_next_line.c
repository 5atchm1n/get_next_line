/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:24 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/24 04:00:27 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(int fd, char **line)
{
	static char		*gnline;
	char			buffer[BUFFER_SIZE + 1];
	int				n;
	int				flag;

	if ((read(fd, buffer, 0) < 0) || fd == 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		gnline = gnl_join(gnline, buffer);
		flag = gnl_find(gnline);
		if (flag != -1)
			break ;
	}
	flag = gnl_find(gnline);
	if (flag != -1)
	{
		*line = gnl_sub(gnline, 0, flag, 0);
		gnline = gnl_dup(&gnline[flag + 1], gnline);
		return (1);
	}
	if (gnline)
	{
		*line = gnl_sub(gnline, 0, gnl_len(gnline), 1);
		gnline = NULL;
		return (0);
	}
	*line = NULL;
	return (0);
}
