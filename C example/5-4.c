/*example5_4a.c 规则嵌套计算阶跃函数y的值*/
#include<stdio.h>
void main()
{
    float x,y;
    printf ("please input x:\n");
    scanf("%f",&x);
    y=0;
    if(x>=0)
    {
        if(x>0)
        y=1;
    }
    else 
        y=-1;
    printf("y=%-4.0f\n",y);
}