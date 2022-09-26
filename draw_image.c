/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:56:46 by scoskun           #+#    #+#             */
/*   Updated: 2022/09/26 18:39:51 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//28 800

void	mini_map(t_cub3d *data, t_img *map)
{
	void	*mmap;
	int		*dat;
	int		i;
	int		j;
	int		k;
	int 	px;
	int		py;
	
	i = 0;
	j = 0;
	k = 0;
	px = 0;
	py = 0;
	map->alen = 1;
	mmap = mlx_new_image(data->mlx, 75, 150);
	dat = (int *)mlx_get_data_addr(mmap, &data->bit_per_px, &data->size_line, &data->endian);
	while(i < (75 * 150))
	{
		dat[i] = 0x2C3E50;
		i++;
	}
	i = 0;
	mlx_put_image_to_window(data->mlx, data->win, mmap, 0, 0);
	while(map->map[i])
	{
		if (map->map[i] == '1')
		{
			mlx_pixel_put(data->mlx, data->win,  px + 5 , py + 5, 0xFE0000);
/* 			mlx_pixel_put(data->mlx, data->win,  px , py + 1, 255);
			mlx_pixel_put(data->mlx, data->win,  px + 1 , py + 1, 255); */
			px++;
		}
		else if (map->map[i] == '\n')
		{
			px = 0;
			py += 5;
		}
		else if (map->map[i] == 'N')
		{
			mlx_pixel_put(data->mlx, data->win,  px + 10, py + 5, 121425);
			px++;
		}
		else if (map->map[i] == '0')
			px += 1;
		i++;
	}
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
			data->screen_img_data[y * data->witdh + x] = 0xBBD1E6;
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
		data->screen_img_data[y * data->witdh + x] = 0x212F3D;
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
