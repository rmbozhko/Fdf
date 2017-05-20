/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <apinchuk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 21:39:33 by apinchuk          #+#    #+#             */
/*   Updated: 2016/12/10 14:33:41 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s;
	size_t	s1_size;

	s = s1;
	s1_size = sizeof(s1);
	while (*s1)
		s1++;
	while (*s2 && s1_size - 1 && n--)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s);
}
