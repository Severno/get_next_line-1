#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int 	main(void)
{
	int		fildes;
	int		fildes2;
	int		fildes3;

	char	str[150];
	char	str2[150];
	char	str3[150];

	fildes = open("ann", O_RDONLY);
	read(fildes, str, 100);
	printf("%d = %s\n", fildes, str);
	
	fildes2 = open("ann", O_RDONLY);
	read(2, str2, 100);
	printf("%d = %s\n", fildes2, str2);
		
	fildes3 = open("ann", O_RDONLY);
	read(fildes3, str3, 100);
	printf("%d = %s\n", fildes3, str3);
	
	close(fildes);
	close(fildes2);
	close(fildes3);
	return (0);
}
