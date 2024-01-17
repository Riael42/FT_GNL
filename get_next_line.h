/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:54:08 by riael             #+#    #+#             */
/*   Updated: 2024/01/17 11:34:53 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Maximum buffer size: Current free memory / 1024 - ~1KB
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

void	ft_strcat(char *s1, char *s2);
ssize_t	ft_strlen(char *s);
ssize_t	ft_fill_cup(char *cup, int fd);
int		ft_found_nl(char *buf);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, char x);
char	*ft_hook_nl(char *buf, char *leftovers);
char	*ft_last_line(char *buf, char *leftovers);
char	*ft_exit_gracefully(char *buf, char *leftovers);

#endif
