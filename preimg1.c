/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preimg1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:38:26 by agunes            #+#    #+#             */
/*   Updated: 2022/10/03 17:10:17 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	premap(t_cub3d *cub3d)
{
	char	**temp;
	int		i;
	int		x;

	temp = NULL;
	i = -1;
	x = 0;
	while (cub3d->img_s->cub[++i])
	{
		if (cub3d->img_s->cub[i][0] == '1')
		{
			cub3d->img_s->map = merge(cub3d->img_s->cub + i);
			dbfree(temp);
			break ;
		}
	}
	return (1);
}

int	checkcub2(char *s)
{
	int		len;

	len = 0;
	if (!ft_strncmp(s, "SO ", 3) || \
	!ft_strncmp(s, "EA ", 3) || \
	!ft_strncmp(s, "NO ", 3) || \
	!ft_strncmp(s, "WE ", 3) || \
	!ft_strncmp(s, "C ", 2) || \
	!ft_strncmp(s, "F ", 2) || \
	!ft_strncmp(s, "1", 1) || \
	s[0] == '\0')
		len++;
	if (len == 0)
		return (0);
	return (1);
}

int	checkcub(t_cub3d *cub3d)
{
	char	*temp;
	int		i;
	int		y;

	i = -1;
	y = 0;
	while (cub3d->img_s->cub[++i])
	{
		y = 0;
		while (cub3d->img_s->cub[i][y] && cub3d->img_s->cub[i][y] <= 32)
				y++;
		temp = cub3d->img_s->cub[i];
		cub3d->img_s->cub[i] = ft_strdup(cub3d->img_s->cub[i] + y);
		if (!checkcub2(cub3d->img_s->cub[i]))
			return (0);
		free(temp);
	}
	jumpspace(cub3d);
	return (1);
}

int	checkmap(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (cub3d->img_s->map[++i] != '\0')
		if (!ft_strchr("01NSEW", cub3d->img_s->map[i]) \
		&& cub3d->img_s->map[i] != '\n')
			return (0);
	return (1);
}

int	parsemap(t_cub3d *cub3d, char **argv)
{
	char	*buff;
	char	*temp;
	int		fd;

	buff = ft_calloc(2, 1);
	temp = ft_calloc(2, 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, buff, 1))
	{
		temp = ft_strjoin(temp, buff);
		buff[1] = '\0';
	}
	cub3d->img_s->cub = ft_split(temp, '\n');
	if (!checkcub(cub3d) || !premap(cub3d) || !checkmap(cub3d))
	{
		free(buff);
		free(temp);
		return (0);
	}
	free(buff);
	free(temp);
	return (1);
}
