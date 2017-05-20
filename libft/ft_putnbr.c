/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <apinchuk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:17:58 by apinchuk          #+#    #+#             */
/*   Updated: 2016/11/30 17:08:54 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int		i;
	char	rev[11];
	int		tempnb;

	tempnb = nb;
	if (nb == -2147483648)
		nb = -214748364;
	i = 0;
	if (tempnb < 0)
		nb = -nb;
	while ((nb / 10) > 0)
	{
		rev[i] = nb % 10 + '0';
		i++;
		nb = nb / 10;
	}
	rev[i] = nb % 10 + '0';
	if (tempnb < 0)
		rev[++i] = '-';
	while (i >= 0)
		ft_putchar(rev[i--]);
	if (tempnb == -2147483648)
		ft_putchar('8');
}
