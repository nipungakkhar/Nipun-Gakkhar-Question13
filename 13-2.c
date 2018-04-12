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
