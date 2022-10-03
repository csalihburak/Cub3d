/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:56:46 by scoskun           #+#    #+#             */
/*   Updated: 2022/10/03 18:59:30 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	norm_mini_map(t_cub3d *data, int px, int py, int i)
{
	while (data->img_s->map[++i])
	{
		if (data->img_s->map[i] == '1')
		{
			data->new_da[px + py] = 0xF39C12;
			px += 4;
		}
		else if (data->img_s->map[i] == '\n')
			py += data->alen * 4;
		else if (data->img_s->map[i] == data->orientation)
		{
			data->new_da[px + py] = 0x20A9A9;
			px += 4;
		}
		else if (data->img_s->map[i] == '0')
			px += 4;
	}
}

int	mini_map(t_cub3d *data)
{
	if (data->m)
	{
		data->new = mlx_new_image(data->mlx, data->alen, data->blen);
		data->new_da = (int *)mlx_get_data_addr(data->new, &data->bit_per_px, \
		&data->size_line, &data->endian);
		norm_mini_map(data, 0, 0, -1);
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
