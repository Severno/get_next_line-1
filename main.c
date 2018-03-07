#include "get_next_line.h"

int		main(void)
{
	if (get_next_line(1, NULL))	
		ft_putstr("Yes\n");
	else
		ft_putstr("No\n");
	return(0);
}
