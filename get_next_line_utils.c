/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <gpascu@student.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:35:26 by riael             #+#    #+#             */
/*   Updated: 2026/06/11 18:01:54 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	readfunc(t_gnldat *data)
{
	data->rv = read(data.fd, data.buf, BUFFER_SIZE);
	if (data->rv == -1)
	{
		int clean = 0;
		while (clean < 1024)
		{
			if (data->leftovers[clean] != ((void *)0))
				free(data.leftovers[clean]);
			clean += 1;
		}
		data->err = 1;
	}
}

int	checknl(t_gnldat *data)
{
	int	j;

	j = 0;
	while (data->buf[j] != '\0')
	{
		if (data->buf[j] == '\n')
			data->found = j;
		j += 1;
	}
	data.bufsize = j * (data.found == 0) + data.found * (data.found != 0) + 1;
	return (found);
}

char	*good_ret(t_gnldat *data)
{
	int	k;

	k = 0;
	if (data->leftovers[fd] != ((void *)0))
	{
		while (data->buf[data->found] != '\0')
		{
			data->leftovers[fd][k] = data->buf[found];
			k += 1;
			found += 1;
		}
		data->leftovers[fd][k] = '\0';
	}
	return (data->ret);
}

void	ft_strjoin(t_gnldat *data)
{
	char	*newret;

	data->retsize += data->bufsize;
	newret = (char *)malloc(sizeof(char) * data->retsize);
	if (newret == ((void *)0))
		data->err = 1;
	if (data->err != 1)
	{
		ft_strncpy(newret, data->ret, data->retsize - data->bufsize - 1);
		ft_strcat(newret, data->buf);
	}
	free(data->ret);
	data->ret = newret;
}
