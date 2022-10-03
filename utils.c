/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:19:19 by agunes            #+#    #+#             */
/*   Updated: 2022/10/03 16:15:57 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pos(t_cub3d *data)
{
	int	x;
	int	y;

	x = -1;
	while (data->img_s->cub[++x])
	{
		y = -1;
		while (data->img_s->cub[x][++y])
		{
			if (data->img_s->cub[x][y] == 'E' || data->img_s->cub[x][y] == 'W' \
			|| data->img_s->cub[x][y] == 'S' || data->img_s->cub[x][y] == 'N')
			{
				data->px = x ;
				data->py = y;
				data->orientation = data->img_s->cub[x][y];
				return ;
			}
		}
	}	
}

int	dblen(char **array)
{
	int	i;
	int	y;
	int	len;

	i = 0;
	y = 0;
	len = 0;
	while (array && array[i])
	{
		y = 0;
		while (array[i][y++])
			len++;
		i++;
		len++;
	}
	return (len);
}

int	dbfree(char **array)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (array != NULL && array[i])
	{
		x = 0;
		while (array[i][x])
			array[i][x++] = '\0';
		free(array[i++]);
	}
	free(array);
	array = NULL;
	return (0);
}

char	*merge(char **map)
{
	char	*arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	arr = ft_calloc(sizeof(char), dblen(map));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			arr[k++] = map[i][j++];
		if (map[i + 1])
			arr[k++] = '\n';
		i++;
	}
	arr[k] = '\0';
	return (arr);
}

char	*deletechar(char *array, char c)
{
	int		i;
	int		x;
	int		len;
	char	*newarray;

	i = -1;
	x = 0;
	len = 0;
	while (array[++i])
	{
		if (array[i] == c)
			len++;
	}
	newarray = ft_calloc(sizeof(char), (ft_strlen(array) - (len - 1)));
	i = -1;
	while (array[++i])
	{
		if (array[i] != c)
			newarray[x++] = array[i];
	}
	newarray[x] = '\0';
	return (newarray);
}
