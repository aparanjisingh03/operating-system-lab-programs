#include<stdio.h>
main()
{
	int n,i,j,size[20],sb[20],eb[20],t[20],x,c[20][20];
	printf("enter no.of files:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter no.of blocks occupied by the file%d:",i+1);
		scanf("%d",&size[i]);
		printf("enter the starting block of file%d:",i+1);
		scanf("%d",&sb[i]);
		t[i]=sb[i];
		for(j=0;j<size[i];j++)
		c[i][j]=sb[i]++;
	}
	for(i=0;i<n;i++)
	{
		eb[i]=t[i]+size[i]-1;
	}
	printf("filename\tlength\tstart block\tend block\n");
	for(i=0;i<n;i++)
	printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,size[i],t[i],eb[i]);
	printf("enter file name:");
	scanf("%d",&x);
	printf("file name is:%d\n",x);
	printf("length is:%d\n",size[x-1]);
	printf("blocks occupied:");
	for(i=0;i<size[x-1];i++)
	printf("%4d",c[x-1][i]);
	}
