/*以自定义函数方式实现字符串格式读写test5.dat文件*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void wr_string(char *,FILE *);
void rd_string(char *,FILE *);
void main()
{
    char str[20];
    FILE *fp;
    if((fp=fopen("D:\\FILE\\test5.dat","w+"))==NULL)
    {
        printf("Cannot  open file, press any key to exit!");
        getch();    /*按任意键返回*/
        exit(-1);
    }
    wr_string(str,fp);
    rewind(fp);
    rd_string(str,fp);
    fclose(fp);
}
void rd_string(char *str,FILE *fp)  /*字符串读函数，将读取的内容输出到屏幕*/
{
    fgets(str,11,fp);
    printf("\n%s\n",str);
}
void wr_string(char *str,FILE *fp)  /*字符串写函数，将输入的内容写入文件*/
{
    printf("input a string:\n");
    scanf("%s",str);
    fputs(str,fp);
}