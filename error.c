/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:23:44 by scoskun           #+#    #+#             */
/*   Updated: 2022/10/04 15:38:55 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_ch(t_cub3d *data, int px, int py, int flag)
{
	if (flag == 0)
	{
		data->new_da[px + py] = 0xD35400;
		data->new_da[px + py + 1] = 0xD35400;
		data->new_da[px + py + data->alen] = 0xD35400;
		data->new_da[px + py + data->alen +1] = 0xD35400;
	}
	else if (flag == 1)
	{
		data->new_da[px + py] = 255;
		data->new_da[px + py + 1] = 255;
		data->new_da[px + py + data->alen] = 255;
		data->new_da[px + py + data->alen +1] = 255;
	}
	else
	{
		data->new_da[px + py] = 0;
		data->new_da[px + py + 1] = 0;
		data->new_da[px + py + data->alen] = 0;
		data->new_da[px + py + data->alen + 1] = 0;
	}
}

void	put_guns2(t_cub3d *data)
{
	if (!data->key_b)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->aim, 300, 500);
		mlx_put_image_to_window(data->mlx, data->win, data->aim2, 950, 550);
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
			data->aim2, 1030, 550);
			mlx_put_image_to_window(data->mlx, data->win, data->grana, 50, 200);
		}
		else
		{
			mlx_put_image_to_window(data->mlx, data->win, data->aim2, 50, 400);
			mlx_put_image_to_window(data->mlx, data->win, \
			data->grana, 1090, 600);
		}	
	}
	else
		put_guns2(data);
}

void	ft_error(t_cub3d *data, int msg)
{
	if (msg == 0)
		printf("Error! Wrong agumnet number\n");
	else if (msg == 1)
		printf("Error! Map files has to be end with '.cub' extension\n");
	else if (msg == 2)
		printf("Error! While Parsing Map\n");
	else if (msg == 3)
		printf("Error! Something Wrong With The İmages");
	else if (msg == 5)
		printf("Error! RGB Values Can't Be Greater Than '255'");
	else if (msg == 6)
	{
		printf("Error! There is no such a file or directory: '%s'\n", \
		data->paths[data->flag1]);
	}
	(void)data;
	exit(1);
}
