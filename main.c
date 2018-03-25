#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("alphabet", O_RDONLY);
	get_next_line(fd, &line);
	ft_putstr(line);
	close(fd);
	return (0);
}
