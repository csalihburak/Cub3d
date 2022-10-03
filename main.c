/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ain.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:24:14 by agunes            #+#    #+#             */
/*   Updated: 2022/09/02 17:05:09 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_orientation(t_cub3d *data)
{
	if (data->orientation == 'S')
	{
		data->rx = 1;
		data->viewy = 0.66;
	}
	else if (data->orientation == 'N')
	{
		data->rx = -1;
		data->viewy = -0.66;
	}
	else if (data->orientation == 'W')
	{
		data->ry = 1;
		data->viewx = -0.66;
	}
	else if (data->orientation == 'E')
	{
		data->ry = -1;
		data->viewx = 0.66;
	}
}

void	set_values(t_cub3d *data)
{
	set_orientation(data);
	data->move_speed = 0.13;
	data->rotate_speed = 0.032;
	data->witdh = 1920;
	data->height = 1080;
	data->img_width = 64;
	data->img_height = 64;
}

int	setupgame(t_cub3d *cub3d)
{
	get_map_size(cub3d, cub3d->img_s);
	set_values(cub3d);
	mini_map(cub3d);
	if (!mlx_start(cub3d))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	if (argc == 2 && cubcheck(argv[1]))
	{
		cub3d = ft_calloc(sizeof(t_cub3d), 1);
		cub3d->img_s = ft_calloc(sizeof(t_img), 1);
		cub3d->map_name = argv[1];
		if (!parsemap(cub3d, argv) || !setupgame(cub3d))
		{
			printf("Error\n");
			return (0);
		}
	}
	else
	{
		printf("Error\n");
		return (0);
	}
	return (1);
}
