void	bresenheim_algorithm_floats(t_pnt *pnt1, t_pnt *pnt2, t_env *e)
{
	
    int signX;
    int signY;
    int error;

    signX = (int)pnt1.x < (int)pnt2->x ? 1 : -1;
    signY = (int)pnt1.y < (int)pnt2->y ? 1 : -1;
    e->del_x = abs((int)pnt2->x - (int)pnt1.x);
    e->del_y = abs((int)pnt2->y - (int)pnt1.y);
    error = e->del_x - e->del_y;
    fdf_drawing_pxl(e, (int)pnt2->x, (int)pnt2->y, pnt2->color);
    while((int)pnt1.x != (int)pnt2->x || (int)pnt1.y != (int)pnt2->y) 
   {
        fdf_drawing_pxl(e, (int)pnt1.x, (int)pnt1.y, pnt1.color);
        s_err = error * 2;
        if(s_err > -e->del_y) 
        {
            error -= e->del_y;
            pnt1.x += signX;
        }
        if(s_err < e->del_x) 
        {
            error += e->del_x;
            pnt1.y += signY;
        }
    }
}