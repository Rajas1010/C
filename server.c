#include <stdio.h>
int main()
{
	int i=0,j,k,l;
	int a[100];
	char b;
	printf("enter the value ");
	do
	{
	scanf("%d",&a[i++]);
	}
	while (getchar()!='\n' && i<99);
	a[i];
	int min=a[0],max=a[0];
	for (int j=0;j<i;j++)
	{
		if (a[j]>max)
		    max=a[j];
		if(a[j]<min)
			min=a[j]; 
	}
l=min;
	for (j=0;j<max-min;j++)
	{
		b='F';
		for (k=0;k<i;k++)//3
			if(l==a[k])
				b='T';
		if(b=='F')
			printf("%d\t",l);
		l++;
	}
	return 0;
}