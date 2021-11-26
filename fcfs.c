#include<stdio.h>
#include<curses.h>
#include<curses.h>
#include<math.h>
#include<string.h>
int wt[100],at[100],bt[100],tat[100],n,p[100];
float awt[5],atat[5];
int temp1,temp2,temp3,sqt,avg;
void fcfs(){
wt[0]=0;
atat[0]=tat[0]=bt[0];
int btt=bt[0];
int i;
for(i=1;i<n;i++){
wt[i]=btt-at[i];
btt+=bt[i];
awt[0]+=wt[i];
tat[i]=wt[i]+bt[i];
atat[0]+=tat[i];
}
atat[0]/=n;
awt[0]/=n;
printf("SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n");
for(i=0;i<n;i++)
{
printf("%3d\t%3d\t%3d\t%3d\t%4d\n",i+1,at[i],bt[i],wt[i],tat[i]);
}
}
void input()
{
printf("Enter number of processes: ");
scanf("%d",&n);
int i;
for(i=0;i<n;i++)
p[i]=i+1;
for(i=0;i<n;i++)
{
printf("Enter Burst Time of process %d:",i+1);
scanf("%d",&bt[i]);
printf("Enter Arrival Time of process %d:",i+1);
scanf("%d",&at[i]);}

for(i=0;i<5;i++)
{
awt[i]=0.0;
atat[i]=0.0;
}
}
void changeArrival(){
int a=at[0];
int i;
for(i=0;i<n;i++){
if(at[i]<a)
a=at[i];
}
if(a!=0){
for(i=0;i<n;i++)
at[i]=at[i]-a;
}
}
void display(int c)
{
int i;
printf("Average Waiting time:%f\nAverage Turn Around Time:%f",awt[c-2],atat[c-2]);
}
int main(){char c;
printf("\t\t***Welcome to CPU Scheduling***\n\n");
input();
changeArrival();
fcfs();
display(c);
}




