#include "fdf.h"

void		fdf_error(void)
{
	printf("FD is crashed");
	//mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(0);
}

void		fdf_malloc_fail(void)
{
	printf("Your malloc has fallen!\n");
	exit(0);
}