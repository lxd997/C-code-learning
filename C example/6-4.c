#include <stdio.h>
#include <math.h>
void main()
{
    int n;
    float m,t,pi;
    pi=0;n=1;m=1.0;t=1.0;
    do
    {
        pi=pi+t;
        n=n+2;
        m=-m;
        t=m/n;
        /* code */
    } while (fabs(t)>=1e-6);
    pi=pi*4;
    printf("圆周率pi=%10.6f\n",pi);
    
}