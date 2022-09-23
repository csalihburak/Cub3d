/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:58:40 by scoskun           #+#    #+#             */
/*   Updated: 2022/09/23 15:07:38 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t	x;

	x = 0;
	while (x < len)
	{
		if (((unsigned char *)s1)[x] != (((unsigned char *)s2)[x]))
			return (((unsigned char *)s1)[x] - (((unsigned char *)s2)[x]));
		x++;
	}
	return (0);
}
