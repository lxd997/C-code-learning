/*从一个文件中读取字符串，写入另一个文件*/
#include<stdio.h>
void main()
{
    FILE *in, *out;
    char a[10];
    in=fopen("D:\\FILE\\1.txt","r");
    out=fopen("D:\\FILE\\2.txt","w");
    fgets(a,5,in);
    fputs(a,out);
    fclose(in);
    fclose(out);
}