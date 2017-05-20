/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <apinchuk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:38:10 by apinchuk          #+#    #+#             */
/*   Updated: 2016/12/10 16:48:42 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	digits(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
	{
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	sign;

	len = digits(n);
	sign = n;
	if (n < 0)
	{
		sign = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = sign % 10 + '0';
	while (sign /= 10)
		str[--len] = sign % 10 + '0';
	if (n < 0)
	{
		str[0] = '-';
	}
	return (str);
}
