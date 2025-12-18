#include <stdio.h>
void main()
{
    int max(int a,int b);/*函数声明*/
    int x=20,y=40,z;
    z=max(x,y);          /*函数调用*/
    printf("max=%d\n",z);
}
int max(int a,int b)     /*函数定义*/
{
    int c;
    if (a>b) c=a;
    else c=b;
    return (c);
}