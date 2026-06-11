#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

typedef struct s_gnldat
{
	char	*leftovers[1024];
	char	buf[BUFFER_SIZE];
	char	*ret;
	int		line_size;
	int		found;
	int		size;
	int		err;

}	t_gnldat;

#endif
