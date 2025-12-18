/*关键点：指针传递的原理，在 C 语言中，函数的参数是通过 值传递 传递的，
指针也是值传递。这意味着，传递给函数的只是指针的副本，而不是指针本身。*/
#include <stdio.h>
void main()
{
    void swap(int *p1,int *p2);
    int a,b;
    int *pointer_1,*pointer_2;
    scanf("%d,%d",&a,&b);
    pointer_1=&a;pointer_2=&b;
    if(a<b) swap(pointer_1,pointer_2);
    printf("\n%d,%d\n",*pointer_1,*pointer_2);
}
void swap(int *p1,int *p2)
{
    int *temp;
    temp=p1;
    p1=p2;
    p2=temp;
}
