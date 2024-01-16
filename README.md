
# Cub3D

## Overview
Cub3D is a project inspired by the famous 90's game "Wolfenstein 3D", considered to be the first true first-person shooter. The goal is to create a dynamic view inside a maze using a technique called ray-casting. The project is part of the 42 School curriculum, aimed at introducing students to graphics programming and deepening their understanding of 2D and 3D rendering.

## Features
- Ray-casting to render a 3D maze from a 2D map.
- Wall collision detection.
- Texture mapping for walls.
- Simple sprite rendering.
- Basic controls to move forward, backward, and rotate the view.

## Usage

### Compilation
To compile Cub3D, run:
```bash
gcc -Wall -Wextra -Werror *.c -o cub3D -lmlx -framework OpenGL -framework AppKit
```

### Running the Program
To start the game, run:
```bash
./cub3D map_file.cub
```
Replace `map_file.cub` with the path to your map configuration file.

## Map Configuration
The map configuration file (`*.cub`) specifies the layout of the maze, wall textures, sprite textures, and other settings.

## Controls
- `W`/`A`/`S`/`D` to move.
- Left and right arrow keys to rotate the view.
- `ESC` to exit the game.

## Notes
- The project requires a thorough understanding of the ray-casting technique.
- Attention to detail is important for accurate rendering and collision detection.
- Performance optimization can be a crucial aspect of the project.

