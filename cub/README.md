# Cub3d

Cub3d is a project about recreating Wolfenstein3d 2.5d engine. The window instance
for the project is handled by the Minilibx, a didactic game engine making use
of the X11 library.

Bresenham and DDA algorithm were implemented in the realization of this project.
Currently, this project is compatible with MACOs's only. It is my plan
to make it compatible with linux in the near future, with a deep refactoring
presenting the code in a more polite form. A barebones collision system is implemented
for player movements: Even though the current collision system is not perfectly optimized,
this Cub is highly performant.

From an optimization perspective, the 42 subject make it so that floating numbers
are used to store and represent vectors in the game, making it difficult to implement
fixed point math. Fast square root algorithms are aswell not easy to implement at this
stage, but i plan to rewrite and optimize this project as soon as i complete the
42 common core projects.

A deep thanks goes to Mmarinel ( https://github.com/mmarinel ), whose skills and
dedication have been a constant source of inspiration for me. Please make sure
to check his amazing work.
