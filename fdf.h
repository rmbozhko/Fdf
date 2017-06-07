/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:24:01 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/24 17:36:32 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "get_next_line.h"

# define PNT_DIST 5
# define X_COND (b->x < e->win_img_size && b->x >= 0)
# define Y_COND (b->y < e->win_img_size && b->y >= 0)
# define DRAWING_PXL_COND (X_COND  && Y_COND)
# define MAX_WIN_IMG_SIZE 1300
# define Q e->angle * 3.14 / 180

typedef struct	s_pnt
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_pnt;

typedef struct	s_brezenheim
{
	t_pnt		temp_pnt;
	t_pnt		*l_pnt;
	int			x;
	int			y;
	int			del_x;
	int			del_y;
	int			sign_x;
	int			sign_y;
	int			error;
	int			error2;
	int			color;
}				t_brezenheim;

typedef struct	s_env
{
	int				xlen;
	int				ylen;
	int				pnt_dist;
	int				win_img_size;
	char			*av;
	int				angle;
	double			win_move_x;
	double			win_move_y;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*str;
	int				sl;
	int				endian;
	int				bpp;
	t_pnt			***fld_ptr;
}				t_env;

t_env			*fdf_create_structures_arr(char *av, t_env *e);
void			fdf_drawing_field(t_env *e, int x, int y, t_brezenheim *b);
void			fdf_no_map(void);
void			fdf_exit(t_env *e);
void			fdf_malloc_fail(void);
void			fdf_error(t_env *e);
int				key_hook(int keycode, t_env *e);
void			fdf_img_to_centre(t_env *e);
void			fdf_create_new_img(t_env *e);
int				fdf_pxl_color(int main_color);
void			fdf_zoom(t_env *e, int keycode);
void			fdf_rotate_x(t_env *e, int quarter);
void			fdf_rotate_y(t_env *e, int quarter);
void			fdf_rotate_z(t_env *e, int quarter);
void			fdf_get_pnt_distance(t_env *e);
void			fdf_get_win_img_size(t_env *e);
void			fdf_change_rotation_angle(t_env *e, int keycode);
void			fdf_gradient(t_env *e);
void			fdf_bresenheim(t_brezenheim *b, t_pnt *pnt1, t_env *e);
long int		fdf_get_pnt_distance_grad(t_pnt *pnt1, t_pnt *pnt2, int error2);
#endif
