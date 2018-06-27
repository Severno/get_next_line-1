# get_next_line
### Score 125/100
##### Mandatory
100/100
##### Bonus
25/25
***
### Challenge
**Note** *This project is no longer updated. get_next_line is now part of [libft](https://github.com/davhojt/libft "libft, a 42 project"), my personal C library. See [get_next_line](https://github.com/davhojt/libft/blob/master/srcs/libft/srcs/get_next_line.c "get_next_line, inside libft") inside libft. In the [libft version](https://github.com/davhojt/libft/blob/master/srcs/libft/srcs/get_next_line.c "get_next_line, inside libft") you can jus use the function by including libft.a.*  
  
To create a function which returns the next line from a file descriptor, each time the function is called, without losing the reading thread.  
The project achieved bonus score for using just one static variable, and handling multiple file descriptors without losing thread of reading on any.  
  
The project is very helpful for parsing excercises, in examples where there is one piece of data per line.  
With a simple program, get_next_line can behave like `cat`.

For example: The following main:
```c
#include "get_next_line.h"
#include <fcntl.h>

int				main(int argc, char **argv)
{
	int			i;
	int			fd;
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
```console
$> cat ann
Pink hair
Orange dress
Loves Monki
Eestlane
Normaalne
```
The above `cat`
```
$> ./fillit maps/sample.fillit
DDAA
CDDA
CCCA
BBBB
```
All tetriminos must be comprised of four '#' on a background of '.' and each seperate by a new line character. All other shapes are invalid. Shapes cannot be rotated.  
Some examples of invalid shapes are:
```
#### ...# ##... #.   .... ..## #### ,,,, .HH.
...# ..#. ##... ##   .... .... #### #### HH..
.... .#.. ....  #.   .... .... #### ,,,, ....
.... #... ....  .... ##.. #### ,,,, ....
```
It is possible to describe the same tertrimino in various ways. For exampe, each of the following are the same:
```
##.. .##. ..## .... .... ....
#... .#.. ..#. ##.. .##. ..##
#... .#.. ..#. #... .#.. ..#.
.... .... .... #... .#.. ..#.
```
The project is limitted to a maximum of 5 functions of 25 lines each and must conform to 42's norm.  
The program cannot leak. All errors must be handled carefully. In no way can the program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
Allowed functions are `exit`, `open`, `close`, `write`, `read`, `malloc` and `free`. Everything else is forbidden.

### Using the project
To compile, run `make`
This will compile **fillit**. Execute with a fillit map as a parameter.
```console
./fillit maps/sample.fillit
```
