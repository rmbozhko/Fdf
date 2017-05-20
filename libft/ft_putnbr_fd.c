/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <apinchuk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:49:51 by apinchuk          #+#    #+#             */
/*   Updated: 2016/12/10 14:49:42 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	rev[11];
	int		tempnb;

	tempnb = n;
	if (n == -2147483648)
		n = -214748364;
	i = 0;
	if (tempnb < 0)
		n = -n;
	while ((n / 10) > 0)
	{
		rev[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	rev[i] = n % 10 + '0';
	if (tempnb < 0)
		rev[++i] = '-';
	while (i >= 0)
		ft_putchar_fd(rev[i--], fd);
	if (tempnb == -2147483648)
		ft_putchar_fd('8', fd);
}
