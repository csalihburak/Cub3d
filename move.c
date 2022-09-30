/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:11:17 by scoskun           #+#    #+#             */
/*   Updated: 2022/09/30 18:07:10 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	getx(char *map, char a)
{
	int	i;

	i = -1;
	while(map[++i])
	{
		if (map[i] == a)
			return (i);
	}
	return (0);
}

void	move_forward_backward(int key, t_cub3d *data)
{
	key = 0;
	if (data->key_w)
	{
		if (data->img_s->cub[(int)(data->px + data->rx * data->move_speed)][(int)data->py] == '0' || data->img_s->cub[(int)(data->px + data->rx * \
		data->move_speed)][(int)data->py] == data->orientation)
			data->px += data->rx * data->move_speed;
		if (data->img_s->cub[(int)data->px][(int)(data->py + \
		data->ry * data->move_speed)] == '0' || data->img_s->cub[(int)data->px][(int)(data->py + \
		data->ry * data->move_speed)] == data->orientation)
			data->py += data->ry * data->move_speed;
	}
	else if (data->key_s)
	{
		if (data->img_s->cub[(int)(data->px - data->rx * \
		data->move_speed)][(int)data->py] == '0' || data->img_s->cub[(int)(data->px - data->rx * \
		data->move_speed)][(int)data->py] == data->orientation)
			data->px -= data->rx * data->move_speed;
		if (data->img_s->cub[(int)data->px][(int)(data->py - data->ry * \
		data->move_speed)] == '0' || data->img_s->cub[(int)data->px][(int)(data->py - data->ry * \
		data->move_speed)] == data->orientation)
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
		data->m = 0;
	if (data->key == 49)
		data->key_b = 0;
	if (data->key == 19)
		data->key_r = 0;
	return (0);
}
