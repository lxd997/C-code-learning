#include <stdio.h>
void main()
{
    char ch;
    ch=getchar();
    if(ch=='+')
    printf("plus\n");
    else if(ch=='-')
    printf("minus\n");
    else if(ch=='*')
    printf("multiply\n");
    else if(ch=='/')
    printf("divide\n");
    else
    printf("sorry\n");
}