/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:25:53 by agunes            #+#    #+#             */
/*   Updated: 2022/09/23 15:38:06 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checkgamemap2(char **buff, int i, int x)
{
	while (buff[++i])
	{
		x = 0;
		if (buff[i][x] != '1')
			return (0);
		while (buff[i][x])
		{
			if (i == 0)
				if (buff[i][x] != '1')
					return (0);
			if (buff[i + 1] == NULL)
				if (buff[i][x] != '1')
					return (0);
			x++;
		}
		if (buff[i][x - 1] != '1')
			return (0);
	}
	return (1);
}

int	xbutton(t_cub3d *main)
{
	dbfree(main->img_s->cub);
	free(main->img_s->map);
	free(main->img_s);
	free(main);
	printf("%sGame closed by player!\n", "\x1B[31m");
	exit(1);
	return (0);
}

int	checkgamemap(t_cub3d *cub3d)
{
	char	**buff;
	int		i;
	int		x;

	buff = ft_split(cub3d->img_s->map, '\n');
	i = -1;
	x = 0;
	if (!checkgamemap2(buff, i, x))
	{
		dbfree(buff);
		return (0);
	}
	dbfree(buff);
	return (1);
}

int	checkimg(t_cub3d *cub3d)
{
	if (cub3d->img_s->ea == NULL)
		return (0);
	if (cub3d->img_s->no == NULL)
		return (0);
	if (cub3d->img_s->we == NULL)
		return (0);
	if (cub3d->img_s->so == NULL)
		return (0);
	if (cub3d->img_s->floor == 0)
		return (0);
	if (cub3d->img_s->ceilling == 0)
		return (0);
	return (1);
}

int	mlx_start(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, \
	cub3d->witdh, cub3d->height, "BOMBOM!");
	if (!preimg(cub3d) || !checkimg(cub3d) || !checkgamemap(cub3d))
		return (0);
	cub3d->screen_img = mlx_new_image(cub3d->mlx, cub3d->height, cub3d->witdh);
	cub3d->screen_img_data = (int *)mlx_get_data_addr(cub3d->screen_img, \
	&cub3d->bit_per_px, &cub3d->size_line, &cub3d->endian);
	dbfree(cub3d->img_s->cub);
	cub3d->img_s->cub = ft_split(cub3d->img_s->map, '\n');
	get_pos(cub3d);
	set_values(cub3d, cub3d->img_s);
	print_roof(cub3d);
	print_ground(cub3d);
	print_img(cub3d, cub3d->img_s);
	mlx_hook(cub3d->win, 17, 0, xbutton, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, move, cub3d);
	mlx_loop(cub3d->mlx);
	return (1);
}
