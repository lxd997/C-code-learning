#include <stdio.h>
void main()
{
    int letter=0,data=0,space=0,others=0;
    char c;
    printf("请输入一行字符，以回车键结束：");
    //使用getchar()输入字符，并赋值给c;
    while ((c=getchar())!='\n')
    {
        if(c>='A'&&c<='Z'||c>='a'&&c<='z')
        letter++;
        else if(c>='0'&&c<='9')
        data++;
        else if(c==' ')
        space++;
        else
        others++;
    }
    printf("letter=%d,data=%d,space=%d,others=%d\n",letter,data,space,others);
}