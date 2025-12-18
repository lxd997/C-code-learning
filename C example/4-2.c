#include <stdio.h>
int main()
{
    int a=123;
    long b=123456;
    printf("a=%d,a=%5d,a=%-5d,a=%2d\n",a,a,a,a);
    printf("b=%ld,b=%8ld,b=%5ld\n",b,b,b);
    return 0;
}