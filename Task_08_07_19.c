/* Question : Given n process with their burst times and arrival time .
	      Implement FCFS to find average waiting time and average turn arround time 
	      also show waiting and turn around time for each 
*/

#include<stdio.h>

// Structure of Process 

struct Process
{
	int pid; 
	int Arrival_Time;
	int Burst_Time;
};

// Create the FCFS algorithms
// Turn Arround Time = Completion Time - Arrival Time
// Waiting Time = Turn Arround Time - Burst Time

void create_Gantt_Chart(struct Process process[], int n)
{
	int CT[n],TT[n],WT[n];
	int ct = 0, tt = 0, wt = 0, tt1 = 0;
	
	for(int i = 0; i < n; i++)
		CT[i] = TT[i] = WT[i] = 0;

	for(int i = 0; i < n; i++)
	{
		CT[i] = ct + process[i].Burst_Time;
		ct = ct + process[i].Burst_Time;

		TT[i] =  ct - process[i].Arrival_Time;
		tt = ct - process[i].Arrival_Time;
		tt1 += TT[i];		

		WT[i] += tt - process[i].Burst_Time;
		wt += WT[i]; 
	}
	
	printf("\n\nProcess Id\tArrival Time\tBurst Time\t Completion Time\t Turn Arround Time\t Waiting Time\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d\t\t%d\t\t  %d\t\t\t %d\t\t\t%d\t\t\t%d\n",process[i].pid,process[i].Arrival_Time,process[i].Burst_Time,CT[i],TT[i],WT[i]);
	}
	
	
	printf("\n\nAvrage Wating Time = %d\n", wt/n);
	printf("Avrage turn around Time = %d\n", tt1/n);
}


int main()
{
	int n;
	printf("Enter the how many process\n");
	scanf("%d",&n);

	struct Process proces[n];

	for(int i = 0; i < n; i++)
	{
		printf("Enter process id, Arrival Time and Burst Time\n");
		scanf("%d%d%d",&proces[i].pid,&proces[i].Arrival_Time,&proces[i].Burst_Time);
	}

	printf("\n\nprocess id\tArrival Time\tBurst Time\n");

	for(int i = 0; i < n; i++)
                printf("%d\t\t%d\t\t%d\n",proces[i].pid, proces[i].Arrival_Time, proces[i].Burst_Time);

	create_Gantt_Chart(proces, n);
	return 0;
}
