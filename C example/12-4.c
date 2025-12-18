#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    char ch,st[20];
    if((fp=fopen("D:\\FILE\\test4.dat","a+"))==NULL)
    {
        printf("\nCannot  open file, press any key to exit!");
        getch();    /*按任意键返回*/
        exit(-1);
    }
    printf("input a string:\n");
    scanf("%s",st);
    fputs(st,fp);
    rewind(fp);
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        putchar(ch);
        ch=fgetc(fp);
    }
    printf("\n");
    fclose(fp);
}