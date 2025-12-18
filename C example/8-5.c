#include <stdio.h>
void main()
{
    int fac(int n);
    int n,f;
    printf("Please enter n: ");
    scanf("%d",&n);
    if(n<=0)
        printf("Sorry,you enter a wrong number! \n");
    else
    {
        f=fac(n);
        printf("%d!=%d\n",n,f);
    }
}
int fac(int n)
{
    int m;
    if(n==0||n==1)
        m=1;
    else
        m=n*fac(n-1);
    return (m);
}