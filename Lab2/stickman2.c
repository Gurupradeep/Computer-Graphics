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

void bresLine(int x1,int y1,int x2,int y2)
{
    float m=(float)(y2-y1)/(x2-x1);
    int p;
   
    if(abs(m)<=1)
    {
        if(x1>x2)
        {
            swap(&x1,&x2);
            swap(&y1,&y2);
        }
        if(m>=0)
        {
            p=2*(y2-y1)-(x2-x1);
            putpixel(x1,y1,WHITE);
            while(x1<=x2)
            {
                x1++;
                if(p<=0)
                    p+=2*(y2-y1);
                else
                {
                    y1++;
                    p+=2*((y2-y1)-(x2-x1));
                }
                putpixel(x1,y1,WHITE);
            }
        }
        else
        {
            p=2*(y1-y2)+(x2-x1);
            putpixel(x1,y1,WHITE);
            while(x1<=x2)
            {
                x1++;
                if(p<=0)
                    p+=2*(y1-y2);
                else
                {
                    y1--;
                    p+=2*((y1-y2)+(x2-x1));
                }
                putpixel(x1,y1,WHITE);
            }
        }
    }
    else
    {
        if(y1>y2)
        {
            swap(&x1,&x2);
            swap(&y1,&y2);
        }
        if(m>=0)
        {
            p=2*(x2-x1)-(y2-y1);
            putpixel(x1,y1,WHITE);
            while(y1<=y2)
            {
                y1++;
                if(p<=0)
                    p+=2*(x2-x1);
                else
                {
                    x1++;
                    p+=2*((x2-x1)-(y2-y1));
                }
                putpixel(x1,y1,WHITE);
            }
        }
        else
        {
            p=2*(x1-x2)+(y2-y1);
            putpixel(x1,y1,WHITE);
            while(y1<=y2)
            {
                y1++;
                if(p<=0)
                    p+=2*(x1-x2);
                else
                {
                    x1--;
                    p+=2*((x1-x2)+(y2-y1));
                }
                putpixel(x1,y1,WHITE);
            }
        }
    }
}
void draw_spokes(int x, int y, int r)
{
   float i=0;
   while(i<=2*PI)
   {
        int x1 = r*cos(i);
        int y1 = r*sin(i);
        dda_line(x,y,x+x1,y+y1,WHITE);
        i = i + (PI/6);
   }
}    
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int i;
/*    printf("Enter The Transalational Distance : \n");
    int t;
    scanf("%d",&t);
    printf("t\n");*/
    int j;
    for(j = 0;j<=100;j++)
    {
    drawcircle(170+j,270,60,WHITE);
    drawcircle(350+j,270,60,WHITE);
    drawcircle(170+j,270,10,WHITE);
    drawcircle(250+j,270,10,WHITE);
    dda_line(170+j,280,250+j,280,WHITE);
    dda_line(170+j,260,250+j,260,WHITE);
    dda_line(170+j,170,350+j,170,WHITE);
    dda_line(260+j,270,175+j,170,WHITE);
    dda_line(260+j,270,350+j,170,WHITE);
    dda_line(170+j,270,170+j,170,WHITE);
    dda_line(350+j,270,350+j,170,WHITE);
  //  bresLine(275,275,350,175);
   // bresLine(175,175,175,275);
   // bresLine(350,175,350,275);
    dda_line(170+j,170,240+j,75,WHITE);
    drawcircle(240+j,55,20,WHITE);
    dda_line(240+j,75,350+j,150,WHITE);
    dda_line(350+j,170,350+j,150,WHITE);
    draw_spokes(170+j,270,60);
    draw_spokes(350+j,270,60);
    delay(200);
    cleardevice();
}
    delay(10000);
   
    closegraph();
    return 0;
}
