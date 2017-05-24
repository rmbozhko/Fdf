/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:19:46 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/24 14:21:32 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		get_middle_color(int times)
{
	int		color;

	if (times == 0)
		color = 98;
	else if (times == 1)
		color = 50;
	else if (times == 2)
		color = 45;
	return (color);
}

static int		get_minor_color(int times)
{
	int		color;

	if (times == 0)
		color = 80;
	else if (times == 1)
		color = 0;
	else if (times == 2)
		color = 165;
	return (color);
}

static int		get_top_color(int times)
{
	int		color;

	if (times == 0)
		color = 51;
	else if (times == 1)
		color = 255;
	else if (times == 2)
		color = 51;
	return (color);
}

int				fdf_pxl_color(int main_color)
{
	int				color;
	static int		times = 0;

	if (main_color == 0 || (main_color == 1) || (main_color == -1)
		|| (main_color >= 2 && main_color <= 3)
		|| (main_color <= -2 && main_color >= -3)
		|| (main_color >= 4 && main_color <= 5)
		|| (main_color <= -4 && main_color >= -5))
		color = get_minor_color(times++);
	else if ((main_color >= 6 && main_color <= 7)
		|| (main_color <= -6 && main_color >= -7)
		|| (main_color >= 8 && main_color <= 9)
		|| (main_color <= -6 && main_color >= -9))
		color = get_middle_color(times++);
	else if (main_color >= 10)
		color = get_top_color(times++);
	(times == 3) ? times = 0 : 0;
	return (color);
}
