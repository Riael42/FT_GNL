/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <gpascu@student.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:28:13 by riael             #+#    #+#             */
/*   Updated: 2026/06/11 18:13:53 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_gnldat	data;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return ((void *)0);
	ft_init(&data, fd);
	while (data.forty_two == 42)
	{
		if (data.buf[0] != '\0')
		{
			if (checknl(&data) != 0)
				return (good_ret(&data));
			data.ret = ft_strjoin(data.ret, data.buf, 1);
			if (!data.ret)
			{
				data.err = 1;
				return (ft_exit_gracefully(&data));
			}
		}
		readfunc(&data);
		if (data.err != 0)
			return (ft_exit_gracefully(&data));
		if (data.rv == 0)
			data.forty_two = 0;
	}
	return (ft_last_line(data.ret, data.leftovers[fd]));
}

void	ft_init(t_gnldat *data, int fd)
{
	int	i;

	data->fd = fd;
	data->found = 0;
	data->err = 0;
	data->rv = 1;
	data->ret = ((void *)0);
	data->forty_two = 42;
	if (data->leftovers[fd] != ((void *)0))
	{
		i = 0;
		while (data->leftovers[fd][i])
		{
			data->buf[i] = data->leftovers[fd][i];
			i += 1;
		}
		data->buf[i] = '\0';
		free(data->leftovers[fd]);
		data->leftovers[fd] = ((void *)0);
	}
	else
		data->buf[0] = '\0';
}

char	*ft_exit_gracefully(t_gnldat *data)
{
	if (data->ret != ((void *)0))
	{
		free(data->ret);
		data->ret = ((void *)0);
	}
	if (data->leftovers[data->fd] != ((void *)0))
	{
		free(data->leftovers[data->fd]);
		data->leftovers[data->fd] = ((void *)0);
	}
	return ((void *)0);
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
	if (leftovers == ((void *)0) || *leftovers == '\0')
	{
		if (*buf)
		{
			if (leftovers)
				*leftovers = '\0';
			return (buf);
		}
		free(buf);
		return ((void *)0);
	}
	if (leftovers)
		*leftovers = '\0';
	return (buf);
}
