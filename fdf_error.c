/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:35:51 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/24 17:42:38 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_error(t_env *e)
{
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(0);
}

void		fdf_malloc_fail(void)
{
	exit(0);
}

void		fdf_exit(t_env *e)
{
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(0);
}
