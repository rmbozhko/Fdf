/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:03:17 by rbozhko           #+#    #+#             */
/*   Updated: 2017/06/29 17:24:45 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		fdf_move_image(t_env *e, int keycode)
{
	t_brezenheim		b;

	if (keycode == 123)
		e->x -= e->angle;
	else if (keycode == 124)
		e->x += e->angle;
	else if (keycode == 126)
		e->y -= e->angle;
	else if (keycode == 125)
		e->y += e->angle;
	fdf_drawing_field(e, -1, -1, &b);
}

static	int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		fdf_exit(e);
	else if (keycode >= 123 && keycode <= 126)
		fdf_move_image(e, keycode);
	else if (keycode == 69 || keycode == 78)
		fdf_zoom(e, keycode);
	else if (keycode == 83 || keycode == 86)
		(keycode == 83) ? fdf_rotate_x(e, 1) : fdf_rotate_x(e, -1);
	else if (keycode == 84 || keycode == 87)
		(keycode == 84) ? fdf_rotate_y(e, 1) : fdf_rotate_y(e, -1);
	else if (keycode == 85 || keycode == 88)
		(keycode == 85) ? fdf_rotate_z(e, 1) : fdf_rotate_z(e, -1);
	else if (keycode >= 18 && keycode <= 28)
		fdf_change_rotation_angle(e, keycode);
	return (keycode);
}

static	void		display_menu(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 10, 0x6EDBBA,
			"Control: ");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 28, 0x6EDBBA,
			"Press 3 or 6 to rotate along the z axis");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 42, 0x6EDBBA,
			"Press 2 or 5 to rotate along the y axis");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 56, 0x6EDBBA,
			"Press 1 or 4 to rotate along the x axis");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 70, 0x6EDBBA,
			"Press + or - to zoom");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 84, 0x6EDBBA,
			"Move your Fdf with direction buttons.");
}

static	int			expose_hook(t_env *e)
{
	display_menu(e);
	return (0);
}

int					main(int argc, char **argv)
{
	t_env				e;
	t_brezenheim		b;

	if (argc != 2)
	{
		printf("No map was passed ....\n");
		return (-1);
	}
	e.av = argv[0];
	e.mlx_ptr = mlx_init();
	e.img_ptr = NULL;
	b.error2 = 0;
	e.y = 0;
	e.x = 0;
	e.angle = 1;
	fdf_create_structures_arr(argv[1], &e);
	e.win_ptr = mlx_new_window(e.mlx_ptr, e.win_img_size,
			e.win_img_size, "FDF 42");
	fdf_isometric(&e, &b);
	mlx_hook(e.win_ptr, 2, 0, key_hook, &e);
	mlx_expose_hook(e.win_ptr, expose_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
