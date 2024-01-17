/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | #voteme4council>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:04:32 by riael             #+#    #+#             */
/*   Updated: 2023/07/16 21:42:50 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
//#define malloc(x) NULL

char	*get_next_line(int fd)
{
	static char	leftovers[1024][BUFFER_SIZE + 1] = {0};
	ssize_t		i;
	char		*buf;
	char		cup[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1023)
		return ((void *)0);
	i = 1;
	buf = ft_strjoin(leftovers[fd], ((void *)0), 0);
	if (ft_found_nl(buf) != 0)
		return (ft_hook_nl(buf, leftovers[fd]));
	while (i > 0)
	{
		i = ft_fill_cup(cup, fd);
		if (i < 0)
			return (ft_exit_gracefully(buf, leftovers[fd]));
		buf = ft_strjoin(buf, cup, 1);
		if (buf == ((void *)0))
			return ((void *)0);
		if (ft_found_nl(buf) != 0)
			return (ft_hook_nl(buf, leftovers[fd]));
	}
	if (ft_found_nl(buf) != 0)
		return (ft_hook_nl(buf, leftovers[fd]));
	return (ft_last_line(buf, leftovers[fd]));
}

ssize_t	ft_fill_cup(char *cup, int fd)
{
	ssize_t	i;

	i = read(fd, cup, BUFFER_SIZE);
	if (i < 0)
		cup[0] = '\0';
	else
		cup[i] = '\0';
	return (i);
}

char	*ft_exit_gracefully(char *buf, char *leftovers)
{
	int	i;

	i = 0;
	if (buf != ((void *)0))
	{
		free(buf);
		buf = ((void *)0);
	}
	while (leftovers[i] != '\0')
	{
		leftovers[i] = '\0';
		i += 1;
	}
	return (buf);
}

ssize_t	ft_strlen(char *s)
{
	ssize_t	i;

	if (s == ((void *)0))
		return (0);
	i = 0;
	while (s[i] != '\0')
		i += 1;
	return (i);
}

char	*ft_last_line(char *buf, char *leftovers)
{
	if (buf == ((void *)0))
		return ((void *)0);
	if (leftovers[0] == '\0')
	{
		if (buf[0] != '\0')
		{
			leftovers[0] = '\0';
			return (buf);
		}
		free(buf);
		return ((void *)0);
	}
	leftovers[0] = '\0';
	return (buf);
}
