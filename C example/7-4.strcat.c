#include "stdio.h"
#include "string.h"
void main()
{
    char s11[40]="university",s22[20]="qingdao";
    printf("连接函数的结果:");
    puts(strcat(s11,s22));
}