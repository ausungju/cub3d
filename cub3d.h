/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/07 13:16:15 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <errno.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx_linux/mlx.h"

# define WIDTH		1600
# define HEIGHT		1200
# define TEX_SIZE	16
# define WS			15
# define MG			10

# define N_COLOR	0xFFA500
# define S_COLOR	0x0000FF
# define E_COLOR	0xFF0000
# define W_COLOR	0x00FF00

# define PI			3.14159265358979323846

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

typedef struct s_player
{
	t_fpoint	point;
	t_fpoint	dir;
	t_fpoint	plane;
}	t_player;

typedef struct s_cub3d
{
	t_player	player;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	void		*texture[8];
	char		*texture_addr[8];
	char		**map;
	char		map_x;
	char		map_y;
	int			bits_pixel;
	int			line_length;
	int			endian;
	int			bits_pixel_tex;
	int			line_length_tex;
	int			endian_tex;
}	t_data;

// draw_map.c
void		set_dda_map_var(t_fpoint pos, t_fpoint rayDir, \
				t_data *data, t_dda *dda);
void		dda_line(t_fpoint pos, t_fpoint rayDir, int color, t_data *data);
void		draw_rader(t_data *data);
void		draw_map(t_data *data);

// draw_cam.c
void		set_dda_wall_var(int x, t_fpoint	pos, t_data *data, t_dda *dda);
void		dda_wall(int x, t_dda *dda, t_data *data);
void		draw_wall(int x, t_fpoint pos, t_data *data);
void		draw_cam(t_data *data);

// draw_utils.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		re_draw(t_data *data);
void		set_dda_var_with_raydir(t_fpoint rayDir, t_fpoint pos, t_dda *dda);
int			select_color(int x, int y, t_dda *dda, t_data *data);
int			draw_texture(int x, t_dda *dda, t_data *data);

// event.c
int			move_envet(int key_code, t_data *data);
int			key_event(int key_code, t_data *data);

// ft_math.c
void		copy_fpoint(t_fpoint *f1, t_fpoint *f2);
double		rad(double angle);
void		rotate(t_fpoint *point, double angle);
double		get_deg(t_fpoint *dir);

// mlx_func.c
t_data		*init_data(int argc, char **argv);
void		parse_argv(char *file_name, t_data *data);
void		parse_error(t_data *data);
int			call_exit(t_data *data);
t_fpoint	*get_player_point(t_fpoint *point, int val, t_data *data);
t_fpoint	*point_locate_map(t_fpoint *point);


void		init_texture(t_data *data);

#endif