/*example 5_7.c 求一元二次方程的根*/
#include <math.h>
#include <stdio.h>
void main()
{
    float a,b,c;
    double s,x1,x2;
    printf("please input a,b,c:\n");
    scanf("%f%f%f",&a,&b,&c);
    if (a>=-(1e-6)&&a<=(1e-6))
        printf ("Sorry! You have a wrong number a.\n");
    else
    {
        s=b*b-4*a*c;
        if(s>(1e-6))
        {
            /*计算两不相等实根*/
            x1=(-b+sqrt(s))/(2*a);
            x2=(-b-sqrt(s))/(2*a);
            printf ("There are two different real:\nx1=%5.2f,x2=%5.2f\n",x1,x2);
        }
        else
            if(s>=-(1e-6)&&s<=(1e-6))
            {
                /*计算两相等实根*/
                x1=x2=-b/(2*a);
                printf("There are two equal real:\nx1=x2=%5.2f\n",x1);

            }
            else
            {
                /*计算两不相等共轭复数*/
                s=-s;
                x1=-b/(2*a);
                x2=fabs(sqrt(s)/(2*a));
                printf("There are two different complex:\n");
                printf ("x1=%5.2f+%5.2fi,x2=%5.2f-%5.2fi\n",x1,x2,x1,x2);
            }
    } 
    
}