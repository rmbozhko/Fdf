static void		fdf_drawing_pxl(t_env *e, int x, int y, t_pnt *pnt)
{
	if (DRAWING_PXL_COND && (e->gradient == 0))
	{
		e->str[(4 * x + y * e->sl)] = fdf_pxl_color(pnt->color);
		e->str[(4 * x + y * e->sl + 1)] = fdf_pxl_color(pnt->color);
		e->str[(4 * x + y * e->sl + 2)] = fdf_pxl_color(pnt->color);
	}
	else if (DRAWING_PXL_COND && (e->gradient == 1))
	{
		// ((e->str[(4 * b.x1 + b.y1 * e->sl)] - ) /*First - Next pnt's color: blue*/ - (e->str[(4 * b.x2 + b.y2 * e->sl)] - )) /*Last pnt's color: blue*/ / //divide each of it by b.distance + (e->str[(4 * b.x2 + b.y2 * e->sl)] - ))
		// Do so for red and green and divide each of it by b.distance 
	}
}

void 			fdf_bresenheim(t_pnt *pnt1, t_pnt *pnt2, t_env *e, int error2)
{
	t_brezenheim	b;
	int 	x1 = (int)pnt1->x;
	int 	y1 = (int)pnt1->y;
	
	b.last_pnt = pnt2;
	b.next_pnt = pnt1;
	b.del_x = abs((int)b.last_pnt->x - x1);
    b.del_y = abs((int)b.last_pnt->y - y1);
    b.sign_x = x1 < (int)b.last_pnt->x ? 1 : -1;
    b.sign_y = y1 < (int)b.last_pnt->y ? 1 : -1;
    b.error = b.del_x - b.del_y;
    b.counter = 0;
    b.distance = fdf_get_pnt_distance_grad(*pnt1, *(b.last_pnt), 0);
    printf("%li\n", b.distance);
    (!(e->gradient)) ? fdf_drawing_pxl(e, (int)b.last_pnt->x, (int)b.last_pnt->y, b.last_pnt) : 0;
    while(x1 != (int)b.last_pnt->x || y1 != (int)b.last_pnt->y) 
   {
        (!(e->gradient)) ? fdf_drawing_pxl(e, x1, y1, pnt1) : 0;
        error2 = b.error * 2;
        if(error2 > -b.del_y) 
        {
            b.error -= b.del_y;
            x1 += b.sign_x;       
        }
        if(error2 < b.del_x) 
        {
            b.error += b.del_x;
            y1 += b.sign_y;
        }
    }
}