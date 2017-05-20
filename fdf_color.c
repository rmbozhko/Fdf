#include "fdf.h"

long int 	fdf_get_pnt_distance_grad(t_pnt *pnt1, t_pnt *pnt2, int error2)
{
	t_brezenheim	b;
	
	b.last_pnt = pnt2;
	b.x = (int)pnt1->x;
	b.y = (int)pnt1->y;
	b.last_pnt = pnt2;
	b.del_x = abs((int)b.last_pnt->x - b.x);
    b.del_y = abs((int)b.last_pnt->y - b.y);
    b.sign_x = b.x < (int)b.last_pnt->x ? 1 : -1;
    b.sign_y = b.y < (int)b.last_pnt->y ? 1 : -1;
    b.error = b.del_x - b.del_y;
    b.counter = 0;
    while(b.x != (int)b.last_pnt->x || b.y != (int)b.last_pnt->y) 
   {
        error2 = b.error * 2;
        if(error2 > -b.del_y) 
        {
            b.error -= b.del_y;
            b.x += b.sign_x;
            b.counter++;        
        }
        if(error2 < b.del_x) 
        {
            b.error += b.del_x;
            b.y += b.sign_y;
            b.counter++;
        }
    }
    return (b.counter);
}

int		fdf_pxl_color(int main_color)
{
	
	int		color;
	static int times = 0;
	if (main_color == 0)
	{
		if (times == 0)
		{
			color = 80;
			times++;
		}
		else if (times == 1)
		{
			color = 0;
			times++;
		}
		else if (times == 2)
		{
			color = 165;
			times++;
		}
	}
	else if ((main_color == 1) || (main_color == -1))
	{ 
		if (times == 0)
		{
			color = 50;
			times++;
		}
		else if (times == 1)
		{
			color = 0;
			times++;
		}
		else if (times == 2)
		{
			color = 50;
			times++;
		}
	}
	else if ((main_color >= 2 && main_color <= 3) || (main_color <= -2 && main_color >= -3))
	{
		if (times == 0)
		{
			color = 100;
			times++;
		}
		else if (times == 1)
		{
			color = 100;
			times++;
		}
		else if (times == 2)
		{
			color = 0;
			times++;
		}
	}
	else if (main_color >= 3 && main_color <= 4)
	{
		if (times == 0)
		{
			color = 93;
			times++;
		}
		else if (times == 1)
		{
			color = 51;
			times++;
		}
		else if (times == 2)
		{
			color = 93;
			times++;
		}
	}
	else if (main_color >= 5 && main_color <= 6)
	{
		if (times == 0)
		{
			color = 255;
			times++;
		}
		else if (times == 1)
		{
			color = 61;
			times++;
		}
		else if (times == 2)
		{
			color = 1;
			times++;
		}
	}
	else if (main_color >= 7 && main_color <= 8)
	{
		if (times == 0)
		{
			color = 98;
			times++;
		}
		else if (times == 1)
		{
			color = 50;
			times++;
		}
		else if (times == 2)
		{
			color = 45;
			times++;
		}
	}
	else if (main_color >= 9)
	{
		if (times == 0)
		{
			color = 51;
			times++;
		}
		else if (times == 1)
		{
			color = 255;
			times++;
		}
		else if (times == 2)
		{
			color = 51;
			times++;
		}
	}
	(times == 3) ? times = 0 : 0;
	return (color);
}