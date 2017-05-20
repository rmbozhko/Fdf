/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:08:14 by rbozhko           #+#    #+#             */
/*   Updated: 2017/04/14 17:13:06 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_zoom(t_env *e, int keycode)
{
	int		x;
	int		y;
	double	coefficient;

	y = -1;
	coefficient = (keycode == 69) ? 1.1 : 0.9;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			e->field_ptr[y][x]->x *= coefficient;
			e->field_ptr[y][x]->y *= coefficient;
		}
	}
	fdf_drawing_field(e);
}

void			fdf_rotate_x(t_env *e, int quarter)
{
	int		x;
	int		y;
	double	tmpz;
	double	tmpy;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			tmpz = e->field_ptr[y][x]->z;
			tmpy = e->field_ptr[y][x]->y;
			e->field_ptr[y][x]->y = tmpy * (cos(Q)) + tmpz * (sin(Q) * quarter);
			e->field_ptr[y][x]->z = ((-tmpy * sin(Q)
						* quarter) + tmpz * cos(Q));
		}
	}
	fdf_drawing_field(e);
}

void			fdf_rotate_y(t_env *e, int quarter)
{
	int		x;
	int		y;
	double	tmpz;
	double	tmpx;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			tmpz = e->field_ptr[y][x]->z;
			tmpx = e->field_ptr[y][x]->x;
			e->field_ptr[y][x]->x = tmpx * (cos(Q)) + (tmpz * sin(Q) * quarter);
			e->field_ptr[y][x]->z = (-tmpx * sin(Q) * quarter) + tmpz * cos(Q);
		}
	}
	fdf_drawing_field(e);
}

void			fdf_rotate_z(t_env *e, int quarter)
{
	int		x;
	int		y;
	double	tmpy;
	double	tmpx;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			tmpy = e->field_ptr[y][x]->y;
			tmpx = e->field_ptr[y][x]->x;
			e->field_ptr[y][x]->x = tmpx * (cos(Q)) + (tmpy * sin(Q) * quarter);
			e->field_ptr[y][x]->y = (-tmpx * sin(Q) * quarter) + tmpy * cos(Q);
		}
	}
	fdf_drawing_field(e);
}

void			fdf_change_rotation_angle(t_env *e, int keycode)
{
	if (keycode == 18)
		e->angle = 1;
	else if (keycode == 19)
		e->angle = 2;
	else if (keycode == 20)
		e->angle = 3;
	else if (keycode == 21)
		e->angle = 4;
	else if (keycode == 23)
		e->angle = 5;
	else if (keycode == 22)
		e->angle = 6;
	else if (keycode == 26)
		e->angle = 7;
	else if (keycode == 28)
		e->angle = 8;
	else if (keycode == 25)
		e->angle = 9;
}
