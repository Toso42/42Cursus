/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pepiro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:05:58 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:06:05 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PEPIRO_H
# define PEPIRO_H
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define WIN_WIDTH 600
# define WIN_HEIGHT 300
# define RED 0XFF0000
# define WHITE 0XFFFFFF

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

// pep frames: [0] D0 | [1] D1 | [2] A0 | [3] A1 | [4] W0 | [5] W1 |
// [6] S0 | [7] S1
typedef struct s_obj
{
	int		exist;
	clock_t	last;
	int		moves;
	int		frame;
	int		y;
	int		x;
	int		movingy;
	int		movingx;
}	t_obj;

// counters: [0]: Collectibles | [1]: Player | [2]: Exits | [3]: Collect. left
// | [4]: patrols
typedef struct s_variables
{
	int		debug;
	void	*mlx_ptr;
	void	*win_ptr;
	clock_t	start_t;
	clock_t	current_t;
	clock_t	patrolinterval;
	clock_t	won;
	clock_t	lost;
	char	*map_path;
	int		map_fd;
	char	*map_string;
	char	**map_matrix;
	char	*itoa_moves;
	int		matrix_y;
	int		matrix_x;
	int		tilesize;
	int		winning;
	int		loosing;
	t_obj	*collectible_array;
	t_obj	*exits_array;
	t_obj	*patrols;
	t_obj	player;
	int		*counters;
	t_img	wall;
	t_img	floor;
	t_img	exit;
	t_img	per;
	t_img	pep0;
	t_img	pep1;
	t_img	pat0;
	t_img	pat1;
	t_img	fgm;
	t_img	fbm;
}	t_var;

//objects.c
void	ft_obj_count(t_var *box, char *line, int x);
void	ft_createobjects(t_var *box);
void	ft_parsemap(t_var *box);
//objects2.c
void	ft_addc(t_var *box, int x, int y, int c);
void	ft_adde(t_var *box, int x, int y, int e);
//mapchecks.c
int		ft_mapchecks(t_var *box, int y);
//map.c
void	ft_hashmap(t_var *box, char what, int x, int y);
void	ft_printmap(t_var *box);
int		ft_createmap(t_var *box);
//rendering.c
void	ft_hashsprites(t_var *box, char what, int x, int y);
void	ft_printsprites(t_var *box);
int		ft_render(t_var *box);
//inits.c
int		ft_loadimages(t_var *box);
int		ft_inithooks(t_var *box);
int		ft_init(t_var *box, char **topo);
//handlers.c
int		ft_handle_closewin(t_var *box);
int		ft_handle_keypress(int key, t_var *box);
//pepiro.c
void	ft_quit(t_var *box);
//prints.c
void	ft_print_patrols(t_var *box);
void	ft_print_collectibles(t_var *box);
void	ft_print_exits(t_var *box);
void	ft_print_moves(t_var *box);
//prints2.c
void	ft_printmatrixcell(t_var *box, int y, int x);
void	ft_printwall(t_var *box, int y, int x);
void	ft_printfloor(t_var *box, int y, int x);
void	ft_printexit(t_var *box, int y, int x);
void	ft_putpep(t_var *box);
//loadimages.c
int		ft_loadimages(t_var *box);
//conditions.c
void	ft_win(t_var *box);
void	ft_lost(t_var *box);
int		ft_exit_condition(t_var *box);
int		ft_random(int min, int max, int range);
#endif
