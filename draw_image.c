/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:56:46 by scoskun           #+#    #+#             */
/*   Updated: 2022/09/29 19:54:20 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	norm_mini_map(t_cub3d *data, int px, int py, int i)
{
	while (data->img_s->map[++i])
	{
		if (data->img_s->map[i] == '1')
		{
			mlx_pixel_put(data->mlx, data->win, px, py, 0xFE0021);
			mlx_pixel_put(data->mlx, data->win, px + 1, py, 0xFE0021);
			mlx_pixel_put(data->mlx, data->win, px, py, 0xFE0021);
			px += 4;
		}
		else if (data->img_s->map[i] == '\n')
		{
			px = 0;
			py += 6;
		}
		else if (data->img_s->map[i] == 'N' || data->img_s->map[i] == 'S' || \
		data->img_s->map[i] == 'W' || data->img_s->map[i] == 'E')
		{
			mlx_pixel_put(data->mlx, data->win, data->px + 100, \
			data->py + 100, 0xFE324);
			px += 4;
		}
		else if (data->img_s->map[i] == '0')
			px += 4;
	}
}

int	mini_map(int key, t_cub3d *data)
{
	if (key == 46)
	{
		void	*mmap;
		int		*dat;
		int		i;

		i = -1;
		mmap = mlx_new_image(data->mlx, data->alen, data->blen + 1);
		dat = (int *)mlx_get_data_addr(mmap, &data->bit_per_px, \
		&data->size_line, &data->endian);
		while (++i < (data->alen * data->blen))
			dat[i] = 3546757;
		mlx_put_image_to_window(data->mlx, data->win, mmap, 0, 0);
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
			data->screen_img_data[y * data->witdh + x] = 0xABB2B9;
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
		data->screen_img_data[y * data->witdh + x] = 0x273746;
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
		if(map->side == 1) 
			map->colour = (map->colour >> 1) & 8355711;
		data->screen_img_data[a * data->witdh + i] = map->colour;
		a++;
	}
}
