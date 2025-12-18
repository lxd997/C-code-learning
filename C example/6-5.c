#include "stdio.h"
void main()
{
    int n,i;
    long fact=1,sum=0;
    printf("请输入阶乘求和的正整数：");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
        sum=sum+fact;
    }
    printf("计算结果为:1!+2!+...%d!=%ld\n",n,sum);
}