/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <apinchuk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:02:10 by apinchuk          #+#    #+#             */
/*   Updated: 2016/12/10 16:17:32 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return (&p[i]);
		i++;
	}
	return (NULL);
}
