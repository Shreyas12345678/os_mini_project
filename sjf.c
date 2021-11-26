#include<stdio.h>
#include<curses.h>
#include<math.h>
#include<string.h>

int wt[100],bt[100],at[100],tat[100],n,p[100];
float awt[5],atat[5];
void main()
{
	float wavg=0,tavg=0,wsum=0,tsum=0;
	int i,j,temp;
	int sum=0,ta=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[i]<at[j])
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;

				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
			}
		}
	}
	int btime=0,min,k=1;
	for(j=0;j<n;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++)
		{
			if(btime>=at[i] && bt[i]<min)
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;

				temp=at[k];
				at[k]=at[i];
				at[i]=temp;

				temp=bt[k];
				bt[k]=bt[i];
				bt[i]=temp;
			}
		}
		k++;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		sum+=bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
	awt[1]=wsum/n;
	for(i=0;i<n;i++)
	{
		ta+=bt[i];
		tat[i]=ta-at[i];
		tsum+=tat[i];
	}
	atat[1]=(tsum/n);
	printf("SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n");
	for(i=0;i<n;i++)
	{
		printf("%3d\t%3d\t%3d\t%3d\t%4d\n",i+1,at[i],bt[i],wt[i],tat[i]);
	}
}