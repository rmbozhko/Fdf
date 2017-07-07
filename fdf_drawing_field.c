/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:28:00 by rbozhko           #+#    #+#             */
/*   Updated: 2017/06/29 17:26:14 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		fdf_drawing_pxl(t_env *e, t_brezenheim *b)
{
	if (DRAWING_PXL_COND)
	{
		e->str[(4 * b->x + b->y * e->sl)] = fdf_pxl_color(b->color);
		e->str[(4 * b->x + b->y * e->sl + 1)] = fdf_pxl_color(b->color);
		e->str[(4 * b->x + b->y * e->sl + 2)] = fdf_pxl_color(b->color);
	}
}

void				fdf_isometric(t_env *e, t_brezenheim *b)
{
	int x;
	int y;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			e->fld_ptr[y][x]->y = (e->fld_ptr[y][x]->x + 2 *
					e->fld_ptr[y][x]->y + e->fld_ptr[y][x]->z) / sqrt(6);
			e->fld_ptr[y][x]->x = ((sqrt(3) * e->fld_ptr[y][x]->x)
					- (sqrt(3) * e->fld_ptr[y][x]->z)) / sqrt(6);
		}
	}
	fdf_drawing_field(e, -1, -1, b);
}

void				fdf_bresenheim(t_brezenheim *b, t_pnt *pnt1, t_env *e)
{
	b->x = (int)pnt1->x;
	b->y = (int)pnt1->y;
	b->del_x = abs((int)b->l_pnt->x - b->x);
	b->del_y = abs((int)b->l_pnt->y - b->y);
	b->sign_x = b->x < (int)b->l_pnt->x ? 1 : -1;
	b->sign_y = b->y < (int)b->l_pnt->y ? 1 : -1;
	b->error = b->del_x - b->del_y;
	while (b->x != (int)b->l_pnt->x || b->y != (int)b->l_pnt->y)
	{
		b->error2 = b->error * 2;
		if (b->error2 > -b->del_y)
		{
			b->error -= b->del_y;
			b->x += b->sign_x;
		}
		if (b->error2 < b->del_x)
		{
			b->error += b->del_x;
			b->y += b->sign_y;
		}
		b->temp_pnt.x = b->x;
		b->temp_pnt.y = b->y;
		fdf_drawing_pxl(e, b);
	}
	fdf_drawing_pxl(e, b);
}

void				fdf_drawing_field(t_env *e, int x, int y, t_brezenheim *b)
{
	t_pnt				pnt;

	(e->img_ptr) ? mlx_destroy_image(e->mlx_ptr, e->img_ptr) : 0;
	e->img_ptr = mlx_new_image(e->mlx_ptr, e->win_img_size, e->win_img_size);
	e->str = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->sl, &e->endian);
	fdf_img_to_centre(e);
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			pnt = *(e->fld_ptr[y][x]);
			b->color = (int)pnt.color;
			if (x + 1 < e->xlen)
			{
				b->l_pnt = (e->fld_ptr[y][x + 1]) ? e->fld_ptr[y][x + 1] : 0;
				(e->fld_ptr[y][x + 1]) ? fdf_bresenheim(b, &pnt, e) : 0;
			}
			if (y + 1 < e->ylen)
			{
				b->l_pnt = (e->fld_ptr[y + 1][x]) ? e->fld_ptr[y + 1][x] : 0;
				(e->fld_ptr[y + 1][x]) ? fdf_bresenheim(b, &pnt, e) : 0;
			}
		}
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, e->x, e->y);
}
