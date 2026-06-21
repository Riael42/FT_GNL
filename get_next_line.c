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

char	*get_next_line(int fd)
{
	static t_gnldat	data;
	if (fd < 0 || fd > 1023)
		return ((void *)0);
	ft_init(&data, fd);
	while (data->forty_two == 42) 
	{
		if (checknl(&data) != 0)
			return (good_ret(&data));
		readfunc(&data);
		if (data.err != 0)
			return (ft_exit_gracefully(&data));
		if (data.rv == 0)
			data->forty_two = 0;
		else
		{
			data.ret = ft_strjoin(data.ret, data.buf, 1);
			if (data.err != 0)
				return (ft_exit_gracefully(&data));
		}
	}
	return (ft_last_line(data.ret, leftovers[fd]));
}

ft init
{
	data.fd = fd;
	data.found = 0;
	data.err = 0;
	data.rv = 1;
	data->leftovers[fd] = malloc;
	data.buf = //join leftovers with nothing

}
