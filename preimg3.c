/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preimg3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:35:31 by agunes            #+#    #+#             */
/*   Updated: 2022/10/04 11:29:58 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hexcolor(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	freeprefc(t_cub3d *cub3d, char **buff, int i)
{
	int	r;
	int	g;
	int	b;

	dbfree(buff);
	r = ft_atoi(cub3d->img_s->cub[i] + 1);
	g = ft_atoi(ft_strchr(cub3d->img_s->cub[i], ','));
	b = ft_atoi(ft_strrchr(cub3d->img_s->cub[i], ',') + 1);
	if (cub3d->img_s->cub[i][0] == 'F')
		cub3d->img_s->floor = mlx_get_color_value(cub3d->mlx, \
		hexcolor(r, g, b));
	else
		cub3d->img_s->ceilling = mlx_get_color_value(cub3d->mlx, \
		hexcolor(r, g, b));
}

int	lenmap(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] > 32)
			len++;
		i++;
	}
	return (len + 1);
}

void	jumpspace(t_cub3d *cub3d)
{
	char	*buff;
	int		x;
	int		y;
	int		i;

	buff = NULL;
	i = -1;
	while (cub3d->img_s->cub[++i])
	{
		y = 0;
		x = 0;
		buff = ft_calloc(lenmap(cub3d->img_s->cub[i]), 1);
		while (cub3d->img_s->cub[i][y])
		{
			if (cub3d->img_s->cub[i][y] <= 32)
				y++;
			else
				buff[x++] = cub3d->img_s->cub[i][y++];
		}
		buff[x] = '\0';
		free(cub3d->img_s->cub[i]);
		cub3d->img_s->cub[i] = ft_strdup(buff);
		free(buff);
	}
}
