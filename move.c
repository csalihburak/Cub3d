/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:11:17 by scoskun           #+#    #+#             */
/*   Updated: 2022/10/04 14:22:24 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_ch(t_cub3d *data, int flag, float px, float py)
{
	if (flag == 0)
		data->img_s->cub[(int)px][(int)py] = '0';
	else
	{
		data->img_s->cub[(int)px][(int)py] = data->orientation;
		norm_mini_map(data, 0, 0, -1);
	}
}

void	move_back(t_cub3d *data, t_img *map)
{
	update_ch(data, 0, data->px, data->py);
	if (map->cub[(int)(data->px - data->rx * data->move_speed)] \
	[(int)data->py] == '0' || map->cub[(int)(data->px - data->rx * \
	data->move_speed)][(int)data->py] == data->orientation)
		data->px -= data->rx * data->move_speed;
	if (map->cub[(int)data->px][(int)(data->py - data->ry * \
	data->move_speed)] == '0' || map->cub[(int)data->px] \
	[(int)(data->py - data->ry * data->move_speed)] == data->orientation)
		data->py -= data->ry * data->move_speed;
	update_ch(data, 1, data->px, data->py);
}

void	move_forward(t_cub3d *data, t_img *map)
{
	if (data->key_w)
	{
		update_ch(data, 0, data->px, data->py);
		if (map->cub[(int)(data->px + data->rx * data->move_speed)] \
		[(int)data->py] == '0' || map->cub[(int)(data->px + data->rx * \
		data->move_speed)][(int)data->py] == data->orientation)
			data->px += data->rx * data->move_speed;
		if (map->cub[(int)data->px][(int)(data->py + \
		data->ry * data->move_speed)] == '0' || map->cub[(int)data->px] \
		[(int)(data->py + data->ry * data->move_speed)] == data->orientation)
			data->py += data->ry * data->move_speed;
		update_ch(data, 1, data->px, data->py);
	}
	else if (data->key_s)
		move_back(data, map);
}

int	move(int key, t_cub3d *data)
{
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
	if (data->key == 49)
		data->key_b = 0;
	if (data->key == 19)
		data->key_r = 0;
	return (0);
}
