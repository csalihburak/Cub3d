/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:56:46 by scoskun           #+#    #+#             */
/*   Updated: 2022/10/04 15:35:50 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	norm_mini_map(t_cub3d *data, int px, int py, int i)
{
	int	j;

	j = -1;
	while (data->img_s->cub[++j])
	{
		i = -1;
		while (data->img_s->cub[j][++i])
		{
			if (data->img_s->cub[j][i] == '1')
				put_ch(data, px, py, 0);
			else if (data->img_s->cub[j][i] == data->orientation)
				put_ch(data, px, py, 1);
			else if (data->img_s->cub[j][i] == '0')
				put_ch(data, px, py, 2);
			if (data->img_s->cub[j][i + 1] == '\0')
				py += data->alen * 4;
			px += 4;
		}
	}
}

int	mini_map(t_cub3d *data)
{
	if (data->m)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->new, 0, 0);
	}
	return (1);
}

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
			data->screen_img_data[y * data->witdh + x] = data->img_s->floor;
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
		data->screen_img_data[y * data->witdh + x] = data->img_s->ceilling;
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
		if (map->side == 1)
			map->colour = (map->colour >> 1) & 8355711;
		data->screen_img_data[a * data->witdh + i] = map->colour;
		a++;
	}
}
