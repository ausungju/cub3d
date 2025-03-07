/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/08 06:25:03 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# define NO			0
# define SO			1
# define WE			2
# define EA			3
# define FA			4
# define F			5
# define C			6

# define WIDTH		1600
# define HEIGHT		1200
# define WS			15
# define MG			10

# define N_COLOR	0xFFA500
# define S_COLOR	0x0000FF
# define E_COLOR	0xFF0000
# define W_COLOR	0x00FF00

# define PI			3.14159265358979323846

# define TRUE		1
# define FALSE		0

# define MS			1000

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
	int		num;
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
	int			side;
	int			draw_start;
	int			draw_end;
	int			tex_x;
}	t_dda;

typedef struct s_cub3d
{
	t_player	player;
	t_tex_info	**texture;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	char		**map;
	int			*map_x;
	int			map_y;
	int			bits_pixel;
	int			line_length;
	int			endian;
	int			floor;
	int			ceiling;
	t_time		time;
}	t_data;

#endif