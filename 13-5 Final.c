#include<stdio.h>
int time_of_arrival1[30],time_of_arrival2[30],p2[30],pr2[30],time_of_arrival3[30];
int time_of_burst1[30],time_of_burst2[30],time_of_burst3[30];

int full_tl=0,ft1=0,ft2=0,ft3=0;

int m,c,arrival_t[30],burst_t[30],proc[30],a=0,b=0,d=0;

int full_tl,z,temporary[30],cntr=0;
float avg_time_of_waiting1=0.0,avg_time_of_turnaround1=0.0;

int u,time_of_waiting3[30],time_of_turnaround3[30];
float avg_time_of_waiting3=0.0,avg_time_of_turnaround3=0.0;

int pst,q,temporary1,full_sum=0,time_of_waiting2[30],time_of_turnaround2[30];
float avg_time_of_waiting2,avg_time_of_turnaround2;

void rd_rn()
{
	printf("Time Quantum for Queue1 is 4\n");
	for(c=0;c<a;c++)
	{
	temporary[c]=time_of_burst1[c];
	} 
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	z=a;
 for(c=0,full_tl=0;z!=0;) 
 { 
 if(temporary[c]<=4&&temporary[c]>0) 
 {
	printf("\nProcess[%d] of Queue1 is running for %d units",c+1,temporary[c]); 
 full_tl=full_tl+temporary[c]; 
 temporary[c]=0; 
 cntr=1; 
 } 
 else if(temporary[c]>0) 
 {
	printf("\nProcess[%d] of Queue1 is running for 4 units",c+1); 
 temporary[c]=temporary[c]-4; 
 full_tl=full_tl+4; 
 } 
 if(temporary[c]==0&&cntr==1) 
 { 
 z--; 
 printf("\nProcess[%d]\t%d\t%d\t%d",c+1,time_of_burst1[c],full_tl-time_of_arrival1[c],full_tl-time_of_arrival1[c]-time_of_burst1[c]);
 avg_time_of_waiting1=avg_time_of_waiting1+full_tl-time_of_arrival1[c]-time_of_burst1[c]; 
 avg_time_of_turnaround1=avg_time_of_turnaround1+full_tl-time_of_arrival1[c]; 
 cntr = 0; 
 } 
 if(c==a-1) 
 {
 c=0; 
 }
 else if(time_of_arrival1[c+1]<=full_tl) 
 {
 c++;
 }
 else 
 {
 c=0;
 }
 } 
 avg_time_of_waiting1=avg_time_of_waiting1/a;
 avg_time_of_turnaround1=avg_time_of_turnaround1/a;
 printf("\nAverage Waiting Time:%f",avg_time_of_waiting1); 
 printf("\nAverage Turnaround Time:%f\n",avg_time_of_turnaround1); 
}

void prty()
{
	for(c=0;c<b;c++)
 {
 pst=c;
 for(q=c+1;q<b;q++)
 {
 if(p2[q]<p2[pst])
 {
 pst=q;
 }
 }
 temporary1=p2[c];
 p2[c]=p2[pst];
 p2[pst]=temporary1; 
 
 temporary1=time_of_burst2[c];
 time_of_burst2[c]=time_of_burst2[pst];
 time_of_burst2[pst]=temporary1;
 
 temporary1=pr2[c];
 pr2[c]=pr2[pst];
 pr2[pst]=temporary1;
 }
 time_of_waiting2[0]=0;
 for(c=1;c<b;c++)
 {
 time_of_waiting2[c]=0;
 for(q=0;q<c;q++)
 {
 time_of_waiting2[c]=time_of_waiting2[c]+time_of_burst2[a];
 }
 full_sum=full_sum+time_of_waiting2[c];
 }
 avg_time_of_waiting2=full_sum/b;
 full_sum=0;
 printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
 for(c=0;c<b;c++)
 {
 time_of_turnaround2[c]=time_of_burst2[c]+time_of_waiting2[c];
 full_sum=full_sum+time_of_turnaround2[c];
 printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",pr2[c],time_of_burst2[c],time_of_waiting2[c],time_of_turnaround2[c]);
 }
 avg_time_of_turnaround2=full_sum/b;
 printf("\nAverage Waiting Time:\t%f",avg_time_of_waiting2);
 printf("\nAverage Turnaround Time:\t%f\n",avg_time_of_turnaround2);
 
 for(c=0;c<b;c++)
 {
 while(time_of_burst2[c]!=0)
 {
 if(time_of_burst2[c]>10)
 {
	printf("\nProcess[%d] of Queue2 is running for 10 units",c+1);
	time_of_burst2[c]=time_of_burst2[c]-10;
	}
	else if(time_of_burst2[c]<=10)
	{
	printf("\nProcess[%d] of Queue2 is running for %d units",c+1,time_of_burst2[c]);
	time_of_burst2[c]=0;
	}
	}
	}

}

