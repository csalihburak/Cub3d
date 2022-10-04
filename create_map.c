/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:47:59 by scoskun           #+#    #+#             */
/*   Updated: 2022/10/04 14:05:16 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wallcheck(t_cub3d *data, t_img *map)
{
	if (map->raydirx < 0)
	{
		map->step_x = -1;
		map->sidedist_x = (data->px - map->mapx) * map->deltadist_x;
	}
	else
	{
		map->step_x = 1;
		map->sidedist_x = (map->mapx + 1.0 - data->px) * map->deltadist_x;
	}
	if (map->raydiry < 0)
	{
		map->step_y = -1;
		map->sidedist_y = (data->py - map->mapy) * map->deltadist_y;
	}
	else
	{
		map->step_y = 1;
		map->sidedist_y = (map->mapy + 1.0 - data->py) * map->deltadist_y;
	}
}

void	hitcheck(t_img *map)
{
	while (map->hit == 0)
	{
		if (map->sidedist_x < map->sidedist_y)
		{
			map->sidedist_x += map->deltadist_x;
			map->mapx += map->step_x;
			map->side = 0;
		}
		else
		{
			map->sidedist_y += map->deltadist_y;
			map->mapy += map->step_y;
			map->side = 1;
		}
		if (map->cub[map->mapx][map->mapy] == '1')
			map->hit = 1;
	}
}

void	get_dist(t_cub3d *data, t_img *map)
{
	if (map->side == 0)
		map->wall_dist = (map->mapx - data->px + (1 - map->step_x) \
		/ 2) / map->raydirx;
	else
		map->wall_dist = (map->mapy - data->py + (1 - map->step_y) \
		/ 2) / map->raydiry;
	map->line_height = (int)(data->height / map->wall_dist);
	map->draw_start = -map->line_height / 2 + data->height / 2;
	if (map->draw_start < 0)
		map->draw_start = 0;
	map->draw_end = map->line_height / 2 + data->height / 2;
	if (map->draw_end >= data->height)
	{
		map->draw_end = data->height - 1;
		data->flag = 1;
	}
}

void	set_image_values(t_cub3d *data, t_img *map)
{
	map->next_idx = map->cub[map->mapx][map->mapy];
	if (map->side == 0)
		map->wallx = data->py + map->wall_dist * map->raydiry;
	else
		map->wallx = data->px + map->wall_dist * map->raydirx;
	map->wallx -= floor(map->wallx);
	map->mx = (int)(map->wallx * (double)data->img_width);
	if (map->side == 0 && map->raydirx > 0)
		map->mx = data->img_width - map->mx - 1;
	if (map->side == 1 && map->raydiry < 0)
		map->mx = data->img_width - map->mx - 1;
	map->pixel_cal = 1.0 * data->img_height / map->line_height;
	map->pixel_nbr = (map->draw_start - data->height / 2 + map->line_height \
	/ 2) * map->pixel_cal;
}

void	print_img(t_cub3d *data, t_img *map)
{
	int	i;

	i = 0;
	while (i < data->witdh)
	{
		map->camx = (2 * i / (double)data->witdh - 1);
		map->raydirx = data->rx + data->viewx * map->camx;
		map->raydiry = data->ry + data->viewy * map->camx;
		map->mapx = (int)data->px;
		map->mapy = (int)data->py;
		map->deltadist_x = fabs(1 / map->raydirx);
		map->deltadist_y = fabs(1 / map->raydiry);
		map->hit = 0;
		wallcheck(data, map);
		hitcheck(map);
		get_dist(data, map);
		set_image_values(data, map);
		draw_image(data, map, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->screen_img, 0, 0);
	put_guns(data);
	mini_map(data);
}
