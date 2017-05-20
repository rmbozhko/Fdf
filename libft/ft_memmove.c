/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <apinchuk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:00:03 by apinchuk          #+#    #+#             */
/*   Updated: 2016/12/10 16:25:46 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t a;

	a = 0;
	if (dst > src)
	{
		while (a < len)
			a++;
		a--;
		while ((int)a >= 0)
		{
			((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
			a--;
		}
		return (dst);
	}
	while (a < len)
	{
		((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
		a++;
	}
	return (dst);
}
