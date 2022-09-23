/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preimg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:01:09 by agunes            #+#    #+#             */
/*   Updated: 2022/09/23 15:20:25 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	prefc2(t_cub3d *cub3d, int i)
{
	char	**buff;
	int		x;
	int		y;

	x = -1;
	y = -1;
	if (!ft_strncmp(cub3d->img_s->cub[i], "C", 1))
	{
		buff = ft_split(cub3d->img_s->cub[i] + 1, ',');
		while (buff[++x])
		{
			if (x > 2)
				return (dbfree(buff));
			y = 0;
			while (buff[x][++y])
				if (!ft_isdigit(buff[x][y]) || (ft_atoi(buff[x]) > 255))
					return (0);
			if (x > 2)
				return (dbfree(buff));
		}
		freeprefc(cub3d, buff, i);
	}
	return (1);
}

int	prefc(t_cub3d *cub3d, int i)
{
	char	**buff;
	int		x;
	int		y;

	x = -1;
	y = -1;
	if (!ft_strncmp(cub3d->img_s->cub[i], "F", 1))
	{
		buff = ft_split(cub3d->img_s->cub[i] + 1, ',');
		while (buff[++x])
		{
			y = 0;
			while (buff[x][++y])
				if (!ft_isdigit(buff[x][y]) || (ft_atoi(buff[x]) > 255))
					return (0);
			if (x > 2)
				return (dbfree(buff));
		}
		freeprefc(cub3d, buff, i);
	}
	if (!prefc2(cub3d, i))
		return (0);
	return (1);
}

void	preimg3(t_cub3d *cub3d, int i, int a, int b)
{
	if (!ft_strncmp(cub3d->img_s->cub[i], "WE", 2))
	{
		cub3d->img_s->we = mlx_xpm_file_to_image(cub3d->mlx, \
			ft_strchr(cub3d->img_s->cub[i], '.'), &a, &b);
			cub3d->img_s->we_data = (int *)mlx_get_data_addr(cub3d->img_s->we, \
			&cub3d->bit_per_px, &cub3d->size_line, &cub3d->endian);
	}
	if (!ft_strncmp(cub3d->img_s->cub[i], "SO", 2))
	{
		cub3d->img_s->so = mlx_xpm_file_to_image(cub3d->mlx, \
			ft_strchr(cub3d->img_s->cub[i], '.'), &a, &b);
			cub3d->img_s->so_data = (int *)mlx_get_data_addr(cub3d->img_s->so, \
			&cub3d->bit_per_px, &cub3d->size_line, &cub3d->endian);
	}
}

void	preimg2(t_cub3d *cub3d, int i, int a, int b)
{
	if (!ft_strncmp(cub3d->img_s->cub[i], "EA", 2))
	{
		cub3d->img_s->ea = mlx_xpm_file_to_image(cub3d->mlx, \
		ft_strchr(cub3d->img_s->cub[i], '.'), &a, &b);
		cub3d->img_s->ea_data = (int *)mlx_get_data_addr(cub3d->img_s->ea, \
		&cub3d->bit_per_px, &cub3d->size_line, &cub3d->endian);
	}
	if (!ft_strncmp(cub3d->img_s->cub[i], "NO", 2))
	{
		cub3d->img_s->no = mlx_xpm_file_to_image(cub3d->mlx, \
		ft_strchr(cub3d->img_s->cub[i], '.'), &a, &b);
		cub3d->img_s->no_data = (int *)mlx_get_data_addr(cub3d->img_s->no, \
		&cub3d->bit_per_px, &cub3d->size_line, &cub3d->endian);
	}
}

int	preimg(t_cub3d *cub3d)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 64;
	b = 64;
	while (cub3d->img_s->cub[i])
	{
		preimg2(cub3d, i, a, b);
		preimg3(cub3d, i, a, b);
		if (!prefc(cub3d, i))
			return (0);
		i++;
	}
	return (1);
}
