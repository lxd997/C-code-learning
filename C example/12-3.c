#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    char str[20];
    if((fp=fopen("D:\\FILE\\test3.dat","r+"))==NULL)
    {
        printf("\nCannot  open file, press any key to exit!");
        getch();    /*按任意键返回*/
        exit(-1);
    }
    fgets(str,11,fp);   /*读取10个有效字符，末尾添加结束符'\0' */
    printf("\n%s\n",str);
    fclose(fp);
}