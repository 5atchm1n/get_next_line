/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:18 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/23 23:02:20 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef FDMAX
#define FDMAX 16
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	int				ifd;
	char			*buff;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *str, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);

#endif
