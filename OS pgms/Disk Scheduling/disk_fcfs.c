#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,head,i,j,seek=0,diff;
	float avg;
	printf("enter the size of queue request\n");
	scanf("%d",&n);
	int queue[n];
	printf("enetr the initial head positions\n");
	scanf("%d",&head);
	queue[0]=head;
	printf("enter the  disk positions to be read\n");
	for(i=1;i<=n;i++)
		scanf("%d",&queue[i]);
	for(j=0;j<n;j++)
	{
		if(queue[j]>queue[j+1])
			diff=queue[j]-queue[j+1];
		else
			diff=queue[j+1]-queue[j];	
		seek+=diff;
		printf("disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
	}
	printf("total seek time is %d\n",seek);
	avg=seek/n;
	printf("avg seek time is %f\n",avg);
	return 0;
}