void sfcf()
{
	time_of_waiting3[0] = 0; 
 for(c=1;c<d;c++)
 {
 time_of_waiting3[c] = 0;
 for(u=0;u<d;u++)
 {
 time_of_waiting3[c]=time_of_waiting3[c]+time_of_burst3[u];
 }
 }
 printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
 for(c=0;c<d;c++)
 {
 time_of_turnaround3[c]=time_of_burst3[c]+time_of_waiting3[c];
 avg_time_of_waiting3=avg_time_of_waiting3+time_of_waiting3[c];
 avg_time_of_turnaround3=avg_time_of_turnaround3+time_of_turnaround3[c];
 printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\n",c+1,time_of_burst3[c],time_of_waiting3[c],time_of_turnaround3[c]);
 }
 avg_time_of_waiting3=avg_time_of_waiting3/d;
 avg_time_of_turnaround3=avg_time_of_turnaround3/d;
 printf("\nAverage Waiting Time=%f",avg_time_of_waiting3);
 printf("\nAverage Turnaround Time=%f",avg_time_of_turnaround3);
 for(c=0;c<d;c++)
 {
 while(time_of_burst3[c]!=0)
 {
 if(time_of_burst3[c]>10)
 {
	printf("\nProcess[%d] of Queue3 is running for 10 units",c+1);
	time_of_burst3[c]=time_of_burst3[c]-10;
	}
	else if(time_of_burst3[c]<=10)
	{
	printf("\nProcess[%d] of Queue2 is running for %d units",c+1,time_of_burst3[c]);
	time_of_burst3[c]=0;
	}
	}
	}
}

void rd_rn1()
{
	printf("Time Quantum between the 3 queues is 10\n");
	for(c=1;c<full_tl;c=c+10)
	{
	if(ft1>10)
	{
	printf("Queue1 is running for 10 units\n");
	ft1=ft1-10;
	}
	else if(ft1<=10&&ft1!=0)
	{
	printf("Queue1 is running for %d units\n",ft1);
	ft1=0;
	}
	if(ft2>10)
	{
	printf("Queue2 is running for 10 units\n");
	ft2=ft2-10;
	}
	else if(ft2<=10&&ft2!=0)
	{
	printf("Queue2 is running for %d units\n",ft2);
	ft2=0;
	}
	if(ft3>10)
	{
	printf("Queue3 is running for 10 units\n");
	ft3=ft3-10;
	}
	else if(ft3<=10&&ft3!=0)
	{
	printf("Queue3 is running for %d units\n",ft3);
	ft3=0;
	}
	}
}

int main()
{
	printf("Enter the no. of process you want to enter\n");
	scanf("%d",&m);
	for(c=0;c<m;c++)
	{
	printf("Enter details of process[%d]\n",c+1);
	printf("Arrival Time:");
	scanf("%d",&arrival_t[c]);
	printf("Burst Time:");
	scanf("%d",&burst_t[c]);
	printf("Priority(1 to 15):");
	scanf("%d",&proc[c]);
	full_tl=full_tl+burst_t[c];
	}
	for(c=0;c<m;c++)
	{
	if(proc[c]>=1&&proc[c]<=5)
	{
	printf("\n\nProcess[%d] belongs to Queue 1\n",c+1);
	time_of_arrival1[a]=arrival_t[c];
	time_of_burst1[a]=burst_t[c];
	a++;
	ft1=ft1+burst_t[c];
	}
	
	else if(proc[c]>=6&&proc[c]<=10)
	{
	printf("Process[%d] belongs to Queue 2\n",c+1);
	time_of_arrival2[b]=arrival_t[c];
	time_of_burst2[b]=burst_t[c];
	p2[b]=proc[c];
	pr2[b]=b+1;
	b++;
	ft2=ft2+burst_t[c];
	}
	
	else if(proc[c]>=11&&proc[c]<=15)
	{
	printf("Process[%d] belongs to Queue 3\n\n\n\n",c+1);
	time_of_arrival3[d]=arrival_t[c];
	time_of_burst3[d]=burst_t[c];
	d++;
	ft3=ft3+burst_t[c];
	}
	}
	
	rd_rn1();
	rd_rn();
	sfcf();
	prty();
	
	return 0;
}
