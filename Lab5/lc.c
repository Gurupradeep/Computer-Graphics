#include <stdio.h>
#include <graphics.h>

void main()
{
	int gd=DETECT, gm;
	float xmax,ymax,xmin,ymin,x1,y1,x2,y2,m;
	float p[4],q[4],b_and[4];
/*	printf("Top left points of the view port: \n " );
	scanf("%f %f",&xmin,&ymin);
	printf("Bottom right part of the view port : \n");
	scanf("%f %f",&xmax,&ymax);*/
	xmin = 100;
	ymin = 100;
	xmax = 400;
	ymax = 400 ;
	printf("Enter the points of line to be clipped: \n");
	scanf("%f %f",&x1,&y1);
	scanf("%f %f",&x2,&y2);
	float x3=x1,y3=y1,x4=x2,y4=y2;
	initgraph(&gd,&gm,"");
	int i;
	for(i=0;i<4;i++)
	{
		p[i]=0;
		q[i]=0;
	}
	m=(y2-y1)/(x2-x1);
	if(x1 <xmin) 
		p[0]=1;
	if(x1 >xmax) 
		p[1]=1;
	if(y1 >ymax) 
		p[2]=1;
	if(y1 <ymin) 
		p[3]=1;
	if(x2 <xmin) 
		q[0]=1;
	if(x2 >xmax) 
		q[1]=1;
	if(y2 >ymax) 
		q[2]=1;
	if(y2 <ymin) 
		q[3]=1;

	for(i=0;i <4;i++)
	{
		b_and[i]=p[i]&&q[i];
	}
	if((b_and[0]==0)&&(b_and[1]==0)&&(b_and[2]==0)&&(b_and[3]==0))
	{
		if((p[0]==0)&&(p[1]==0)&&(p[2]==0)&&(p[3]==0)&&(q[0]==0)&&(q[1]==0)&&(q[2]==0)&&(q[3]==0))
		{
			cleardevice();
			printf("yo abda\n");
			rectangle(xmin,ymin,xmax,ymax);
			line(x1,y1,x2,y2);
			getch();
		}
		else
		{
			cleardevice();
			rectangle(xmin,ymin,xmax,ymax);
			getch();
			if((p[2]==0)&&(p[3]==1))
			{
 				x1=x1+(ymin-y1)/m;
 				y1=ymin;
			}
			if((q[2]==0)&&(q[3]==1))
			{
				x2=x2+(ymin-y2)/m;
 				y2=ymin;
			}
			if((p[2]==1)&&(p[3]==0))
			{
 				x1=x1+(ymax-y1)/m;
 				y1=ymax;
			}
			if((q[2]==1)&&(q[3]==0))
			{
 				x2=x2+(ymax-y2)/m;
 				y2=ymax;
			}
			if((p[1]==0)&&(p[0]==1))
			{
 				y1=y1+m*(xmin-x1);
	 			x1=xmin;
			}
			if((q[1]==0)&&(q[0]==1))
			{
 				y2=y2+m*(xmin-x2);
 				x2=xmin;
			}
			if((p[1]==1)&&(p[0]==0))
			{
 				y1=y1+m*(xmax-x1);
 				x1=xmax;
			}
			if((q[1]==1)&&(q[0]==0))
			{
 				y2=y2+m*(xmax-x2);
 				x2=xmax;
			}
			if(x1<=xmin &&x2<=xmin&&y1<=ymin &&y2<=ymin)
			{
				cleardevice();
				printf("Line is fully clipped");
				rectangle(xmin,ymin,xmax,ymax);
			}
			else if(x1>=xmax &&x2>=xmax&&y1>=ymax &&y2>=ymax)
			{
				cleardevice();
				printf("Line is fully clipped");
				rectangle(xmin,ymin,xmax,ymax);
			}
			else 
			{
			printf("yo\n");
			cleardevice();
			rectangle(xmin,ymin,xmax,ymax);
			line(x3,y3,x4,y4);
			setcolor(GREEN);
			line(x1,y1,x2,y2);
			getch();
			}
		}
		}
		else
		{
			cleardevice();
			printf("Line is fully clipped");
			rectangle(xmin,ymin,xmax,ymax);
		}
		getch();
		closegraph();
	}


