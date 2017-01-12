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
	// draw rectangles.
	draw_rectangle(100, 100, 550, 200, 4);
	draw_rectangle(100, 200, 550, 300, 15);
	draw_rectangle(100, 300, 550, 400, 2);

	// draw circles
	int rx = 325, ry = 250;

	int rad = 50;
	float dtheta = 1.0/rad;
	float deltaTheta = (PI/12.0);
	int i=0;
	float raddel = 0.0;
	float x, y;
	while(raddel <= 2*PI){
		x = rx + rad*cos(raddel);
		y = ry + rad*sin(raddel);
		putpixel(x, y, 1);
		raddel += dtheta;
	}
	raddel = 0.0;
	
	float angle = 0.0;
	// draw lines
	while(i<24){
		x = rx + rad*cos(raddel);
		y = ry + rad*sin(raddel);
		dda_line(rx, ry, x, y, 1);
		raddel += deltaTheta;
		i++;
	}

	getch();
	closegraph();
	return 0;
	
}
	
