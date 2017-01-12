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

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	dda_line(x1,y1,x2,y2,BLUE);
	dda_line(x2,y2,x3,y3,BLUE);
	dda_line(x1,y1,x3,y3,BLUE);
}
int main()
{

	int gdriver = DETECT, gmode;
	// initialisations
	// 4 corner points for whole flag.
	initgraph(&gdriver, &gmode, " ");
	// draw rectangles.
	draw_rectangle(100, 100, 540, 130, WHITE);
	draw_rectangle(100, 130, 540, 180, BLUE);
	draw_rectangle(100, 180, 540, 340, WHITE);
	draw_rectangle(100, 340, 540,390, BLUE);
	draw_rectangle(100, 390, 540, 420, WHITE);
	
	int x[6],y[6];
	int i;
	float angle = (2*PI)/3;
	for(i=0;i<3;i++)
	{
		x[i] = 320 + 66*cos(PI/2 + i*angle);
		y[i] = 260 + 66*sin(PI/2 + i*angle);
		
		
	}
	
	draw_triangle(x[0],y[0],x[1],y[1],x[2],y[2]);
	
	for(i=0;i<3;i++)
	{
		x[i] = 320 + 66*cos(PI/6 + i*angle);
		y[i] = 260 + 66*sin(PI/6 + i*angle);
		
		
	}
	
	draw_triangle(x[0],y[0],x[1],y[1],x[2],y[2]);
	
	
	getch();
	closegraph();
	return 0;
	
}
	
