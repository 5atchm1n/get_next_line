/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:18 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/04 02:44:37 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

typedef struct		s_list
{
	char			*sbuffer;
	size_t			ifd;
	struct s_list	*head;
	struct s_list	*next;
	
}					t_list;


int					get_next_line(int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2)
char				*ft_strdup(const char *src)

#endif
