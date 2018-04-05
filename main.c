#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("alphabet", O_RDONLY);
	while ((get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	close(fd);
	return (0);
}
