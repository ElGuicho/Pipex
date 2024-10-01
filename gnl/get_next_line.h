/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:02:31 by gmunoz            #+#    #+#             */
/*   Updated: 2024/10/01 15:02:38 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	*gnl_calloc(int count, int size);
int		gnl_strlen(const char *str);
char	*gnl_strchr(const char *s, int i);
char	*gnl_strdup(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
