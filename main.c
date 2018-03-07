#include "get_next_line.h"

int		main(void)
{
	if (get_next_line(1, NULL))	
		ft_putstr("Linked to gnl [1]\n");
	else
		ft_putstr("Linked to gnl [0]\n");

	int		fildes;
	int		fildes2;
	int		fildes3;

	char	str[150];
	char	str2[150];
	char	str3[150];

	printf("TOP\n");
	fildes = open("ann", O_RDONLY);
	read(fildes, str, 100);
	printf("%d = %s\n", fildes, str);

	fildes2 = open("ann", O_RDONLY);
	read(fildes2, str2, 100);
	printf("%d = %s\n", fildes2, str2);

	fildes3 = open("ann", O_RDONLY);
	read(fildes3, str3, 100);
	printf("%d = %s\n", fildes3, str3);

	printf("BOTTOM\n");

	close(fildes);
	close(fildes2);
	close(fildes3);
	return (0);
}
