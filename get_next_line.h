/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:18 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/03 23:38:37 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

typedef struct		s_list
{
	ssize_t			p_read;
	char			line[BUFFER SIZE + 1];
}					t_list;


int					get_next_line(int fd, char **line);

#endif
