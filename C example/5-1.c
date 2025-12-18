#include <stdio.h>
void main()
{
    int n;
    printf("Please enter a number:");
    scanf("%d",&n);
    if(n<0)
      n=-n;
    printf("The result is :%d.\n",n);
}