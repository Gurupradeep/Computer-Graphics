#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define PI 3.14159

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
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

void drawcircle(int xc, int yc, int r, int color)
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
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int x[10];
    int y[10];
    int j;
    j = 0;
    float i = 0;
    while(i<=2*PI)
    {
        x[j] = 100 + 50*cos(i);
        y[j] = 250 + 50*sin(i);
        i = i + (2*PI)/5;
        j++;
    }
   for(j=0;j<4;j++)
    {
        dda_line(x[j],y[j],x[j+1],y[j+1],WHITE);
    }
    dda_line(x[4],y[4],x[0],y[0],WHITE);
    //Translation
    for(j=0;j<4;j++)
    {
        dda_line(x[j]+100,y[j],x[j+1]+100,y[j+1],WHITE);
    }
    dda_line(x[4]+100,y[4],x[0]+100,y[0],WHITE);

    //scaling
    for(j=0;j<4;j++)
    {
        dda_line(0.5*(x[j]+100),0.5*(y[j]),0.5*(x[j+1]+100),0.5*y[j+1],WHITE);
    }
    dda_line(0.5*(x[4]+100),0.5*y[4],0.5*(x[0]+100),0.5*y[0],WHITE);

    //rotation
    i = 30;
    int x1[10];
    int y1[10];
    j = 0;
    while(i<=4*PI)
    {
        x1[j] = 100 + 50*cos(i);
        y1[j] = 250 + 50*sin(i);
        i = i + (2*PI)/5;
        j++;
    }
    for(j=0;j<4;j++)
    {
        dda_line(x1[j],y1[j],x1[j+1],y1[j+1],WHITE);
    }
    dda_line(x1[4],y1[4],x1[0],y1[0],WHITE);
    for(j=0;j<4;j++)
    {
        dda_line(x[j]*cos(PI/6) -y[j]* sin(PI/6),x[j]*sin(PI/6) + y[j] * cos(PI/6),x[j+1]*cos(PI/6) -y[j+1]* sin(PI/6),x[j+1]*sin(PI/6) + y[j+1] * cos(PI/6),WHITE);
    }
    dda_line(x[4]*cos(PI/6) -y[4]* sin(PI/6),x[4]*sin(PI/6) + y[4] * cos(PI/6),x[0]*cos(PI/6) -y[0]* sin(PI/6),x[0]*sin(PI/6) + y[0] * cos(PI/6),WHITE);
    //Translation
    delay(10000);
   
    closegraph();
    return 0;
}
