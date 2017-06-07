/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_additional_ft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:26:44 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/24 15:19:23 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_img_to_centre(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	e->win_move_x = (((e->fld_ptr[e->ylen - 1][e->xlen - 1]->x
					+ e->fld_ptr[0][0]->x) / 2));
	e->win_move_y = (((e->fld_ptr[e->ylen - 1][e->xlen - 1]->y
					+ e->fld_ptr[0][0]->y) / 2));
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			e->fld_ptr[y][x]->x += (e->win_img_size / 2) - e->win_move_x;
			e->fld_ptr[y][x]->y += (e->win_img_size / 2) - e->win_move_y;
		}
	}
}

void		fdf_get_pnt_distance(t_env *e)
{
	int		multiplication;
	int		counter;
	int		delimiter;

	counter = 0;
	multiplication = e->xlen * e->ylen;
	delimiter = (!(multiplication % 2)) ? 2 : 3;
	while ((multiplication /= delimiter))
		counter++;
	e->pnt_dist = (int)(PNT_DIST / counter) + PNT_DIST;
}

void		fdf_get_win_img_size(t_env *e)
{
	int		default_win_img_size;
	int		multiplication;
	int		h_counter;
	int		l_counter;

	multiplication = e->xlen * e->ylen;
	default_win_img_size = 400;
	h_counter = 100;
	l_counter = 0;
	if (multiplication <= 1300)
	{
		while (!(l_counter >= multiplication && multiplication <= h_counter))
		{
			default_win_img_size += (h_counter > 400) ? 100 : 0;
			l_counter += 100;
			h_counter += 100;
		}
		e->win_img_size = default_win_img_size;
	}
	else
		e->win_img_size = MAX_WIN_IMG_SIZE;
}
