# get_next_line
### Score 125/100
##### Mandatory
100/100
##### Bonus
25/25
***
### Challenge
**Note** This project is no longer updated. get_next_line is now part of [libft] (https://github.com/davhojt/libft "libft, a 42 project"), my personal C library. See [libft] (https://github.com/davhojt/libft/blob/master/srcs/libft/srcs/get_next_line.c "get_next_line, inside libft").
To create a function which returns the next line from a file descriptor, each time it is called, without losing the reading thread.  
The project achieved bonus score for using just one static variable, and handling multiple file descriptors without losing thread of reading on any.  
  
The project is very helpful for parsing excercises, in examples where there is one piece of data per line.  
With a simple simple program, get_next_line can behave like `cat`.

For example:
```
$> cat maps/sample.fillit
....
##..
.#..
.#..

....
####
....
....

#...
###.
....
....

....
##..
.##.
....
```
The map above, should produce the following, where each tetrimino is assigned a chronological letter.
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
The program cannot leak. All errors must be handled carefully. In no way can the program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
Allowed functions are `exit`, `open`, `close`, `write`, `read`, `malloc` and `free`. Everything else is forbidden.

### Using the project
To compile, run `make`
This will compile **fillit**. Execute with a fillit map as a parameter.
```console
./fillit maps/sample.fillit
```
