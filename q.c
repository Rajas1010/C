#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
typedef struct node* list;
list front=0;
list rear=0;
void enqueue(int x)
{
	list newnode;
	newnode=(list)malloc(sizeof(struct node));
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
	list temp;
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
void display()
{
	list temp;
	if(front==0 && rear==0)
			printf("empty");
	else
	{
		temp=front;
		while(temp !=0)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
void main()
{
	int x,y,z;
	
	printf("enter the limit");
	scanf("%d",&y);
	while(y!=0)
	{
	printf("enter the value");
	scanf("%d",&x);
	enqueue(x);
	y--;
	}
	display();
	while(1){
	printf("if delete press 0");
	scanf("%d",&z);
	if(z==0)
		dequeue();
	else 
		if(z==1)
		display();
	else
		break;
	}
	
	
}