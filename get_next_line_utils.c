/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
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

void	readfunc(t_gnldat *data)
{
	int	clean;

	data->rv = read(data->fd, data->buf, BUFFER_SIZE);
	if (data->rv == -1)
	{
		clean = 0;
		while (clean < 1024)
		{
			if (data->leftovers[clean])
			{
				free(data->leftovers[clean]);
				data->leftovers[clean] = ((void *)0);
			}
			clean += 1;
		}
		data->err = 1;
	}
	else
	{
		data->buf[data->rv] = '\0';
	}
}

int	checknl(t_gnldat *data)
{
	int	j;

	j = 0;
	data->found = -1;
	while (data->buf[j] && data->found == -1)
	{
		if (data->buf[j] == '\n')
			data->found = j;
		j += 1;
	}
	if (data->found != -1)
	{
		data->bufsize = data->found + 1;
		return (1);
	}
	data->bufsize = j;
	return (0);
}

char	*fill_line(t_gnldat *data, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (data->ret)
	{
		while (data->ret[i])
		{
			line[i] = data->ret[i];
			i += 1;
		}
		free(data->ret);
		data->ret = ((void *)0);
	}
	j = 0;
	while (j < (size_t)data->found + 1)
	{
		line[i + j] = data->buf[j];
		j += 1;
	}
	line[i + j] = '\0';
	return (line);
}

char	*good_ret(t_gnldat *data)
{
	char	*line;
	size_t	len;

	len = 0;
	len = ft_strlen(data->ret);
	line = (char *)malloc(sizeof(char) * (len + data->bufsize + 1));
	if (!line)
	{
		data->err = 1;
		return ((void *)0);
	}
	line = fill_line(data, line);
	data->leftovers[data->fd] = ((void *)0);
	if (data->buf[data->found + 1])
		data->leftovers[data->fd] = \
		ft_strjoin(((void *)0), &data->buf[data->found + 1], 0);
	if (data->buf[data->found + 1] && !data->leftovers[data->fd])
	{
		free(line);
		data->err = 1;
		return ((void *)0);
	}
	return (line);
}

char	*ft_strjoin(char *s1, char *s2, int free_s1)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res && s1 && free_s1)
		free(s1);
	if (!res)
		return ((void *)0);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i += 1;
	}
	j = 0;
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j += 1;
	}
	res[i + j] = '\0';
	if (s1 && free_s1)
		free(s1);
	return (res);
}
