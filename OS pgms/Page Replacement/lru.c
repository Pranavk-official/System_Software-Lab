#include<stdio.h>
#include<stdlib.h>
#define max 100
#define min 10
int ref[max],count,frame[min],n;
void input()
{
	int temp;
	count=0;
	printf("enter no of page frames:");
	scanf("%d",&n);
	printf("\nente rthe reference string:");
	scanf("%d",&temp);
	while(temp !=-1)
	{
		ref[count++]=temp;
		scanf("%d",&temp);
	}
}
void lru()
{
	int i,j,k,stack[min],top=0,fault=0;
	//system("CLS");
	for(i=0;i<count;i++)
	{
		if(top<n)
			stack[top++]=ref[i],fault++;
		else
		{
			for(j=0;j<n;j++)
			if(stack[j]==ref[i])
			break;
			if(j<n)
			{
				for(k=0;k<n-1;k++)
				stack[k]=stack[k+1];
				stack[k]=ref[i];
			}
			else
			{
				for(k=0;k<n-1;k++)
				stack[k]=stack[k+1];
				stack[k]=ref[i];
				fault++;
			}
		}
		printf("\nafter inserting %d the stack status is:",ref[i]);
		for(j=0;j<top;j++)
		printf("%d",stack[j]);
	}
	printf("\nend to inserting the ref string");
	printf("\n total page fault is %d",fault);
	printf("\npress any key top conjtinue:");
}
int main()
{
	int x;
	while(1)
	{
		printf("\n...MENU...\n1.input\n2.lru\n0.exit");
		printf("\nenter your choice:");
		scanf("%d",&x);
		switch(x)
		{
			case 1:input();
					break;
			case 2:lru();
					break;
			case 0:exit(0);
		}
	}
	return 0;
}					
