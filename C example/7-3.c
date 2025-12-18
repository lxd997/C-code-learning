#include"stdio.h"
void main()
{
    int i,a[10],max;
    float sum=0,average;
    printf("Input 10 integer data:\n");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    max=a[0];
    sum=0;
    for(i=0;i<10;i++)
    {
        if(max<a[i]) max=a[i];
        sum+=a[i];
    }
    average=sum/10.0;
    printf("max=%d,average=%f\n",max,average);
}