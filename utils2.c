/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:08:16 by scoskun           #+#    #+#             */
/*   Updated: 2022/10/03 18:55:22 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pos2(t_cub3d *data)
{
	int	i;

	i = -1;
	while (data->img_s->map[++i])
	{
		if (data->img_s->map[i] == data->orientation)
			return (i);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1 && s2) && s1[i] == s2[i] && s2[i])
			i++;
		return (s1[i] - s2[i]);
	}
	return (0);
}

void	get_map_size(t_cub3d *data, t_img *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i] != '\n' && data->blen == 0)
			data->alen += 4;
		if (map->map[i] == '\n')
			data->blen += 6;
		i++;
	}
	data->blen += 6;
}

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
