#include<stdio.h>
struct fcfs
{
int at,st,str,ft,tat,wt;
}p[50];


main()
{
int i,j,n;
float atrt=0,awt=0;
printf("\nEnter the number of processes:");
scanf("%d",&n);
printf("\nEnter the arrival times of the processes");
for(i=0;i<n;i++)
scanf("%d",&p[i].at);
printf("\nEnter the service times of the processes");
for(i=0;i<n;i++)
scanf("%d",&p[i].st);
p[0].str=p[0].at;
for(j=0;j<n;j++)
{
p[j].ft=p[j].str+p[j].st;
p[j+1].str=p[j].ft;
}
for(i=0;i<n;i++)
{
p[i].tat=p[i].ft-p[i].at;
atrt=atrt+p[i].tat;
p[i].wt=p[i].str-p[i].at;


awt=awt+p[i].wt;
}
printf("process\tAT\tST\tSTR\tFT\tTAT\tWT\n");
for(i=0;i<n;i++)
{
printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p[i].st,p[i].str,p[i].ft,p[i].tat,p[i].wt);
}
atrt=atrt/n;
awt=awt/n;
printf("Average turn around time=%f",atrt);
printf("Average waiting time=%f",awt);
}


