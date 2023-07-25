Page Replacement Algorithm


FIFO

#include <stdio.h>
 int main()
 {
 int i,j,l,rs[50],frame[10],nf,k,avail,count=0;
 printf("Enter length of ref. string : ");
 scanf("%d", &l);
 printf("Enter reference string :\n");
 for(i=1; i<=l; i++)
 scanf("%d", &rs[i]);
 printf("Enter number of frames : ");
 scanf("%d", &nf);
 for(i=0; i<nf; i++)
 frame[i] = -1;   j = 0;
 printf("\nRef. str  Page frames");
 for(i=1; i<=l; i++)
 {
  printf("\n%4d\t", rs[i]);
  avail = 0;
  for(k=0; k<nf; k++)
  if(frame[k] == rs[i])
  avail = 1;
  if(avail == 0)
  {
   frame[j] = rs[i];
   j = (j+1) % nf;
   count++;
   for(k=0; k<nf; k++)
    printf("%4d", frame[k]);
  }
 }
 printf("\n\nTotal no. of page faults : %d\n",count);
}


OPTIMAL

#include<stdio.h>
 int fr[3], n, m; void display();
 void main()
{ int i,j,page[20],fs[10];
int
max,found=0,lg[3],index,k,l,flag1=0,flag2=0,pf=0;
printf("Enter length of the reference string:   ");
 scanf("%d",&n);
printf("Enter the reference string: ");
for(i=0;i<n;i++)
  scanf("%d",&page[i]);
  printf("Enter no of frames: ");
scanf("%d",&m);
 for(i=0;i<m;i++)
 fr[i]=-1; pf=m;
 for(j=0;j<n;j++)
{
        flag1=0;        flag2=0;
for(i=0;i<m;i++)
 { if(fr[i]==page[j])
 { flag1=1; flag2=1; break; } }
 if(flag1==0)
 { for(i=0;i<m;i++)
 { if(fr[i]==-1)
 { fr[i]=page[j];
 flag2=1;
 break;
}
} }
 if(flag2==0)
 { for(i=0;i<m;i++)
 lg[i]=0;
 for(i=0;i<m;i++)
 { for(k=j+1;k<=n;k++)
{ if(fr[i]==page[k])
 { lg[i]=k-j; break; }
}
 } found=0;
 for(i=0;i<m;i++)
 { if(lg[i]==0)
 { index=i;  found = 1;
break; }
}
if(found==0)
{
max=lg[0];
        index=0;
        for(i=0;i<m;i++)
        { if(max<lg[i])
{ max=lg[i];
 index=i; }
} }
fr[index]=page[j];
 pf++; }
 display();
}
printf("Number of page faults : %d\n", pf);
} void display()
{ int i; for(i=0;i<m;i++)
 printf("%d\t",fr[i]);
 printf("\n");
}



LRU


#include <stdio.h>
int arrmin(int[], int);
int main()
 {
 int i,j,len,rs[50],frame[10],nf,k,avail,count=0;   int access[10], freq=0, dm;
 printf("Length of Reference string : ");
 scanf("%d", &len);
 printf("Enter reference string :\n");
 for(i=1; i<=len; i++)
 scanf("%d", &rs[i]);
 printf("Enter no. of frames : ");
 scanf("%d", &nf);
 for(i=0; i<nf; i++)
 frame[i] = -1;
 j = 0;
 printf("\nRef. str  Page frames");
 for(i=1; i<=len; i++)
 {
  printf("\n%d\t", rs[i]);
  avail = 0;
  for(k=0; k<nf; k++)
  {
   if(frame[k] == rs[i])
   {
    avail = 1;
    access[k] = ++freq;
    break;
   }
  }
  if(avail == 0)
  {
   dm = 0;
   for(k=0; k<nf; k++)
   {
    if(frame[k] == -1)
    dm = 1;
        break;
 }
   if(dm == 1)
   {
    frame[k] = rs[i];
    access[k] = ++freq;
    count++;
   }
   else
   {
    j = arrmin(access, nf);
        frame[j] = rs[i];
    access[j] = ++freq;
        count++;
   }
   for(k=0; k<nf; k++)
    printf("%d", frame[k]);
  }
 }
 printf("\n\nTotal no. of page faults : %d\n", count);
}
int arrmin(int a[], int n)
{
 int i, min = a[0];
 for(i=1; i<n; i++)
 if (min > a[i])
 min = a[i];
 for(i=0; i<n; i++)
 if (min == a[i])
   return i;
}   