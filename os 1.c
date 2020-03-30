#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,i,j;
int a,b,c,x=0;
int var=0;
printf("---------------LET'S  START-------------------\n\n");
printf("ENTER NUMBER OF PROCESSES = ");
scanf("%d",&n);
int qu1[n],count=0;
int priority[n],process[n],btime[n],atime[n],rtime[n],tt[n],it[n],idle=0;
for(i=0;i<n;i++)
{
printf("\n For process %d : \n",i+1);
process[i]=i+1;
printf("enter priority = ");
scanf("%d",&priority[i]);
printf("enter burst time = ");
scanf("%d",&btime[i]);
printf("ARRIVAL TIME = ");
scanf("%d",&atime[i]);
}
a=n;
printf("\n");
printf("\n1)--------------------AFTER SORTING-----------------------");
int tq,t,remain,flag=0;
float waiting_time=0,turn_time=0;
int wt[n],tat[n]; 
float avwtime=0,avtatime=0;
int temp,pos;
                       //sorting according to arrival time
for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(atime[j]<atime[pos])
   			pos=j;
		}
		temp=btime[i];
		btime[i]=btime[pos];
		btime[pos]=temp;
            
		temp=atime[i];
		atime[i]=atime[pos];
		atime[pos]=temp;
		             
        temp=priority[i];
		priority[i]=priority[pos];
		priority[pos]=temp;
		
		temp=process[i];
		process[i]=process[pos];
		process[pos]=temp;
	}
printf("\n");
printf("\n1)--------------------process list-----------------------");
printf("\n\n");
printf(" ____________________________________________________________________________________________\n");
printf("|	QUEUE 1            |        PRIORITY	    | burst time          | arriaval time    |\n");
printf("|__________________________|________________________|_____________________|__________________|\n");
for(i=0;i<n;i++)
{
printf("|	  P%d		   ",process[i]);
printf("|         %d              ",priority[i]);
printf("|	  %d		  ",btime[i]);
printf("|	  %d	     |\n",atime[i]);
}
printf("|__________________________|________________________|_____________________|__________________|\n\n\n");
int total=0;
int wtime[n],ttime[n];
float avg_wtime,avg_tatime;
remain=a;
printf("\n\n----------ROUND ROBIN SCHEDULING FOR QUEUE ----------\n\n");
for(i=0;i<a;i++)
{
rtime[i]=btime[i];
}
printf("enter time quantum = ");
scanf("%d",&tq);
printf("_______________________________________________\n");
printf("|Process   |  Turnaround time |  Waiting time    |\n");
printf("|__________|__________________|__________________|\n");
int full=n;
while(full)
{
for(t=0,i=0;remain!=0;) 
{
//printf("\n\n i== %d   t== %d   \n\n",i,t); 
if(rtime[i]<=tq && rtime[i]>0)
{
t=t+rtime[i];
rtime[i]=0;
flag=1;
}
else if(rtime[i]>0)
{
rtime[i]=rtime[i]-tq;
t=t+tq;
}
if(rtime[i]==0 && flag==1)
{
remain--;
printf("|P%d      |         %d        |       %d          |\n",i+1,t-atime[i],t-atime[i]-btime[i]);
printf("|_________|___________________|___________________|\n");
waiting_time=waiting_time+t-atime[i]-btime[i];
turn_time=turn_time+t-atime[i];
flag=0;
full--;
}
if(i==a-1)
i=0;
if((atime[i+1]>t && rtime[i]==0))
{
	idle=idle+(atime[i+1]-t);
	t=(t+(atime[i+1]-t));
	i++;
}
else if(atime[i+1]<=t)
{
i++;
}
}
}
printf("\nCPU IDLE time : %d  \n",idle);
float utilization_percentage=(t-idle)*100;
printf("\nCPU utilization percentage : %f\n",utilization_percentage/t);
printf("\nAverage waiting time= %2f\n\n",waiting_time/a);
printf("Average turnaround time= %2f\n\n",turn_time/a);
}
