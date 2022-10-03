/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:23:47 by agunes            #+#    #+#             */
/*   Updated: 2022/10/03 18:56:39 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct s_img
{
	int		alen;
	int		blen;
	int		floor;
	int		ceilling;
	void	*so;
	void	*ea;
	void	*no;
	void	*we;
	void	*p;
	double	camx;
	double	raydirx;
	double	raydiry;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wallx;
	double	pixel_cal;
	double	pixel_nbr;
	char	**cub;
	char	*map;
	int		**wmap;
	int		*ea_data;
	int		*no_data;
	int		*we_data;
	int		*so_data;
	int		mx;
	int		my;
	int		colour;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		next_idx;
}	t_img;

typedef struct s_cub3d
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*screen_img;
	void			*img2;
	void			*aim;
	void			*aim2;
	void			*new;
	void			*grana;
	double			px;
	double			py;
	double			rx;
	double			ry;
	double			viewx;
	double			viewy;
	double			move_speed;
	double			rotate_speed;
	double			old;
	double			old2;
	int				alen;
	int				blen;
	int				*img_data;
	int				*img_data2;
	int				*new_da;
	int				img_width;
	int				img_height;
	int				*screen_img_data;
	int				img_x;
	int				img_y;
	int				bit_per_px;
	int				size_line;
	int				endian;
	int				witdh;
	int				height;
	int				flag;
	int				i;
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_a;
	int				key_b;
	int				key_r;
	int				key;
	int				m;
	int				flag1;
	char			*map_name;
	char			orientation;
	struct s_img	*img_s;
}	t_cub3d;

char	*merge(char **map);
char	*deletechar(char *array, char c);
int		setupgame(t_cub3d *cub3d);
int		parsemap(t_cub3d *cub3d, char **argv);
int		dbfree(char **array);
int		mlx_start(t_cub3d *cub3d);
int		preimg(t_cub3d *cub3d);
int		main_loop(t_cub3d *data);
int		move(int key, t_cub3d *data);
int		aim(int key, t_cub3d *data);
int		move2(int key, t_cub3d *data);
int		move_norm(t_cub3d *data);
int		checkgamemap(t_cub3d *cub3d);
int		checkimg(t_cub3d *cub3d);
int		mini_map(t_cub3d *data);
int		ft_strcmp(char *s1, char *s2);
int		cubcheck(char *s);
int		get_pos2(t_cub3d *data);
void	jumpspace(t_cub3d *cub3d);
void	freeprefc(t_cub3d *cub3d, char **buff, int i);
void	draw_image(t_cub3d*data, t_img *map, int i);
void	print_img(t_cub3d *data, t_img *map);
void	print_roof(t_cub3d *data);
void	print_ground(t_cub3d *data);
void	get_pos(t_cub3d *data);
void	set_values(t_cub3d *data);
void	get_map_size(t_cub3d *data, t_img *map);
void	move_forward_backward(t_cub3d *data, t_img *map);
void	put_guns(t_cub3d *data);
#endif