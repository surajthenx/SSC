#include<stdio.h>
#include<stdlib.h>

int alloc[10][10],max[10][10],need[10][10],avail[10],work[10],finish[10],request[10];
int p,r,j,i,k,v=0,req=0,pno;

int check(int i)
{
	for(int j=0;j<r;j++)
	{
		if(need[i][j]>work[j])
		{
			return 0;
		}
		return 1;
	}
}

int main()
{
	printf("enter the number of processes and resources\n");
	scanf("%d%d",&p,&r);
	int seq[p];
	printf("enter the allocation matrix\n");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("enter the maximum matrix:\n");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("enter the available array\n");
	for(int i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
		work[i]=avail[i];
	}
	L1:
	for(i=0;i<p;i++)
	{
		finish[i]=0;
	}
	while(v<p)
	{
		int allocated=0;
		for(int i=0;i<p;i++)
		{
			if(!finish[i]&&check(i))
			{
				for(k=0;k<r;k++)
				{
					work[k]=work[k]+alloc[i][k];
				}
				allocated=finish[i]=1;
				seq[v]=i;
				v++;
			}
		}
		if(!allocated)
		{
			break;
		}
	}
	for(int i=0;i<p;i++)
	{
		if(finish[i]==0)
		{
			printf("safe sequences not generated\n");
			exit(0);
		}
	}
	printf("safe sequences is:\n");
	for(i=0;i<v;i++)
	{
		printf("p%d\t",seq[i]);
	}
	printf("\ndo you wnat to have a new resource request?(0/1)\n");
	scanf("%d",&req);
	if(req==0)
	{
		exit(0);
	}
	else
	{
		printf("enter the additional request\n");
		for(int i=0;i<r;i++)
		{
			scanf("%d",&request[i]);
		}
		printf("enter the processes number\n");
		scanf("%d",&pno);
		for(i=0;i<r;i++)
		{
			if(request[i]>need[pno][i])
			{
				printf("request is not granted  immidiatly\n");
				exit(0);
			}
			alloc[pno][i]+=request[i];
			work[i]=avail[i];
			work[i]-=request[i];
			need[pno][i]-=request[i];
			v=0;
		}
			goto L1;
	}
}
