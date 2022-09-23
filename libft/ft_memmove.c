/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:02:25 by scoskun           #+#    #+#             */
/*   Updated: 2022/09/23 15:07:32 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int			i;

	i = 0;
	if (!dest && !src)
		return (0);
	if ((size_t) dest - (size_t) src < len)
	{
		i = len - 1 ;
		while (i >= 0)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i--;
		}
	}
	else
	{
		while ((size_t)i < len)
		{
			((char *) dest)[i] = ((const char *) src)[i];
			i++;
		}
	}
	return (dest);
}
