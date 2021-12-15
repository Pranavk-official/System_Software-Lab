#include<stdio.h>
int main()
{
	int i,j,seek=0,n;
	int d[20],temp,disk,dloc;
	float avg;
	printf("enter the number of loc\t");
	scanf("%d",&n);
	printf("enter the position of head\t");
	scanf("%d",&disk);
	printf("enter elements of disk queue\n");
	for(i=1;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	d[n]=disk;
	d[0]=0;
	n=n+1;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(d[i]>d[j])
			{
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(disk==d[i])
		{
			dloc=i;
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d--->",d[i]);
	}
	for(i=dloc;i>0;i--)
	{
		seek=seek+(d[i]-d[i-1]);
		printf("\n%d--->%d    %d",d[i],d[i-1],seek);
	}
	printf("\n0--->%d    %d",d[dloc+1],seek);
	seek=seek+d[dloc+1];
	for(i=dloc+1;i<n-1;i++)
	{
		seek=seek+(d[i+1]-d[i]);
		printf("\n%d-->%d     %d",d[i],d[i+1],seek);
	}
	printf("\ntotal seek time:%d",seek);
	avg=seek/n;
	printf("\nmovement of average seek time %f",avg);
	return 0;
}

	
	
