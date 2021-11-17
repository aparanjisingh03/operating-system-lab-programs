#include<stdio.h>
#include<math.h>
main()
{
	int np,nb,mm,bs,i,j,ps[100],nba[100],ifm[100],sb=0,flag=0;
	float x;
	printf("enter the memory size:");
	scanf("%d",&mm);
	printf("enter the no.of blocks:");
	scanf("%d",&nb);
	printf("enter the no.of processes:");
	scanf("%d",&np);
	bs=mm/nb;
	for(i=1;(i<=np)&&(sb<nb);i++)
	{
		printf("enter the size of ps[%d]:",i);
		scanf("%d",&ps[i]);
		if(ps[i]<=bs)
		nba[i]=1;
		else
		{
			x=ps[i]/(float)bs;
			nba[i]=(ceil)(x);
		}
		ifm[i]=nba[i]*bs-ps[i];
		sb=sb+nba[i];
		if(sb>nb)
		{
			i=i-1;
			flag=1;
		}
	}
	j=i;
	printf("process\tsize\tnba\tifm\n");
	for(i=1;i<j;i++)
	printf("%d\t%d\t%d\t%d\n",i,ps[i],nba[i],ifm[i]);
	if(flag==1)
	printf("memory space is unavailable");
}
