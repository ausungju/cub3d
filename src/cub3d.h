/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/08 06:26:09 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include "type.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx_linux/mlx.h"

// draw
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	get_texture_color(int x, int y, int num, t_data *data);
int				draw_texture(int x, t_dda *dda, t_data *data);
void			draw_cam(t_data *data);
void			draw_map(t_data *data);

// parsing
char			*gnl_pass_empty_line(int fd, int is_insert_nl);
char			*pass_space(char *line);
char			*get_element(int id, char **line);
int				check_character(char c);

void			set_map_size(t_data *data);
void			set_and_verify_map(t_data *data);

int				select_parameter(char **line, t_data *data);
void			set_color(int id, char *line, t_data *data);
void			set_texture(int id, char *line, t_data *data);
void			file_parsing(char *file_path, t_data *data);
t_data			*init_data(int argc, char **argv);

// utils
void			copy_fpoint(t_fpoint *f1, t_fpoint *f2);
void			copy_point(t_point *f1, t_point *f2);
double			rad(double angle);
void			rotate(t_fpoint *point, double angle);
double			get_deg(t_fpoint *dir);

t_fpoint		*get_player_point(t_fpoint *point, int scope, t_data *data);
void			point_locate_map(t_point *dest, t_fpoint *point);
void			parse_error(t_data *data);
int				call_exit(t_data *data);
int				get_strarr_size(char **ptr);

// event.c
void			re_draw(t_data *data);
int				move_envet(int key_code, t_data *data);
int				key_event(int key_code, t_data *data);

#endif