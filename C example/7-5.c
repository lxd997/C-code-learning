/*冒泡排序*/
#include "stdio.h"
#define N 10
void main()
{
    int a[N],i,j,t;
    printf("Input 10 numbers:\n");
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(j=0;j<N-1;j++)
        for(i=0;i<N-1-j;i++)
            if(a[i]>a[i+1])
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
    printf("The sorted numbers:\n");
    for(i=0;i<N;i++)
    printf("%d ",a[i]);
    printf("\n");
}