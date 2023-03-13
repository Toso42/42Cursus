/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:31:58 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 16:46:25 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <string.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "src/init/init.h"
# include "src/img/img.h"
# include "src/utils/utils.h"
# include "src/handlers/handlers.h"
# include "src/loop/loop.h"
# include "structures.h"

# define W_WIDTH		1280
# define W_HEIGHT		1024
# define WALL_SIZE		420
# define TEXT_SIZE		420
# define KEY_PRESS		2
# define KEY_RELEASE	3
# define KEY_EXIT		17
// WASD
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
//Keyboard ARROWS
# define K_AR_L			123
# define K_AR_R			124
# define K_AR_U			126
# define K_AR_D			125
//ESC key
# define K_ESC 53
//COLORS
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0x008000
# define BLUE			0x0000FF
# define DARKRED		0x8F0000
# define WALLN			0x6C0000
# define WALLS			0x9D0000
# define WALLW			DARKRED
# define WALLE			0x600000

enum	e_bool
{
	FALSE,
	TRUE
};

enum	e_cardinalp
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

#endif
