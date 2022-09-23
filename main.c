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

int	cubcheck(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 'b' || s[i - 2] != 'u' || s[i - 3] != 'c' || \
		s[i - 4] != '.' || i < 5)
		return (0);
	return (1);
}

void	set_values(t_cub3d *data, t_img *map)
{
	if (data->orientation == 'S')
	{
		data->rx = 1;
		data->ry = 0;
	}
	else
		data->rx = -1;
	data->viewx = 0;
	data->viewy = 0.66;
	data->move_speed = 0.5;
	data->rotate_speed = 0.1;
	data->witdh = 1080;
	data->height = 1080;
	data->img_width = 64;
	data->img_height = 64;
	map->next_idx = 0;
}

int	setupgame(t_cub3d *cub3d)
{
	set_values(cub3d, cub3d->img_s);
	if (!mlx_start(cub3d))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	if (argc == 2 && cubcheck(argv[1]))
	{
		cub3d = ft_calloc(sizeof(t_cub3d), 100);
		cub3d->img_s = ft_calloc(sizeof(t_img), 100);
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
