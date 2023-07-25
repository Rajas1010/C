#include<stdio.h>
void main()
{
	int page[20],pageCount,fsize,frame[10],i,j,k,avl,fCount=0;
	printf("enter the Frame size");		//3
	scanf("%d",&fsize);
	printf("enter the no of pages");
	scanf("%d",&pageCount);				//6
	for(i=0;i<pageCount;i++)
	{
		printf("enter the page number");
		scanf("%d",&page[i]);					//1 1 6 4 5 6 
	}
	for(j=0;j<fsize;j++)
	{
		frame[j]=-1;
	}
	j=0;
	printf("\n ref\t\tframes\t\t\tFault\n");
	for(i=0;i<pageCount;i++)			//1
	{
		printf("%d \t\t",page[i]);		//1	1
		avl=0;
		for(k=0;k<fsize;k++)			//3
		if(frame[k]==page[i])		//-1 !=1  _  1 =1
		{
			avl=1;
			for(k=0;k<pageCount;k++)
				printf("%d \t",frame[k]); //1 -1 -1
				printf("H");
		}
		if(avl==0)								//
		{
			frame[j]=page[i];				//-1 replace 1
			j=(j+1)%fsize;					// j=1
			fCount++;							//1
			for(k=0;k<pageCount;k++)//
				printf("%d \t",frame[k]); //print 1 -1 -1
				printf("F"); //f
		}
		printf("\n");
	}
	printf("Fault is ; %d",fCount);
}