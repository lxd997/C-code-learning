#include <stdio.h>
void main()
{
    char c;
    printf("请输入一个字符：");
    scanf("%c",&c);
    if(c>='a'&&c<='z'||c>='A'&&c<='Z')
       printf("YES\n");
    else
       printf("NO!\n");
}