#include <stdio.h>
#include <graphics.h>
void main() 
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	int x1,y1,x2,y2,xmax,xmin,ymax,ymin,xx1,yy1,xx2,yy2,dx,dy,i;
	int p[4],q[4];
	float t1,t2,t[4];
	/*printf("Enter the lower co-ordinates of window");
	scanf("%d %d",&xmin,&ymin); 
	printf("Enter the upper co-ordinates of window");
	scanf("%d %d",&xmax,&ymax);*/
	xmin=100;
	ymin=100;
	xmax=400;
	ymax=400;
	setcolor(BLUE);
	rectangle(xmin,ymin,xmax,ymax);
	x1 = 50;
	y1 = 50;
	x2 = 50;
	y2 = 200;
/*	printf("Enter the points of line to be clipped: \n");
	scanf("%d %d",&x1,&y1);
	scanf("%d %d",&x2,&y2);*/
	
	line(x1,y1,x2,y2);
	dx=x2-x1;
	dy=y2-y1;
	p[0]=-dx;
	p[1]=dx;
	p[2]=-dy;
	p[3]=dy;
	q[0]=x1-xmin;
	q[1]=xmax-x1;
	q[2]=y1-ymin;
	q[3]=ymax-y1;
	for(i=0;i < 4;i++){ 
		if(p[i]!=0){
			t[i]=(float)q[i]/p[i];
		}
		else
			if(p[i]==0 && q[i] < 0)
				printf("Line completely outside the window");
			else
				if(p[i]==0 && q[i] >= 0)
					printf("Line completely inside the window");
	}
	if (t[0] > t[2]){
		t1=t[0];
	}
	else{
		t1=t[2];
	}
	if (t[1] < t[3]){
		t2=t[1];
	}
	else{
		t2=t[3];
	}
	if (t1 < t2){
		xx1=x1+t1*dx;
		xx2=x1+t2*dx;
		yy1=y1+t1*dy;
		yy2=y1+t2*dy;
		printf("line after clipping:");
		setcolor(WHITE);
		line(xx1,yy1,xx2,yy2);
	}
	else{
		printf("line lies out of the window");
	}
	getch();
}

