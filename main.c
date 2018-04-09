#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	int		fd1;
	//int		fd2;
	char	*line1;
	//char	*line2;

	fd1 = open("alphabet", O_RDONLY);
	//fd2 = open("ann", O_RDONLY);
	while ((get_next_line(fd1, &line1)) == 1)
	{
		/*while ((get_next_line(fd2, &line2)) == 1)
		{
			ft_putstr(line2);
			ft_putchar('\n');
		}*/
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putstr(line1);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
	}
	close(fd1);
	//close(fd2);
	return (0);
}
