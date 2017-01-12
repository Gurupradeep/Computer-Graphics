#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define PI 3.14159



/* 
DDA algorihm

*/

float max(float x, float y)
{
	if(x>=y)
	    return x;
	else
            return y;         
}

void dda_line( int x1,int y1, int x2, int y2, int color)
{

	float x,y, dx, dy, pixel;
	dx=(x2-x1);
    	dy=(y2-y1);
    	pixel = max(abs(dx), abs(dy));
    	dx=dx/pixel;
    	dy=dy/pixel;
   	x=x1;
    	y=y1;
	int i=1;
    	while(i<=pixel)
    	{
      		putpixel(x,y, color);
      		x=x+dx;
      		y=y+dy;
      		i=i+1;
    	}
    return;
}


void draw_rectangle(int x1, int y1, int x2, int y2, int color)
{
	int i;
	for( i=y1;i<=y2;i++)
	{
		dda_line(x1,i,x2,i,color);
	}
	return ;
}

int main()
{

	int gdriver = DETECT, gmode;
	// initialisations
	// 4 corner points for whole flag.
	initgraph(&gdriver, &gmode, " ");
	int i,j;
	int toggle = 0;
	for(i =0;i<3;i++)
	{
		for(j= 0;j <3;j++)
		{
			if(toggle)
				draw_rectangle(100 + 100*j,100 +100*i,200 + 100*j, 200 + 100*i,RED);
			else
				draw_rectangle(100 + 100*j,100 +100*i,200 + 100*j, 200 + 100*i,BLUE);
			
			if(toggle == 0)
				toggle = 1;
			else
				toggle = 0;
				
		}
	}
	
	getch();
	closegraph();
	return 0;
}
