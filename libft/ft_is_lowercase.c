/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_lowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <apinchuk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:17:33 by apinchuk          #+#    #+#             */
/*   Updated: 2016/12/19 18:20:07 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_lowercase(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}

int			ft_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(is_lowercase(str[i])))
			return (0);
		i++;
	}
	return (1);
}
