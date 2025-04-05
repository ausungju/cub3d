/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/30 19:40:05 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# define NO				0
# define SO				1
# define WE				2
# define EA				3
# define F				7
# define C				8

# define SPACE			'0'
# define WALL			'1'

# define WIDTH			1200
# define HEIGHT			900
# define WS				7
# define MG				10
# define MOVE_SPEED		0.0511f
# define MOVE_CHECK		0.0611f
# define TEXTURE_SPEED	0.08f

# define N_COLOR		0xFFA500
# define S_COLOR		0x0000FF
# define E_COLOR		0xFF0000
# define W_COLOR		0x00FF00

# define PI				3.14159265358979323846

# define TRUE			1
# define FALSE			0

# define MS				1000
# define K_DEFALT_SLEEP	5

typedef struct timeval	t_time;

typedef struct s_fpoint
{
	double	x;
	double	y;
}	t_fpoint;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_tex_info
{
	void	*img;
	char	*addr;
	int		x;
	int		y;
	int		max_y;
	int		num;
	int		bits_pixel;
	int		line_length;
	int		endian;
}	t_tex_info;

typedef struct s_player
{
	t_fpoint	point;
	t_fpoint	dir;
	t_fpoint	plane;
	char		char_dir;
}	t_player;

typedef struct s_draw_tex
{
	double	step;
	double	tex_pos;
	int		n;
	int		tex_x;
}	t_draw_tex;

typedef struct s_dda
{
	t_fpoint	side_dist;
	t_fpoint	delta_dist;
	t_fpoint	ray_dir;
	t_fpoint	pos;
	t_point		map;
	t_point		step;
	double		perp_wall_dist;
	int			line_weight;
	int			hit;
	int			side;
	int			draw_start;
	int			draw_end;
}	t_dda;

typedef struct s_cub3d
{
	t_player	player;
	t_tex_info	**texture;
	void		*mlx;
	void		*win;
	void		*img;
	void		*item;
	char		*addr;
	char		**map;
	int			*map_x;
	int			map_y;
	int			bits_pixel;
	int			line_length;
	int			endian;
	int			floor;
	int			ceiling;
	int			sleep_time;
	int			item_x;
	int			item_y;
	double		ani_val;
	t_time		key_time;
}	t_data;

#endif