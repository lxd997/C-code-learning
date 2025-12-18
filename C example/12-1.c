#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    char ch;
    if((fp=fopen("D:\\FILE\\test1.txt","r++"))==NULL)
    {
        printf("\nCannot open file,press any key to exit!");
        exit(-1);
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        putchar(ch);
        ch=fgetc(fp);
    }
    fclose(fp);
}