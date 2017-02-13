#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct NODE
{
	int x,y,c;
};
typedef struct NODE node;
int min(int []);
int check(node[],node[]);
void main()
{
	int i,a[3],j,small,sumx,sumy,count;
	node p[100];
	node c[3],temp[3];		
	for(i=0;i<100;i++)
	{
		p[i].x=rand()%1000;
		p[i].y=rand()%1000;
		p[i].c=0; 
	}
	for(i=0;i<3;i++)
	{
		c[i].x=rand()%1000;
		c[i].y=rand()%1000;
	}
	while(1)
	{
		for(i=0;i<3;i++)
		{
			temp[i].x=c[i].x;
			temp[i].y=c[i].y;
		}
		for(i=0;i<100;i++)
		{
			for(j=0;j<3;j++)
				a[j]=(int)sqrt((p[i].x-c[j].x)*(p[i].x-c[j].x)+(p[i].y-c[j].y)*(p[i].y-c[j].y));
			p[i].c=min(a);
		}
		for(j=0;j<3;j++)
		{
			sumx=sumy=count=0;
			for(i=0;i<100;i++)
			{
				if(p[i].c==j)
				{
					sumx+=p[i].x;
					sumy+=p[i].y;
					count++;
				}
			}
			c[j].x=sumx/count;
			c[j].y=sumy/count;
		}
		if(check(temp,c))
			break;
	}
	printf("Optimal locations are:\n");
	for(i=0;i<3;i++)
		printf("c[%d].x=%d c[%d].y=%d\n",i,c[i].x,i,c[i].y);
						
}
int min(int a[])
{
	int i,small=a[0],j=0;
	for(i=0;i<3;i++)
		if(a[i]<small)
		{
			small=a[i];
			j=i;
		}
	return j;
}
int check(node temp[],node c[])
{
	int i;
	for(i=0;i<3;i++)
		if((temp[i].x!=c[i].x)||(temp[i].y!=c[i].y))
			return 0;
	return 1;
}	
