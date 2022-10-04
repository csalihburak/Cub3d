/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:08:16 by scoskun           #+#    #+#             */
/*   Updated: 2022/10/04 14:03:44 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mimap(t_cub3d *data)
{
	data->new = mlx_new_image(data->mlx, data->alen, data->blen);
	data->new_da = (int *)mlx_get_data_addr(data->new, &data->bit_per_px, \
	&data->size_line, &data->endian);
	data->aim = mlx_xpm_file_to_image(data->mlx, "./textures/gun.xpm", \
	&data->img_width, &data->img_height);
	data->aim2 = mlx_xpm_file_to_image(data->mlx, "./textures/aim.xpm", \
	&data->img_width, &data->img_height);
	dbfree(data->img_s->cub);
	data->grana = mlx_xpm_file_to_image(data->mlx, "./textures/chc.xpm", \
	&data->img_width, &data->img_height);
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
			data->blen += 5;
		i++;
	}
	data->blen += 5;
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

void	get_path(t_cub3d *data, int i, int j)
{
	char	**buff;

	buff = data->img_s->cub;
	data->paths = ft_calloc(sizeof(char *), 5);
	while (buff[++i])
	{
		if (!ft_strncmp(buff[i], "NO", 2))
			data->paths[j++] = ft_strdup(ft_strchr(buff[i], 'O') + 1);
		if (!ft_strncmp(buff[i], "EA", 2))
			data->paths[j++] = ft_strdup(ft_strchr(buff[i], 'A') + 1);
		if (!ft_strncmp(buff[i], "SO", 2))
			data->paths[j++] = ft_strdup(ft_strchr(buff[i], 'O') + 1);
		if (!ft_strncmp(buff[i], "WE", 2))
			data->paths[j++] = ft_strdup(ft_strchr(buff[i], 'E') + 1);
	}
	data->paths[j] = NULL;
	i = -1;
	while (data->paths[++i])
	{
		if (open(data->paths[i], O_RDONLY) == -1)
		{
			data->flag1 = i;
			ft_error(data, 6);
		}
	}
}
