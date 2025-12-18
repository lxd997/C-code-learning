#include<stdio.h>
int main()
{
    float r,l,s;
    printf("请输入半径：\n");
    scanf("%f",&r);
    l=2*3.14159*r;
    s=3.14159*r*r;
    printf("r=%f,l=%f,s=%f\n",r,l,s);
    return 0;
}