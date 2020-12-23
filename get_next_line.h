/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:18 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/23 06:03:22 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef FDMAX
# define FDMAX 256
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 256
#endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *str, int c);
size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);

#endif
