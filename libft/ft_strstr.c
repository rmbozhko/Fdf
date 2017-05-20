/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <apinchuk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 21:23:23 by apinchuk          #+#    #+#             */
/*   Updated: 2016/12/10 14:38:28 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + c] == to_find[c])
		{
			c++;
			if (to_find[c] == '\0')
			{
				return (str + i);
			}
		}
		c = 0;
		i++;
	}
	return (NULL);
}
