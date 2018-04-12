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


