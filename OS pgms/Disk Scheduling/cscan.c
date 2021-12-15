#include<stdio.h>
int main()
{
	int i,j,seek=0,n;
	int temp,disk,dloc;
	float avg;
	printf("enter the number of loc\t");
	scanf("%d",&n);
	int d[n];
	printf("enter the position of head\t");
	scanf("%d",&disk);
	printf("enter elements of disk queue\n");
	for(i=2;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	d[n]=disk;
	d[0]=0;
	d[1]=99;
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
	seek+=d[n-1];
	printf("\n0--->%d    %d",d[n-1],seek);
	for(i=n-2;i>=(dloc+1);i--)
	{
		seek=seek+(d[i+1]-d[i]);
		printf("\n%d-->%d     %d",d[i+1],d[i],seek);
	}
	printf("\ntotal seek time:%d",seek);
	avg=seek/n;
	printf("\nmovement of average seek time %f",avg);
	return 0;
}

	

	
	
