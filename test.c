#include<stdio.h>
#include<stdlib.h>
void main()
{/*
	int *p=(int *)malloc(sizeof(int));
	
	for(int i=0;i<3;i++)
	{
		scanf("%d",p+i);
	}
	for(int i=0;i<3;i++)
	{
		printf("%d ",*(p+i));
	}
	
	*p=40;
	printf("%d",*p);
	printf("\n");
	struct stu{
		char *name;
		int age;
	};
	struct stu s;
	s.name = "Raja";
	s.age=45;
	printf("%s",s.name);
	printf("%d",s.age);
*/
//triple pointer
/*
	int p= 20;
	int *ptr1=&p;
	int **ptr2=&ptr1;
	int ***ptr3=&ptr2;
	printf("%d",***ptr3);
*/

/*
// typedef
	typedef int num;
	num i=10;
	printf("%d",i);
	*/
	
	//Realloc
	/*
	int *p=(int *)malloc(3*sizeof(int));
	*p=(23,45,67);
	for(int i=0;i<3;i++)
	{
		printf("%d ",*p+i);
	}
		p=(int *)realloc(p,5* sizeof(int));
	for(int i=3;i<5;i++)
	{
		scanf("%d",p+i);
		printf("%d ",*(p+i));
	}
*/


}