/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:11:17 by scoskun           #+#    #+#             */
/*   Updated: 2022/09/29 18:53:42 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_backward(int key, t_cub3d *data)
{
	key = 0;
	if (data->key_w)
	{
		if (data->img_s->cub[(int)(data->px + data->rx * \
		data->move_speed)][(int)data->py] == '0')
		{
			data->px += data->rx * data->move_speed;
		}
		if (data->img_s->cub[(int)data->px][(int)(data->py + \
		data->ry * data->move_speed)] == '0')
			data->py += data->ry * data->move_speed;
	}
	else if (data->key_s)
	{
		if (data->img_s->cub[(int)(data->px - data->rx * \
		data->move_speed)][(int)data->py] == '0')
		{
			data->px -= data->rx * data->move_speed;
		}
		if (data->img_s->cub[(int)data->px][(int)(data->py - data->ry * \
		data->move_speed)] == '0')
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
	return (0);
}
