/* FCFS Disk Scheduling Implementation */ 
#include <stdio.h> 
#include <stdlib.h> 
int main()
{
	int queue[100], q_size, head, seek =0, diff;
	printf("%s\n", "***FCFS Disk Scheduling Algorithm***"); 
	printf("%s\n", "Enter the size of the queue"); 
	scanf("%d", &q_size); 
	printf("%s\n", "Enter queue elements"); 
	for(int i=1; i<=q_size; i++)
	{ 
		scanf("%d",&queue[i]);
	} 
	printf("%s\n","Enter initial head position"); 
	scanf("%d", &head); 
	queue[0]=head; 
	for(int j=0; j<=q_size-1; j++)
	{ 
		diff = abs(queue[j]-queue[j+1]);
		seek += diff; 
		printf("Move from %d to %d with Seek %d\n",queue[j],queue[j+1],diff);
	} 
	printf("\nTotal seek time is %d\t",seek); 
	return 0;
    }