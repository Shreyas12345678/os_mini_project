#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
// #include<conio.h>

int wt[100],bt[100],at[100],tat[100],n,p[100];
float awt[5],atat[5];
int temp1,temp2,temp3,sqt,avg;
void changeArrival()
{
    int a = at[0];
    int i;
    for(i=0;i<n;i++)
    {
        if(at[i] < a)
        {
            a = at[i];
        }
    }
    if(a != 0){
        for(i=0;i<n;i++)
            at[i] = at[i] - a;
    }
}
void input()
{
 printf("Enter Number of processes:");
 scanf("%d",&n);
 int i;
for(i=0;i<n;i++)
p[i]=i+1;
 for(i=0;i<n;i++)
 {
 printf("Enter Burst Time of process %d:",i+1);
 scanf("%d",&bt[i]);
 printf("Enter Arrival Time of process %d:",i+1);
 scanf("%d",&at[i]);
 }
for(i=0;i<5;i++)
{
awt[i]=0.0;
atat[i]=0.0;
}
}

void rr()
{
int i, total = 0, x, counter = 0, time_quantum;
 int wait_time = 0, turnaround_time = 0, temp[100];
x=n;
for(i = 0; i < n; i++)
 {
temp[i] = bt[i];
 }
 printf("\nEnter Time Quantum:\t");
 scanf("%d", &time_quantum);
 printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
 for(total = 0, i = 0; x != 0;)
 {
 if(temp[i] <= time_quantum && temp[i] > 0)
 {
 total = total + temp[i];
 temp[i] = 0;
 counter = 1;
 }
 else if(temp[i] > 0)
 {
 temp[i] = temp[i] - time_quantum;
 total = total + time_quantum;
 }
 if(temp[i] == 0 && counter == 1)
 {
 x--;
printf("Process[%d]\t\t%d\t\t %d\t\t\t %d\n", i + 1, bt[i], total -
at[i], total - at[i] - bt[i]);
 wait_time = wait_time + total - at[i] - bt[i];
 turnaround_time = turnaround_time + total - at[i];
 counter = 0;
 }
 if(i == n - 1)
 {
i = 0;
}
 else if(at[i + 1] <= total)
 {
i++;
}
 else
 {
i = 0;
}
}
awt[2] = wait_time * 1.0 / n;
atat[2] = turnaround_time * 1.0 / n;
}

void display(int c)
{
 int i;
 printf("Average Waiting Time: %f\nAverage Turn Around Time:%f",awt[c-2],atat[c-2]);
}

int main(){
 printf("\t\t***Welcome to CPU Scheduling*\n\n");
 int c,choice;
 do
 {
 printf("\n1\tEnter the data \n\n\t\tAlgorithms available for CPU scheduling are\n \n2\tFCFS Algorithm\n3\tSJF Algorithm\n4\tRound robin\n5\tSRTF Algorithm\n6\tOur innovative algorithm\n");
 printf("\n\t\tEnter your choice from the above table: ");
 scanf("%d",&c);
 switch(c)
 {
 case 1:input();changeArrival(); break;
 // case 2:fcfs();display(c);break;
 // case 3:sjf();display(c);break;
 case 4:rr();display(c);break;
 // case 5:srtf();display(c);break;
 // case 6:innovative();display(c);break;
 default: printf("Please enter choice from 1 to 6 only\n");break;
 }
 printf("\n\n\t\tPress 1 to continue or 0 for Exit\n\t\tEnter your choice: ");
 scanf("%d",&choice);
 if(choice==0)
 printf("\nThank You!\n");
 }while(choice==1);
}