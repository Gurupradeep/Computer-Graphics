#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#define PI 3.14159

void reflect(int x1,int y1,int x2,int y2, int choice)
{
   
   if(choice==1)
   {
      //Reflection about y=250
    line(10,250,300,250);
    line(x1,500-y1,x2,500-y2);
   }
   else if(choice==2)
   {
      //Reflection about x=350
      line(350,10,350,300); 
     line(700-x1,y1,700-x2,y2);   
   }
}

void shear(float x[],float y[],int choice,float angle)
{
  int i=0;
  for(i=0;i<=7;i++)
  {
  if(choice==1)
   {
    if(i==0||i==4||i==5||i==2)
    x[i]=x[i]+tan(angle)*(y[i]);
  else
    x[i]=x[i];
   }
   else if(choice==2)
   {
      if(i==1||i==6||i==4||i==0)
      y[i]=y[i]-tan(angle)*x[i];
   }
   
   }  
}
void translate(float x[],float y[],float x1[],float y1[],int tx,int ty)
{
  int i;
  for(i=0;i<=7;i++)
  {
    x1[i]=x[i]+tx;
    y1[i]=y[i]+ty;
  }
}

int main() {
	int gd=DETECT,gm,choice,angle;
  printf("Enter the axis 1.X axis 2.Y axis \n");
  scanf("%d",&choice);
  printf("Enter the angle of shear in degrees\n");
  scanf("%d",&angle);
  initgraph(&gd, &gm, "X:\\TC\\BGI");
	float x[8],y[8],a,b,d,p,rx,ry,x1[8],y1[8];
  d=100;int i;
  p=d/1.414;


  x[0]=100;
  y[0]=100;
  x[1]=100;
  y[1]=200;
  x[2]=200;
  y[2]=100;
  x[3]=200;
  y[3]=200;
  x[4]=150;
  y[4]=70;
  x[5]=250;
  y[5]=70;
  x[6]=150;
  y[6]=170;
  x[7]=250;
  y[7]=170;

  // Uding a temporary array to store the original co ordinates of the cube
  for( i=0;i<=7;i++)
  {
    x1[i]=x[i];
    y1[i]=y[i];
  }
  //Cube
  line(x[0],y[0],x[1],y[1]);
  line(x[1],y[1],x[3],y[3]);
  line(x[2],y[2],x[3],y[3]);
  line(x[2],y[2],x[5],y[5]); 
  line(x[6],y[6],x[7],y[7]);
  line(x[3],y[3],x[7],y[7]);
  line(x[5],y[5],x[7],y[7]);
  line(x[1],y[1],x[6],y[6]);
  line(x[0],y[0],x[2],y[2]); 
  line(x[4],y[4],x[5],y[5]);
  line(x[4],y[4],x[6],y[6]);
  line(x[0],y[0],x[4],y[4]);   


  
  //Shear
  float rad=(PI/180)*angle;
  shear(x,y,choice,rad);

  //Setting the style of the line as dotted
  setlinestyle(1,1,1);

  //Shearing effect on the cube
  line(x[0],y[0],x[1],y[1]);
  line(x[1],y[1],x[3],y[3]);
  line(x[2],y[2],x[3],y[3]);
  line(x[2],y[2],x[5],y[5]); 
  line(x[6],y[6],x[7],y[7]);
  line(x[3],y[3],x[7],y[7]);
  line(x[5],y[5],x[7],y[7]);
  line(x[1],y[1],x[6],y[6]);
  line(x[0],y[0],x[2],y[2]); 
  line(x[4],y[4],x[5],y[5]);
  line(x[4],y[4],x[6],y[6]);
  line(x[0],y[0],x[4],y[4]);    

  // Getting back the original Co ordinates
  for( i=0;i<=7;i++)
  {
    x[i]=x1[i];
    y[i]=y1[i];
  }

  //Effect of reflection on the cube
  reflect(x[0],y[0],x[1],y[1],choice);
  reflect(x[1],y[1],x[3],y[3],choice);
  reflect(x[2],y[2],x[3],y[3],choice);
  reflect(x[2],y[2],x[5],y[5],choice); 
  reflect(x[6],y[6],x[7],y[7],choice);
  reflect(x[3],y[3],x[7],y[7],choice);
  reflect(x[5],y[5],x[7],y[7],choice);
  reflect(x[1],y[1],x[6],y[6],choice);
  reflect(x[0],y[0],x[2],y[2],choice); 
  reflect(x[4],y[4],x[5],y[5],choice);
  reflect(x[4],y[4],x[6],y[6],choice);
  reflect(x[0],y[0],x[4],y[4],choice); 

  getch();
  closegraph();
  return 0;
}
