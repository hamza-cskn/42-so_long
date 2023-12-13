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

## Image
<img width="1090" src="https://github.com/hamza-cskn/42-so_long/assets/36128276/4e591b8b-bf90-4971-bab6-b335284cc525">

## Map
Maps can be added or edited. The game will read the maps folder. Please feel free to look over example maps in the repository. Each character (except newlines) in the map file represents a square in the game.

* P -> Player
* 1 -> WALL
* 0 -> EMPTY (I call them GRASS)
* C -> COLLECTIBLE (Strawberries)
* E -> EXIT

All maps must meet these requirements to be valid and playable.
1. Must be rectangular.
2. Must be surrounded by walls.
3. Must contain only one exit location. (No more or less)
4. Must contain only one player location. (No more or less)
5. At least one possible way must exist to reach all collectibles and the exit location. (The map must be finishable.)

## Compiling
* Clone project with sub modules: `git clone --recursive git@github.com:hamza-cskn/42-so_long.git`
* Go the project folder and build it: `cd 42-so_long/ && make`
* Run the executable: `./so_long <map name>`
