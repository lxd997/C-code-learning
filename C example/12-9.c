/*从键盘输入文件名，输入字符串写入文件，并输出字符串，字符串以“#”结束*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;   /*定义文件指针*/
    char ch,filename[20];
    scanf("%s",filename);   /*获取文件名存入字符数组*/
    if((fp=fopen("filename","w"))==NULL)
    {
        printf("Cannot open file\n");
        exit(0);    /*终止程序*/
    }
    ch=getchar();   /*接收输入的第一个字符*/
    while(ch!='#')
    {
        fputc(ch,fp);
        putchar(ch);
        ch=getchar();
    }
    printf("\n");   /*向屏幕输出一个换行符*/
    fclose(fp);
}