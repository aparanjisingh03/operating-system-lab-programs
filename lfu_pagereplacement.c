#include<stdio.h>
int main()
{
	int i,j,k,f,min,p,pf=0,count[10],pageref[25],fp[10],n;
	printf("\nenter the length of pag reference string:");
	scanf("%d",&n);
	printf("\nenter the reference string:");
	for(i=0;i<n;i++)
	scanf("%d",&pageref[i]);
	printf("\nenter no. of frames:");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		fp[i]=-1;
		count[i]=0;
	}
	printf("\npage replacement process is:\n");
	for(i=0;i<n;i++)
	{
		for(k=0;k<f;k++)
		{
			if(fp[k]==pageref[i])
			{
				count[k]++;
				break;
			}
		}
		if(k==f)
		{
			min=100;
			for(j=0;j<f;j++)
			{
				if(count[j]<min)
				{
					min=count[j];
					p=j;
				}
			}
			fp[p]=pageref[i];
			count[p]=1;
			pf++;
			printf("page fault %d",pf);
		}
		for(j=0;j<f;j++)
		printf("\t%d",fp[j]);
		printf("\n");
	}
	printf("\nthe number of page faults using lfu are %d",pf);
}
