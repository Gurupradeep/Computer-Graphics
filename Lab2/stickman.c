#include <stdio.h>
#include <graphics.h>
#include <math.h>

void pixel(int xc, int yc, int x, int y,int color)
{
	 putpixel(xc+x,yc+y,color);
         putpixel(xc+y,yc+x,color);
         putpixel(xc-y,yc+x,color);
         putpixel(xc-x,yc+y,color);
         putpixel(xc-x,yc-y,color);
         putpixel(xc-y,yc-x,color);
         putpixel(xc+y,yc-x,color);
         putpixel(xc+x,yc-y,color);
}

void midpoint_circle(int xc, int yc, int r, int color)
{
	int x = 0;
	int y = r;
	int p = 1-r;
	pixel(xc,yc,x,y,color);
	while(x<y)
	{
		if(p<0)
		{
			x = x + 1;
			p = p + 2*x + 1;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p = p + (2*x) -(2*y) +1;
		}
		pixel(xc,yc,x,y,color);
	}
}
	
	

void bresenham_line(int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	float m = (float)dy/dx;
	int x;
	int y;
	int end;
	int p;
	if(x1!=x2)
	{
		if(abs(m) <= 1)
		{	
			if(x1 > x2)
			{
				x = x2;
				y = y2;
				end = x1;
			}
			else
			{
				x = x1;
				y = y1;
				end = x2;
			}
		
			if( m >=0)
			{
				printf("Hello");
				p = 2*dy - dx;
		
				putpixel(x,y,color);
		
				while(x<end)
				{
					if(p<0)
					{
						x = x + 1;
						putpixel(x,y,color);
						p = p + 2*dy;
					}
					else
					{
						x = x + 1;
						y = y + 1;
						p = p + 2*(dy - dx);
						putpixel(x,y,color);
					}
				}
			}
			else
			{
				printf("Hello");
				p  = 2*dy + dx;
				putpixel(x,y,color);
		
				while(x<end)
				{
					if(p<0)
					{
						x = x + 1;
						putpixel(x,y,color);
						p = p + 2*dy;
					}
					else
					{
						x = x + 1;
						y = y - 1;
						p = p + 2*(dx - dy);
						putpixel(x,y,color);
					}
				}
			}
		}
	}
	else
	{
		while(y1 < y2)
		{
			putpixel(x1,y1,color);
			y1++;
		}
	}
}
	

int main()
{

	int gdriver = DETECT, gmode;
	// initialisations
	// 4 corner points for whole flag.
	initgraph(&gdriver, &gmode, " ");
	bresenham_line(300,100,300,200,GREEN);
	
	//bresenham_line(100,200,101,600,BLUE);
	midpoint_circle(300,50,50,GREEN);
	
	bresenham_line(300,200,375,175,GREEN);
	
	getch();
	closegraph();
	return 0;
}
