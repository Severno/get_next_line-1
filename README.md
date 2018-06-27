# get_next_line
### Score 125/100
##### Mandatory
100/100
##### Bonus
25/25
***
### Challenge
**Note** *This project is no longer updated. get_next_line is now part of [libft](https://github.com/davhojt/libft "libft, a 42 project"), my personal C library. See [get_next_line](https://github.com/davhojt/libft/blob/master/srcs/libft/srcs/get_next_line.c "get_next_line, inside libft") inside libft. In the [libft version](https://github.com/davhojt/libft/blob/master/srcs/libft/srcs/get_next_line.c "get_next_line, inside libft") you can just use the function by including libft.a.*  
  
To create a function which returns the next line from a file descriptor, each time the function is called, without losing the reading thread.  
  
The project achieved bonus score for using just one static variable, and handling multiple file descriptors without losing thread of reading on any.  
  
The project is very helpful for parsing excercises, in examples where there is one piece of data per line.  
With a simple program, get_next_line can behave like `cat`.

For example: The following main:
```c
#include "get_next_line.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		i;
	int		fd;
	char		*line;

	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
		close(fd);
	}
	return (0);
}
```
The following would result from the above simple main:
```console
$> ./test_gnl ann
Pink hair
Orange dress
Loves Monki
Eestlane
Normaalne
```
Which would be the same as:
```console
$> cat ann
Pink hair
Orange dress
Loves Monki
Eestlane
Normaalne
```
The function must conform to 42's norm.  
The function cannot leak. All errors must be handled carefully. In no way can the function quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
Allowed functions are `read`, `malloc` and `free`. Everything else is forbidden.

### Using the project
The project must be submitted without a Makefile. To compile first run:
```console
make -C libft/ fclean && make -C libft/
```
Then run:
```console
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
```

This will compile **test_gnl**. Execute with a fillit map as a parameter.
```console
./test_gnl [input_file]
```
