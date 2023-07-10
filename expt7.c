#include<stdio.h>
#include<stdlib.h>
struct J
{
	int id,bt,tat,wt,at,ft;
}job[100];

void scheduler(struct J job[],int n,int q,int c)
{
	int burst[100],t=0,done=0,curr=0,diff=q,i=0;
	float tat_sum=0,wt_sum=0;
	for(i=0;i<n;i++)
		burst[i]=job[i].bt;
	if(c==0)
		curr=-1;
	while(done<n)
	{
		if(c==1)
		{
			for(int x=0;x<n;x++)
			{
				if(job[curr].bt==0)
					curr=x;
				if(job[x].bt<job[curr].bt&&job[x].bt>0&&job[x].at<=t)
					curr=x;
			}
			diff=1;
		}
		else
		{
			while(1)
			{
				curr=(curr+1)%n;
				if(job[curr].bt!=0)
				break;
			}
			diff=(q<=job[curr].bt)?q:job[curr].bt;
		}
		job[curr].bt-=diff;
		t+=diff;
		if(job[curr].bt==0)
		{
			done++;
			job[curr].ft=t;
		}
	}
	if(c==1)
		printf("SRTF DETAILS ARE\n");
	else
		printf("RR SCHRDULING DETAILS ARE:\n");
	for(i=0;i<n;i++)
	{
		job[i].bt=burst[i];
		job[i].tat=job[i].ft-job[i].at;
		job[i].wt=job[i].tat-job[i].bt;
		tat_sum+=job[i].tat;
		wt_sum+=job[i].wt;
	}
	printf("job\tBT\tAT\tTAT\tWT\n");
	for(i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\n",i+1,job[i].bt,job[i].at,job[i].tat,job[i].wt);
		printf("Avg TAT=%f\n Avg WT=%f\n",tat_sum/n,wt_sum/n);
}
void main()
{
	int n,q,c,i;
	printf("enter the number of processes:\n");
	scanf("%d",&n);
	printf("enter the arrival time and burst time\n");
	for(i=0;i<n;i++)
	{
		printf("job%d:",i+1);
		scanf("%d%d",&job[i].at,&job[i].bt);
	}
	while(1)
	{
		printf("enter your choice:\n");
		printf("1.RR\n2.SRJF\n3.exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("enter the time quantum:");
			      scanf("%d",&q);
			      scheduler(job,n,q,0);
			      break;
			case 2:scheduler(job,n,1,1);
				break;
			case 3:exit(0);
		}
	}
}	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
