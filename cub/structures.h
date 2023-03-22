/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   structures.h									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tdi-leo <tdi-leo@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/13 10:50:22 by tdi-leo		   #+#	#+#			 */
/*   Updated: 2023/03/13 10:50:33 by tdi-leo		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_mapfill
{
	int	max_len;
	int	map_height;
	int	x;
	int	y;
	int	cur_len;
}	t_mapfill;

typedef struct s_key
{
	int	key_up;
	int	key_down;
	int	key_right;
	int	key_left;
	int	key_esc;
	int	key_sidel;
	int	key_sider;
}	t_key;

typedef struct s_immage
{
	void	*img;
	int		*data;

	int		img_w;
	int		img_h;
	int		bpp;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

// struct to hold RGB values
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

//game.d.h.timg
typedef struct s_hitpoint
{
	t_point	true_ray;
	t_point	normal_ray;
	t_point	pladir_dil;
	t_point	hit;
	t_point	texture;
	t_img	*timg;
	double	tray_mod;
	double	perp_dist;
	int		color;
	int		side;

}	t_hitpoint;

// game.d.h
typedef struct s_dda
{
	t_point		result;
	t_hitpoint	*h;
	double		w_cursor;
	double		fraction;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
	int			side;
	int			hit;
	int			wallcursor;
	int			wallheight;
	double		stepx;
	double		stepy;
	double		mapx;
	double		mapy;
	double		euclide;

}	t_dda;

// struct to hold textures and map references
//maparray
//floor
//ceiling
//ntexture
//stexture
//wtexture
//etexture
typedef struct s_map
{
	void	*ntexture;
	void	*stexture;
	void	*wtexture;
	void	*etexture;
	t_rgb	*floor;
	t_rgb	*ceiling;
	char	**maparray;
	int		width;
	int		height;
	double	wall_step;
}	t_map;

typedef struct s_minimap
{
	int		minimap_w;
	int		minimap_h;
	int		tilesize;
	int		color;
}	t_minimap;

//game.player.plap
typedef struct s_player
{
	int			initial_direction;
	t_point		pos;
	t_point		pos_reset;
	t_point		dir;
	double		pla_dist;
	t_point		pla_dir;
	t_point		*plap;
	double		mov_step;
	double		rot_step;
	double		side_step;
}	t_player;

typedef struct s_bresenhams
{
	int	dx;
	int	dy;
	int	decide;
	int	color;
	int	pk;
	int	swap;
}	t_bresenhams;

//game.map
//game.window_instance
//game.mlx_instance
typedef struct s_mlx
{
	void			*mlx_instance;
	void			*window_instance;
	t_map			*map;
	t_minimap		minimap;
	t_img			img;
	t_img			walln;
	t_img			walls;
	t_img			wallw;
	t_img			walle;
	int				skycolor;
	int				floorcolor;
	t_player		player;
	t_player		miniplayer;
	t_key			key;
	t_dda			d;
	t_dda			movd;
	t_bresenhams	b;
	clock_t			lastep;
	clock_t			ctime;
}	t_mlx;

#endif