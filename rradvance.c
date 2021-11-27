#include<stdio.h>
#include<curses.h>

#include<math.h>
#include<string.h>

int wt[100],bt[100],at[100],tat[00],n,p[100];
float awt[5],atat[5];
int temp1,temp2,temp3;



void input(){
   printf("Enter number of process:");
   scanf("%d",&n);
   int i;
   for(i=0;i<n;i++){
       p[i]=i+1;
    }
   for(i=0;i<n;i++){
      printf("enter burst times %d:",i+1);
      scanf("%d",&bt[i]);
      printf("Enter arrial tiime of the processs %d",i+1);
      scanf("%d",&at[i]);
    }
    
    for(int i=0;i<5;i++){
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

  void innovative(){
      
       int bt1[n],i,j,temp,qt;
       int b[n];
       
       float twt,ttat;
       for(i=0;i<n;i++)
         bt1[i]=bt[i];
         
       for(i=0;i<n;i++)
         b[i]=bt[i];
         
       int num=n;
       int time=0;
       int max;
       int sum,t,a,ap;
       ap=0;
       
       for(i=0;i<n;i++){
         for(j=0;j<n-i-1;j++){
               if(bt[j]>bt[j+1]){
                   
                    temp1=bt[j];
                    temp2=p[j];
                    temp3=at[j];
                    bt[j]=bt[j+1];
                    p[j]=p[j+1];
                    at[j]=at[j+1];
                    bt[j]=temp1;
                    p[j+1]=temp2;
                    at[j+1]=temp3;
                 }
           
       }
     }

     max=bt[n-1];
     sum=0;
     for(i=0;i<n;i++){
        sum=sum+bt[i];
     }
      float avg=sum/n;
      //printf("\n")
      qt=(avg+max)/2; 
      printf("\nDynamic Quantum time calculated is : %d\n",qt);
   
      while(num>0){ 
        a=0; 
        max=0; 
        sum=0; 
        t=0; 
  for(i=0;i<n;i++){ 
 
 
 
   if(at[i]<=time && b[i]!=0) 
   { 
    if(b[i]<qt) 
    { 
     t+=b[i]; 
     b[i]=0; 
    } 
    else 
    { 
     t+=qt; 
     b[i]-=qt; 
    } 
    if(b[i]<qt && b[i]!=0){ 
     t+=b[i]; 
     b[i]=0; 
    }
    if(b[i]==0){ 
     wt[i]=(time+t)-bt1[i]; 
     tat[i]=time+t; 
     num--; 
    } 
   } 
  } 
  time+=t; 
  } 
  printf("Processes\tWaitingtime\tTurnAroundTime\n"); 
  for(j=1;j<=n;j++) { 
      for(i=0;i<n;i++){ 
        if(j==p[i]) 
          printf("process %d\t%d\t\t%d\n",p[i],wt[i],tat[i]); 
    } 
   } 
 
  twt=0; 
  ttat=0; 
  for(i=0;i<n;i++) {

    twt=twt+wt[i];
  } 
  awt[4]=twt/n; 
  for(i=0;i<n;i++) {
     ttat=ttat+tat[i];
    } 
    atat[4]=(ttat/n);


  }
         
         
      
  
  int main(){
  char c;
  printf("\t\t***Welcome to CPU Scheduling***\n\n");
	input();
	changeArrival();
	innovative();
	display(6);
	return 0;
  }
    
