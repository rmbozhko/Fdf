/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:28:00 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/24 15:12:19 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_drawing_pxl(t_env *e, t_brezenheim *b, t_pnt *pnt)
{
	if (DRAWING_PXL_COND && !(e->gradient))
	{
		e->str[(4 * b->x + b->y * e->sl)] = fdf_pxl_color(pnt->color);
		e->str[(4 * b->x + b->y * e->sl + 1)] = fdf_pxl_color(pnt->color);
		e->str[(4 * b->x + b->y * e->sl + 2)] = fdf_pxl_color(pnt->color);
	}
}

void 			fdf_bresenheim(t_pnt *pnt1, t_pnt *pnt2, t_env *e, int error2)
{
	t_brezenheim	b;

	b.x = (int)pnt1->x;
	b.y = (int)pnt1->y;
	b.flag = 1;
	b.last_pnt = pnt2;
	b.del_x = abs((int)b.last_pnt->x - b.x);
    b.del_y = abs((int)b.last_pnt->y - b.y);
    b.sign_x = b.x < (int)b.last_pnt->x ? 1 : -1;
    b.sign_y = b.y < (int)b.last_pnt->y ? 1 : -1;
    b.error = b.del_x - b.del_y;
    while(b.x != (int)b.last_pnt->x || b.y != (int)b.last_pnt->y) 
   {
   		b.base_pnt.x = b.temp_pnt.x;
   		b.base_pnt.y = b.temp_pnt.y;
        error2 = b.error * 2;
        if(error2 > -b.del_y) 
        {
            b.error -= b.del_y;
            b.x += b.sign_x;       
        }
        if(error2 < b.del_x) 
        {
            b.error += b.del_x;
            b.y += b.sign_y;
        }
        b.temp_pnt.x = b.x;
   		b.temp_pnt.y = b.y;
        fdf_drawing_pxl(e, &b, pnt1);
    }
    fdf_drawing_pxl(e, &b, pnt1);
}

void			fdf_drawing_field(t_env *e)
{
	int		x;
	int		y;
	t_pnt	pnt;

	y = -1;
	if (e->img_ptr)
		mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx_ptr, e->win_img_size, e->win_img_size);
	e->str = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->sl, &e->endian);
	fdf_img_to_centre(e);
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			pnt = *(e->field_ptr[y][x]);
			if (e->field_ptr[y][x + 1])
				fdf_bresenheim(&pnt, e->field_ptr[y][x + 1], e, 0);
			if (e->field_ptr[y + 1][x])
				fdf_bresenheim(&pnt, e->field_ptr[y + 1][x], e, 0);
		}
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}
