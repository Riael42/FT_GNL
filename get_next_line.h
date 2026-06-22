#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>

typedef struct s_gnldat
{
	int		fd;
	char	*leftovers[1024];
	char	buf[BUFFER_SIZE + 1];
	char	*ret;
	int		line_size;
	int		found;
	int		size;
	int		err;
	int		rv;
	int		retsize;
	int		bufsize;
	int		forty_two;
}	t_gnldat;

char	*get_next_line(int fd);
void	ft_init(t_gnldat *data, int fd);
int		checknl(t_gnldat *data);
char	*good_ret(t_gnldat *data);
void	readfunc(t_gnldat *data);
char	*ft_exit_gracefully(t_gnldat *data);
char	*ft_strjoin(char *s1, char *s2, int free_s1);
char	*ft_last_line(char *buf, char *leftovers);
ssize_t	ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);

#endif