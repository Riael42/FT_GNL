//header

char	*ft_gnl_strjoin(char *dest, char *left, char *right, char *leftovers);

char	*get_next_line(int fd)
{
	static	char	*leftovers[4000][BUFFER_SIZE + 2] = {0};
	char		buf[BUFFER_SIZE + 1];
	char		*ret;
	size_t		size;
	
	if (leftovers[fd][BUFFER_SIZE + 1] == 0)
		leftovers[fd][BUFFER_SIZE + 1] = -1;
	buf[0] = '\0';
	ret = (char *)malloc(sizeof(char) * 1);
	while (42 == 42)
	{
		size = ft_gnl_strjoin(ret, ret, buf, leftovers[fd]);
		if (leftovers[fd][BUFFER_SIZE + 1] == 42 && size != -1)
			return (ft_last_line(ret, buf, leftovers[fd]));
		if (size == 1)
			return (ft_get_line(buf, leftovers[fd]));
		if (size != -1)
			size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (ft_exit_gracefully(ret));
		if (size == 0)
			leftovers[fd][BUFFER_SIZE + 1] = 42;
	}
}

static size_t	ft_gnl_strjoin(char *dest, char *left, char *right, char *leftovers)
{
	char	*new;
	
	if (leftovers[len] == 42)
		dest = ft_gnl_strpdup(leftovers);
	if (leftovers[len] == 42)
		return (42);
	new = ft_strjoin(left, right);
	if (new == (((void *)0)))
		return (-1);
	if (ft_find_nl(new) == 1)
		return (1);
	return (0);
}
