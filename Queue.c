#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
typedef struct node* Queue;
Queue front=0;
Queue rear=0;
void main()
{
	Queue tmp,ex;
	tmp=rear;
	int page[20],pageCount,fsize,frame[10],i,j,k,avl,fCount=0;
	printf("enter the Frame size");	
	scanf("%d",&fsize);
	printf("enter the no of pages");
	scanf("%d",&pageCount);			
	for(i=0;i<pageCount;i++)
	{
		printf("enter the page number");
		scanf("%d",&page[i]);			
	}
	for(j=0;j<fsize;j++)
	{
		tmp->data=-1;
		tmp=tmp->next;
	}
	j=0;	
	printf("\n ref\t\tframes\t\t\tFault\n");
	for(i=0;i<pageCount;i++)			
	{
		printf("%d \t\t",page[i]);		
		avl=0;
		for(k=0;k<fsize;k++)	
		{			
		if(tmp->data==page[i])		
			tmp=tmp->next;
		}
		{
			avl=1;
			for(k=0;k<pageCount;k++)
				printf("%d \t",frame[k]);
				printf("H");
		}
		if(avl==0)								
		{
			dequeue();
			frame->next=page[i];
			j=(j+1)%fsize;					
			fCount++;							
			for(k=0;k<pageCount;k++)
			{
				printf("%d \t",tmp->data);
			}
				printf("F"); 
		}
		printf("\n");
	}
	printf("Fault is ; %d",fCount);
}
void enqueue(int x)
{
	Queue newnode;
	newnode=(Queue)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=0;
	if(front==0 && rear==0)
	{
		front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue()
{
	Queue temp;
	temp=front;
		if(front==0 && rear==0)
			printf("empty");
		else
		{	
			printf("%d",front->data);
			front=front->next;
			free(temp);
		}
}