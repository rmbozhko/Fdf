/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:03:17 by rbozhko           #+#    #+#             */
/*   Updated: 2017/04/14 17:07:14 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_isometric(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			e->field_ptr[y][x]->y = (e->field_ptr[y][x]->x + 2 *
					e->field_ptr[y][x]->y + e->field_ptr[y][x]->z) / sqrt(6);
			e->field_ptr[y][x]->x = ((sqrt(3) * e->field_ptr[y][x]->x)
					- (sqrt(3) * e->field_ptr[y][x]->z)) / sqrt(6);
		}
	}
	fdf_drawing_field(e);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		fdf_exit(e);
	else if ((keycode == 69 || keycode == 78))
		fdf_zoom(e, keycode);
	else if (keycode == 83 || keycode == 86)
		(keycode == 83) ? fdf_rotate_x(e, 1) : fdf_rotate_x(e, -1);
	else if (keycode == 84 || keycode == 87)
		(keycode == 84) ? fdf_rotate_y(e, 1) : fdf_rotate_y(e, -1);
	else if (keycode == 85 || keycode == 88)
		(keycode == 85) ? fdf_rotate_z(e, 1) : fdf_rotate_z(e, -1);
	else if (keycode >= 18 && keycode <= 28)
		fdf_change_rotation_angle(e, keycode);
	else if (keycode == 76)
	{
		e->gradient = (!(e->gradient)) ? 1 : 0;
		fdf_drawing_field(e);
		printf("-----------------\n");
	}
	else
		printf("Keycode of the pressed button: %d\n", keycode);
	return (keycode);
}

int				main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
	{
		printf("No map was passed ....\n");
		return (-1);
	}
	e.av = argv[0];
	e.mlx_ptr = mlx_init();
	e.img_ptr = NULL;
	e.gradient = 0;
	fdf_create_structures_arr(argv[1], &e);
	e.win_ptr = mlx_new_window(e.mlx_ptr, e.win_img_size,
			e.win_img_size, "FDF 42");
	fdf_isometric(&e);
	fdf_drawing_field(&e);
	mlx_hook(e.win_ptr, 2, 0, key_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
