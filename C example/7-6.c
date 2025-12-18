/*选择排序*/
#include "stdio.h"
#define N 10
void main()
{
    int a[N],i,j,t,p;
    printf ("Input 10 numbers:\n");
    for (i=0;i<N;i++)
        scanf("%d",&a[i]);
    for (i = 0; i < N-1; i++)
    {
        /* code */
        p=i;
        for (j = i+1; j < N; j++)
            if(a[j]<a[p]) p=j;
            if(p!=i)
            {
                t=a[i];
                a[i]=a[p];
                a[p]=t;
            }
        printf("第%d次排序的结果:\n",i+1);
        for (j = 0; j < N; j++)
            printf("%d ",a[j]);
        printf("\n");
        }
    printf("The sorted numbers:\n");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
}