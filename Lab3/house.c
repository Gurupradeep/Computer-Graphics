#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define pi 3.14


int sign(x)
{
	if(x>0)
		return 1;
	else if(x<0)
	 	return -1;
	else
	 	return 0;
}


void drawline(int x1,int y1, int x2, int y2)
{
	int x,y,dx,dy,swap,temp,s1,s2,p,i;
	x=x1;
	y=y1;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	swap=0;
	putpixel(x1,y1,WHITE);
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		swap=1;
	}
	p=2*dy-dx;
	for(i=0;i<dx;i++)
	{
		
		if(p>=0)
	  	{
	  		p=p-2*dx;
	  		if(swap)
	   			x+=s1;
	  		else
	   			y+=s2;
	  	}
	  	p=p+2*dy;
	 	if(swap)
	  		y+=s2;
	 	else
	  		x+=s1;
	  putpixel(x,y,WHITE);
 	}
	putpixel(x2,y2,WHITE);
}

void pixel(int xc,int yc,int x,int y)
{
            putpixel(xc+x,yc+y,7);
            putpixel(xc+y,yc+x,7);
            putpixel(xc-y,yc+x,7);
            putpixel(xc-x,yc+y,7);
            putpixel(xc-x,yc-y,7);
            putpixel(xc-y,yc-x,7);
            putpixel(xc+y,yc-x,7);
            putpixel(xc+x,yc-y,7);
}

void drawcircle(int xc,int yc,int r)
{
	int x,y,Pk;
		x=0;
        y=r;
        Pk=1-r;
       
        while(x<y)
        {
        	pixel(xc,yc,x,y);
        	if(Pk<0)
                {
                    x=x+1;
                    Pk=Pk+(2*x)+1;
                }
                else
                {
                    x=x+1;
                    y=y-1;
                    Pk=Pk+(2*x)-(2*y)+1;
                }
                
         }
            
}

void reflect(int x[],int y[],int x1[],int y1[])
{
	int choice,i;
	printf("Enter the axis 1.X axis 2.Y axis");
	scanf("%d",&choice);
	if(choice==2)
	{
		for(i=1;i<18;i++)
		{
			x1[i]=x[i]-2*(x[i]-260)+10;
			y1[i]=y[i];
		}
	}
	else if(choice==1)
	{
		for(i=1;i<18;i++)
		{
			y1[i]=y[i]-2*(y[i]-300) + 10;
			x1[i]=x[i];
		}
	}
}

void shear(int x[],int y[],int x1[],int y1[])
{
	int choice,i;
	printf("Enter the axis 1.X axis 2.Y axis");
	scanf("%d",&choice);
	if(choice==2)
	for(i=1;i<18;i++)
	{
		if(i==4||i==2)
			{
				x1[i]=x[i];
				y1[i]=y[i];
			}
			else{
		y1[i]=(x[i]-260)*tan(pi/6)+y[i];//Angle of shear=30 degrees
		x1[i]=x[i];
	}
	}
	else if(choice==1)
	{
		for(i=1;i<14;i++)
		{
			if(i==5||i==7||i==1||i==2)
			{
				x1[i]=x[i];
				y1[i]=y[i];
			}
			else{
			x1[i]=x[i]+tan(pi/6)*(y[i]-300);  //Angle of sheer = 30 degrees
			y1[i]=y[i];
		}
		}

	}
	
}
void house(int x[],int y[],int color)
{
	
	setcolor(color);
	line(x[1],y[1],x[2],y[2]);
	line(x[1],y[1],x[3],y[3]);
	line(x[2],y[2],x[4],y[4]);
	line(x[4],y[4],x[3],y[3]);
	line(x[5],y[5],x[6],y[6]);
	line(x[7],y[7],x[8],y[8]);
	line(x[8],y[8],x[6],y[6]);
	line(x[3],y[3],x[9],y[9]);
	line(x[9],y[9],x[4],y[4]);
	line(x[11],y[11],x[13],y[13]);
	line(x[13],y[13],x[10],y[10]);
	line(x[10],y[10],x[12],y[12]);
	line(x[12],y[12],x[11],y[11]);
	line(x[14],y[14],x[15],y[15]);
	line(x[16],y[16],x[17],y[17]);
}

void main()
{

	int tx;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\BGI\\");
	int x[20],y[20],x1[20],y1[20];
	x[1]=100,y[1]=300;
	x[2]=260,y[2]=300;
	x[3]=100,y[3]=150;
	x[4]=260,y[4]=150;
	x[5]=160,y[5]=300;
	x[6]=160,y[6]=200;
	x[7]=200,y[7]=300;
	x[8]=200,y[8]=200;
	x[9]=180,y[9]=120;
	x[10]=240,y[10]=180;
	x[11]=220,y[11]=220;
	x[12]=220,y[12]=180;
	x[13]=240,y[13]=220;
	x[14]=(x[12]+x[10])/2;
	y[14]=(y[12]+y[10])/2;
	x[15]=(x[11]+x[13])/2;
	y[15]=(y[11]+y[13])/2;
	x[16]=(x[12]+x[11])/2;
	y[16]=(y[12]+y[11])/2;
	x[17]=(x[13]+x[10])/2;
	y[17]=(y[13]+y[10])/2;
	int color=GREEN;

	house(x,y,color);
	int ch;
	
	printf("Enter choice 1.Reflect 2.Shear\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		color=BLUE;
		reflect(x,y,x1,y1);
		house(x1,y1,color);
	}
	else if(ch==2)
	{
		color=BLUE;
		shear(x,y,x1,y1);
		house(x1,y1,color);
	}

	getch();
	closegraph();
}