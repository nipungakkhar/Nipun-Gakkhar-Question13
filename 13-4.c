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
