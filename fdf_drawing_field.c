/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:28:00 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/24 17:26:49 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_drawing_pxl(t_env *e, t_brezenheim *b)
{
	if (DRAWING_PXL_COND && !(e->gradient))
	{
		e->str[(4 * b->x + b->y * e->sl)] = fdf_pxl_color(b->color);
		e->str[(4 * b->x + b->y * e->sl + 1)] = fdf_pxl_color(b->color);
		e->str[(4 * b->x + b->y * e->sl + 2)] = fdf_pxl_color(b->color);
	}
}

void			fdf_bresenheim(t_brezenheim *b, t_pnt *pnt1, t_env *e)
{
	b->x = (int)pnt1->x;
	b->y = (int)pnt1->y;
	b->del_x = abs((int)b->last_pnt->x - b->x);
	b->del_y = abs((int)b->last_pnt->y - b->y);
	b->sign_x = b->x < (int)b->last_pnt->x ? 1 : -1;
	b->sign_y = b->y < (int)b->last_pnt->y ? 1 : -1;
	b->error = b->del_x - b->del_y;
	while (b->x != (int)b->last_pnt->x || b->y != (int)b->last_pnt->y)
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

void			fdf_drawing_field(t_env *e)
{
	int					x;
	int					y;
	t_pnt				pnt;
	t_brezenheim		b;

	b.error2 = 0;
	(e->img_ptr && (y = -1)) ? mlx_destroy_image(e->mlx_ptr, e->img_ptr) : 0;
	e->img_ptr = mlx_new_image(e->mlx_ptr, e->win_img_size, e->win_img_size);
	e->str = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->sl, &e->endian);
	fdf_img_to_centre(e);
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			pnt = *(e->field_ptr[y][x]);
			b.color = (int)pnt.color;
			// printf("X: %d : %d : %d\n", x, x + 1, e->xlen);
			// printf("y: %d : %d : %d\n", y, y + 1, e->ylen);
			if (x + 1 == e->xlen || y + 1 == e->ylen)
				break ; 
			b.last_pnt = (e->field_ptr[y][x + 1]) ? e->field_ptr[y][x + 1] : 0;
			(e->field_ptr[y][x + 1]) ? fdf_bresenheim(&b, &pnt, e) : 0;
			b.last_pnt = (e->field_ptr[y + 1][x]) ? e->field_ptr[y + 1][x] : 0;
			(e->field_ptr[y + 1][x]) ? fdf_bresenheim(&b, &pnt, e) : 0;
		}
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}

// OR || ИЛИ || ODER 

// void			fdf_drawing_field(t_env *e)
// {
// 	int					x;
// 	int					y;
// 	t_pnt				pnt;
// 	t_brezenheim		b;

// 	b.error2 = 0;
// 	(e->img_ptr && (y = -1)) ? mlx_destroy_image(e->mlx_ptr, e->img_ptr) : 0;
// 	// write(1, "Let's go deeper!\n", 17);
// 	e->img_ptr = mlx_new_image(e->mlx_ptr, e->win_img_size, e->win_img_size);
// 	// write(1, "Let's went deeper!\n", 19);
// 	e->str = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->sl, &e->endian);
// 	// write(1, "Let's gone deeper!\n", 19);
// 	fdf_img_to_centre(e);
// 	// write(1, "Really?!\n", 9);
// 	// printf("length-es: %d : %d\n", e->ylen, e->xlen);
// 	while (++y < e->ylen && (x = -1))
// 	{
// 		// write(1, "WTF, do you have problems?\n", 27);
// 		// printf("Y: %d\n", y);
// 		while (++x < e->xlen)
// 		{
// 			// write(1, "You surely do have problems!\n", 29);
// 			// printf("X: %d : %d : %d\n", x, x + 1, e->xlen);
// 			pnt = *(e->field_ptr[y][x]);
// 			// printf("data: %d:%d\n", pnt.x, pnt.y);
// 			b.color = (int)pnt.color;
// 			if (x + 1 < e->xlen)
// 			{
// 				b.last_pnt = (e->field_ptr[y][x + 1]) ? e->field_ptr[y][x + 1] : 0;
// 				(e->field_ptr[y][x + 1]) ? fdf_bresenheim(&b, &pnt, e) : 0;
// 			}
// 			// write(1, "Mayday, Mayday!\n", 16);
// 			printf("y: %d : %d : %d\n", y, y + 1, e->ylen);
// 			if (y + 1 < e->ylen)
// 			{
// 				b.last_pnt = (e->field_ptr[y + 1][x]) ? e->field_ptr[y + 1][x] : 0;
// 				(e->field_ptr[y + 1][x]) ? fdf_bresenheim(&b, &pnt, e) : 0;
// 			}
// 			// write(1, "sos!\n", 5);
// 		}
// 	}
// 	write(1, "So deep?!\n", 10);
// 	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
// }
