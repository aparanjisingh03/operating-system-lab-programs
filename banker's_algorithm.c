#include<stdio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void show();
void cal();
int main()
{
	int i,j;
	printf("***bankers's algorithm***");
	printf("enter no.of process:\t");
	scanf("%d",&n);
	printf("enter no.of resource instances:\t");
	scanf("%d",&r);
	printf("enter the max matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("enter the allocation matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
    }
    printf("enter the available resources:\n");
    for(j=0;j<r;j++)
    {
    	scanf("%d",&avail[j]);
	}
		show();
		cal();
		return 0;
	}
	void show()
	{
		int i,j;
		printf("process\tallocation\tmax\tavailable\t");
		for(i=0;i<n;i++)
		{
			printf("\np%d\t",i);
			for(j=0;j<r;j++)
			{
				printf("%d",alloc[i][j]);
			}
			printf("\t\t");
			for(j=0;j<r;j++)
			{
				printf("%d",max[i][j]);
			}
			printf("\t\t");
			if(i==0)
			{
				for(j=0;j<r;j++)
				printf("%d",avail[j]);
			}
		}
	}
	void cal()
	{
		int finish[100],temp,need[100][100],flag=1,k,c1=0;
		int safe[100];
		int i,j;
		for(i=0;i<n;i++)
		{
			finish[i]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<r;j++)
			{
				need[i][j]=max[i][j]-alloc[i][j];
			}
		}
		printf("\n");
		while(flag)
		{
			flag=0;
			for(i=0;i<n;i++)
			{
				int c=0;
				for(j=0;j<r;j++)
				{
					if((finish[i]==0)&&(need[i][j]<=avail[j]))
					{
						c++;
						if(c==r)
						{
							for(k=0;k<r;k++)
							{
								avail[k]+=alloc[i][j];
								finish[i]=1;
								flag=1;
							}
							printf("p%d->",i);
							if(finish[i]==1)
							{
								i=n;
							}
						}
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(finish[i]==1)
			{
				c1++;
			}
			else
			{
				printf("p%d->",i);
			}
		}
		if(c1==n)
		{
			printf("\nthe system is in saferstate");
		}
		else
		{
			printf("\nprocess are in dead lock");
			printf("the system is in unsafe state");
		}  
}
