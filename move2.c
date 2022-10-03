/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:49:34 by scoskun           #+#    #+#             */
/*   Updated: 2022/10/03 18:13:38 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_cub3d *data)
{
	data->old = data->rx;
	data->rx = data->rx * cos(-data->rotate_speed) - data->ry * \
	sin(-data->rotate_speed);
	data->ry = data->old * sin(-data->rotate_speed) + data->ry * \
	cos(-data->rotate_speed);
	data->old2 = data->viewx;
	data->viewx = data->viewx * cos(-data->rotate_speed) - data->viewy * \
	sin(-data->rotate_speed);
	data->viewy = data->old2 * sin(-data->rotate_speed) + data->viewy * \
	cos(-data->rotate_speed);
}

void	move_right(t_cub3d *data)
{
	data->old = data->rx;
	data->rx = data->rx * cos(data->rotate_speed) - \
	data->ry * sin(data->rotate_speed);
	data->ry = data->old * sin(data->rotate_speed) + \
	data->ry * cos(data->rotate_speed);
	data->old2 = data->viewx;
	data->viewx = data->viewx * cos(data->rotate_speed) - \
	data->viewy * sin(data->rotate_speed);
	data->viewy = data->old2 * sin(data->rotate_speed) + \
	data->viewy * cos(data->rotate_speed);
}

int	move_norm(t_cub3d *data)
{
	move_forward_backward(data, data->img_s);
	if (data->key_a)
		move_left(data);
	else if (data->key_d)
		move_right(data);
	return (0);
}

int	main_loop(t_cub3d *data)
{
	mlx_clear_window(data->mlx, data->win);
	print_roof(data);
	print_ground(data);
	print_img(data, data->img_s);
	if (data->key == 46)
		data->m = 1;
	if (data->key == 45)
		data->m = 0;
	move_norm(data);
	return (0);
}

int	move2(int key, t_cub3d *data)
{
	printf("%d\n", key);
	data->key = key;
	if (key == 13)
		data->key_w = 1;
	if (key == 1)
		data->key_s = 1;
	if (key == 123 || key == 0)
		data->key_a = 1;
	if (key == 2 || key == 124)
		data->key_d = 1;
	if (data->key == 49)
		data->key_b = 1;
	if (data->key == 19)
		data->key_r = 1;
	return (1);
}
