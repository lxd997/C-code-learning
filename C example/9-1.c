#include <stdio.h>
#define PI 3.14159
void main()
{
    double r1,r2;
    double s1,s2,s;
    printf("请输入半径r1、r2的值: ");
    scanf("%lf,%lf",&r1,&r2);
    s1=r1*r1*PI;
    s2=r2*r2*PI;
    s=s2-s1;
    printf("area=%lf\n",s);
}