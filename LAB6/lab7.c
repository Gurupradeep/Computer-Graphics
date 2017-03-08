#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define PI 3.142
int rx1=230,rx2=370,ry1=150,ry2=275,j=0,i;
float x2[20],y2[20];
float a[5],b[5];
void clip(float e,float f,float m)
{
while(e<rx1 || e>rx2 || f<ry1 || f>ry2)
{
if(e<rx1)
{
f+=m*(rx1-e);
e=rx1;
}
else if(e>rx2)
{
f+=m*(rx2-e);
e=rx2;
}
if(f<ry1)
{
e+=(ry1-f)/m;
f=ry1;
}
else if(f>ry2)
{
e+=(ry2-f)/m;
f=ry2;
}
}
x2[j]=e;
y2[j]=f;
j++;
}

/*void drawstar(float x,float y,int l)
{
a[0]=x;b[0]=y;
a[3]=x+l*cos(PI/3);b[3]=y-l*sin(PI/3);
a[2]=x+1.25*l*cos(PI/6);b[2]=y-1.25*l*sin(PI/6);
a[1]=a[3]+l*cos(PI/3);b[1]=b[3]+l*sin(PI/3);
a[4]=a[1]-1.25*l*cos(PI/6);b[4]=b[1]-1.25*l*sin(PI/6);

line(a[0],b[0],a[3],b[3]);
line(a[0],b[0],a[2],b[2]);
line(a[2],b[2],a[4],b[4]);
line(a[1],b[1],a[4],b[4]);
line(a[1],b[1],a[3],b[3]);
}*/

void drawstar(float x,float y,int l)
{
a[0]=x;b[0]=y;
a[1]=x+l*cos(PI/3);b[1]=y-l*sin(PI/3);
a[4]=x+1.25*l*cos(PI/6);b[4]=y-1.25*l*sin(PI/6);
a[2]=a[1]+l*cos(PI/3);b[2]=b[1]+l*sin(PI/3);
a[3]=a[2]-1.25*l*cos(PI/6);b[3]=b[2]-1.25*l*sin(PI/6);

for(i=0;i<4;i++)
line(a[i],b[i],a[i+1],b[i+1]);
line(a[i],b[i],a[0],b[0]);
}

void clipstar()
{
	float m;

	for(i=0;i<4;i++)
	{
	m=(b[i+1]-b[i])/(a[i+1]-a[i]);
	clip(a[i],b[i],m);
	clip(a[i+1],b[i+1],m);
	}
	m=(b[i]-b[0])/(a[i]-a[0]);
	clip(a[i],b[i],m);
	clip(a[0],b[0],m);
	rectangle(rx1,ry1,rx2,ry2);
	for(i=0;i<j-1;i++)
	line(x2[i],y2[i],x2[i+1],y2[i+1]);
}
int main()
{
	int gd=DETECT,gm=0;
	initgraph(&gd, &gm, "");
	drawstar(200,300,200);
	rectangle(rx1,ry1,rx2,ry2);
	getch();
	cleardevice();
	clipstar();
	getch();
	closegraph();
    return 0;
}