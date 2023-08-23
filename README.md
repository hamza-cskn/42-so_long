# 42-so_long
> And thanks for all the fish!

## Summary
This project is about coding a minimal 2D game. [Minilibx](https://harm-smits.github.io/42docs/) library used to open windows, putting pixels to the screen and listening keys.

## Mandatory Part
| Program Name    | Turn in files | Makefile | Arguments | External functs. | Libft authorized | Description |
| -------- | ------- | ------- | -------- | ------- | ------- | ------- |
| so_long | Makefile, \*.h, \*.c, maps, textures, libft.h, ft_*.c | NAME, all, clean, fclean, re | A map in format *.ber | Detailed below | yes | You must create a basic 2D game in which a dolphin escapes Earth after eating some fish.  Instead of a dolphin, fish, and the Earth, you can use any character, any collectible and any place you want. |

### External Functions
* open, close, read, write, malloc, free, perror, strerror, exit
* All functions of the math library (-lm compiler option, man man 3 math)
* All functions of the MiniLibX
* ft_printf and any equivalent YOU coded

## Compiling
* Clone project with sub modules: `git clone --recursive git@github.com:hamza-cskn/42-so_long.git`
* Go the project folder and build it: `cd 42-so_long/ && make`
* Run the executable: `./solong`
