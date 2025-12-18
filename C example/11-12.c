/*例11-12 example 11_12.c 共用体成员的取值*/
#include <stdio.h>
union data
{
    short int i;
    char ch;
    float f;
};
void main()
{
    union data a;
    a.i=10;
    a.ch='t';
    a.f=8.9;
    printf("共用体变量a成员的值为:\n");
    printf("a.i=%hd\ta.ch=%c\ta.f=%5.2f\n",a.i,a.ch,a.f);
}
//从程序结果可以看出，只有成员f具有确定的值，而成员i和ch的值是不可预料的。共用体的各成员共用同一段内存，所以只接受最后一个赋值。