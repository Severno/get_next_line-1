#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
	int		fd1;
	char	*line1;
	int i;

	i = 0;

	fd1 = open(argv[1], O_RDONLY);
	while ((get_next_line(fd1, &line1)) == 1)
	{
		ft_putstr(line1);
		ft_putchar('\n');
	}
	close(fd1);
	}
	return (0);
}
