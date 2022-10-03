/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:11:17 by scoskun           #+#    #+#             */
/*   Updated: 2022/10/03 19:01:18 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_guns2(t_cub3d *data)
{
	if (!data->key_b)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->aim, 300, 500);
		mlx_put_image_to_window(data->mlx, data->win, data->aim2, 950, 600);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, data->aim, 300, 450);
		mlx_put_image_to_window(data->mlx, data->win, data->aim2, 950, 500);
	}
}

void	put_guns(t_cub3d *data)
{
	if (data->key_r)
	{
		if (!data->key_b)
		{
			mlx_put_image_to_window(data->mlx, data->win, \
			data->aim2, 1030, 600);
			mlx_put_image_to_window(data->mlx, data->win, data->grana, 50, 200);
		}
		else
		{
			mlx_put_image_to_window(data->mlx, data->win, \
			data->grana, 1090, 600);
			mlx_put_image_to_window(data->mlx, data->win, data->aim2, 50, 400);
		}	
	}
	else
		put_guns2(data);
}

void	move_forward_backward(t_cub3d *data, t_img *map)
{
	if (data->key_w)
	{
		if (map->cub[(int)(data->px + data->rx * data->move_speed)] \
		[(int)data->py] == '0' || map->cub[(int)(data->px + data->rx * \
		data->move_speed)][(int)data->py] == data->orientation)
			data->px += data->rx * data->move_speed;
		if (map->cub[(int)data->px][(int)(data->py + \
		data->ry * data->move_speed)] == '0' || map->cub[(int)data->px] \
		[(int)(data->py + data->ry * data->move_speed)] == data->orientation)
			data->py += data->ry * data->move_speed;
	}
	else if (data->key_s)
	{
		if (map->cub[(int)(data->px - data->rx * data->move_speed)] \
		[(int)data->py] == '0' || map->cub[(int)(data->px - data->rx * \
		data->move_speed)][(int)data->py] == data->orientation)
			data->px -= data->rx * data->move_speed;
		if (map->cub[(int)data->px][(int)(data->py - data->ry * \
		data->move_speed)] == '0' || map->cub[(int)data->px] \
		[(int)(data->py - data->ry * data->move_speed)] == data->orientation)
			data->py -= data->ry * data->move_speed;
	}
}

int	move(int key, t_cub3d *data)
{
	printf("%d\n", key);
	if (key == 53)
		exit(1);
	if (key == 13)
		data->key_w = 0;
	if (key == 1)
		data->key_s = 0;
	if (key == 123 || key == 0)
		data->key_a = 0;
	if (key == 2 || key == 124)
		data->key_d = 0;
	if (data->key == 46)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->new, 0, 0);
		data->m = 0;
	}
	if (data->key == 49)
		data->key_b = 0;
	if (data->key == 19)
		data->key_r = 0;
	return (0);
}
