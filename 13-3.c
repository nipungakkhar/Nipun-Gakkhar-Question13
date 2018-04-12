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
