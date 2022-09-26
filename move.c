/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:11:17 by scoskun           #+#    #+#             */
/*   Updated: 2022/09/26 18:44:58 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int pos(t_cub3d *data)
{
	int i;

	i = 0;

	data->img_s->alen = 0;
	while(data->img_s->map[i])
	{			
		if (data->img_s->map[i] == 'E' || data->img_s->map[i] == 'w' \
			|| data->img_s->map[i] == 'S' || data->img_s->map[i] == 'N')
			return (i);
		if (data->img_s->map[i] == '\n')
			data->img_s->alen += 1;
		i++;
	}
	return (0);
}

void	move_forward_backward(int key, t_cub3d *data)
{
	int p;

	p = pos(data);
	data->img_s->blen = ft_strlen(data->img_s->cub[data->img_s->alen]);
	if (key == 13)
	{
		if (data->img_s->cub[(int)(data->px + data->rx * \
		data->move_speed)][(int)data->py] == '0')
		{
			data->img_s->map[p] = '0';
			data->img_s->map[p - 64] = data->orientation;
			data->px += data->rx * data->move_speed;
		}
		if (data->img_s->cub[(int)data->px][(int)(data->py + \
		data->ry * data->move_speed)] == '0')
			data->py += data->ry * data->move_speed;
	}
	else if (key == 1)
	{
		if (data->img_s->cub[(int)(data->px - data->rx * \
		data->move_speed)][(int)data->py] == '0')
		{
			data->img_s->map[p] = '0';
			data->img_s->map[p + 64] = data->orientation;
			data->px -= data->rx * data->move_speed;
		}
		if (data->img_s->cub[(int)data->px][(int)(data->py - data->ry * \
		data->move_speed)] == '0')
			data->py -= data->ry * data->move_speed;
	}
}

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

void	move_norm(int key, t_cub3d *data)
{
	if (key == 13 || key == 1)
		move_forward_backward(key, data);
	if (data->orientation == 'S')
	{
		if (key == 0 || key == 123)
			move_left(data);
		else if (key == 2 || key == 124)
			move_right(data);
	}
	if (data->orientation == 'N')
	{
		if (key == 0 || key == 123)
			move_right(data);
		else if (key == 2 || key == 124)
			move_left(data);
	}
}

int	move(int key, t_cub3d *data)
{
	int	a;
	int	b;
	int i;

	i = 0;
	if (key == 53)
		exit(1);
	move_norm(key, data);
	mlx_clear_window(data->mlx, data->win);
	print_roof(data);
	print_ground(data);
	print_img(data, data->img_s);
	mlx_mouse_get_pos(data->win, &a, &b);
	mlx_put_image_to_window(data->mlx, data->win, data->aim, a, b);
	mini_map(data, data->img_s);
	return (0);
}
