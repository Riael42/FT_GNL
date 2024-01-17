/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:17:45 by riael             #+#    #+#             */
/*   Updated: 2024/01/17 11:33:05 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_hook_nl(char *buf, char *leftovers)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i += 1;
	i += 1;
	if (buf[i] == '\0')
	{
		leftovers[j] = '\0';
		return (buf);
	}
	while (buf[i] != '\0')
	{
		leftovers[j] = buf[i];
		buf[i] = '\0';
		i += 1;
		j += 1;
	}
	leftovers[j] = '\0';
	return (buf);
}

void	ft_strcat(char *s1, char *s2)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i += 1;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i += 1;
		j += 1;
	}
	s1[i] = '\0';
}

int	ft_found_nl(char *buf)
{
	ssize_t	i;

	if (buf == ((void *)0))
		return (0);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i += 1;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, char x)
{
	ssize_t	i;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret == ((void *)0))
		return ((void *)0);
	ret[0] = '\0';
	if (s1 != ((void *)0))
	{
		i = 0;
		while (s1[i] != '\0')
		{
			ret[i] = s1[i];
			i += 1;
		}
		ret[i] = '\0';
		if (x == 1)
			free(s1);
	}
	if (s2 != ((void *)0))
		ft_strcat(ret, s2);
	return (ret);
}
