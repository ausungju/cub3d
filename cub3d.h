/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/07 21:18:44 by seongkim         ###   ########.fr       */
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
	t_tex_info	*texture[5];
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	char		**map;
	char		map_x;
	char		map_y;
	int			bits_pixel;
	int			line_length;
	int			endian;

}	t_data;

void			draw_map(t_data *data);

// draw_cam.c
void			set_dda_wall_var(int x, t_fpoint	pos, t_data *data, \
					t_dda *dda);
void			dda_wall(int x, t_dda *dda, t_data *data);
void			draw_wall(int x, t_fpoint pos, t_data *data);
void			draw_cam(t_data *data);

// draw_utils.c
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			set_dda_var_with_raydir(t_fpoint rayDir, t_fpoint pos, \
					t_dda *dda);
int				draw_texture(int x, t_dda *dda, t_data *data);
unsigned int	get_texture_color(int x, int y, int num, t_data *data);

// event.c
void			re_draw(t_data *data);
int				move_envet(int key_code, t_data *data);
int				key_event(int key_code, t_data *data);

// ft_math.c
void			copy_fpoint(t_fpoint *f1, t_fpoint *f2);
void			copy_point(t_point *f1, t_point *f2);
double			rad(double angle);
void			rotate(t_fpoint *point, double angle);
double			get_deg(t_fpoint *dir);

// mlx_func.c
t_data			*init_data(int argc, char **argv);
void			parse_argv(char *file_name, t_data *data);
void			point_locate_map(t_point *dest, t_fpoint *point);

t_fpoint		*get_player_point(t_fpoint *point, int val, t_data *data);
void			get_map_size(t_data *data);
void			parse_error(t_data *data);
int				call_exit(t_data *data);

void			init_textures(t_data *data);

#endif