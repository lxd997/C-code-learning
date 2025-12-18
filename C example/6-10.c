/*计算sin(x)的值，直到最后一项的绝对值小于10的-6次方为止*/
#include "stdio.h"
#include "math.h"
#define PI 3.1415926
void main()
{
    int i=1;
    long n=1,f=1,flag=1;
    double t,sum=0.0,x;
    float angle;
    printf("请输入角度angle的值:");
    scanf("%f",&angle);
    x=PI/180*angle;
    t=x/f;
    while (fabs(t)>=1e-6)
    {
        /* code */
        printf("第%d次循环t的值:",i++);
        printf("t=%lf\n",t);
        sum=sum+t;
        n=n+2;
        flag=-flag;
        f=f*n*(n-1);
        t=flag*pow(x,n)/f;
    }
    printf("计算结果为:sin(%f°)=%lf\n",angle,sum);
}