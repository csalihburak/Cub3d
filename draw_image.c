/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:56:46 by scoskun           #+#    #+#             */
/*   Updated: 2022/09/23 15:57:22 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_roof(t_cub3d *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->witdh)
	{
		y = 0;
		while (y < data->height / 2)
		{
			data->screen_img_data[y * data->witdh + x] = data->img_s->ceilling;
			y++;
		}
		x++;
	}
}

void	print_ground(t_cub3d *data)
{
	int	x;
	int	y;

	x = 0;
	y = data->height / 2;
	while (x < data->witdh && y < data->height)
	{
		data->screen_img_data[y * data->witdh + x] = data->img_s->floor;
		x++;
		if (x == data->witdh)
		{
			x = 0;
			y++;
		}
	}
}

void	draw_image(t_cub3d *data, t_img *map, int i)
{
	int	a;

	a = map->draw_start;
	while (a < map->draw_end)
	{
		map->my = (int)map->pixel_nbr & (data->img_height - 1);
		map->pixel_nbr += map->pixel_cal;
		if (map->raydirx > 0 && map->side != 1)
			map->colour = map->so_data[data->img_height * map->my + map->mx];
		else if (map->raydirx < 0 && map->side != 1)
			map->colour = map->no_data[data->img_height * map->my + map->mx];
		else if ((map->raydirx <= 2 && map->raydiry >= 0) && map->side == 1)
			map->colour = map->ea_data[data->img_height * map->my + map->mx];
		else
			map->colour = map->we_data[data->img_height * map->my + map->mx];
		data->screen_img_data[a * data->witdh + i] = map->colour;
		a++;
	}
}
