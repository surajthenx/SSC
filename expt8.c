#include<stdio.h>
#include<stdlib.h>

void FIFO(char s[],char F[],int l,int f)
{
	int i,j=0,k,flag=0;
	printf("page\t frames\t faults");
	for(i=0;i<l;i++)
	{
		for(k=0;k<f;k++)
		{
			if(F[k]==s[i])
			{
				flag=1;
			}
		}
		printf("\n%c\t",s[i]);
		if(flag==0)
		{
			F[j++]=s[i];
			printf("%s",F);
			printf("\tfault");
		}
		else
		{
			flag=0;
			printf("%s",F);
			printf("\t hit");
		}
		if(j==f)
		{
			j=0;
		}
	}
}
void lru(char s[],char F[],int l,int f)
{
	int i,j=0,k,m,flag=0,top=0;
	printf("\n  page\t frames\t faults");
	for(i=0;i<l;i++)
	{
		for(k=0;k<f;k++)
		{
			if(F[k]==s[i])
			{
				flag=1;
				break;
			}
		}
		printf("\n%c\t",s[i]);
		if(j!=f && flag!=1)
		{
			F[top]=s[i];
			if(++j!=f)
			{
				top++;
			}
		}
	        else
		{
			if(flag!=1)
			{
				for(k=0;k<top;k++)
				{
					F[k]=F[k+1];
				}
				F[top]=s[i];
			}
			else
			{
				for(m=k;m<top;m++)
				{
					F[m]=F[m+1];
				}
				F[top]=s[i];
			}
		}
		printf("%s",F);
		if(flag==0)
			printf("\t faults");
		else
			printf("\t hit");
		flag=0;
	}
}
void main()
{
	int ch,i,f,l;
	char F[10],s[25];
	printf("enter the number of empty frames:");
	scanf("%d",&f);
	F[f]='\0';
	printf("enter the length of the string:");
	scanf("%d",&l);
	printf("enter the string:");
	scanf("%s",s);
	while(1)
	{
		printf("\n enter your choice:\n 1.FIFO\n 2.LRU\n 3.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:for(i=0;i<f;i++)
					F[i]=-1;
					FIFO(s,F,l,f);
					break;
			case 2:for(i=0;i<f;i++)
					F[i]=-1;
					lru(s,F,l,f);
					break;
			case 3:exit(0);
		}
	}
}			
