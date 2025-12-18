/*验证12-11.c的文件中是否有信息，输出到屏幕。*/
#include<stdio.h>
#define SIZE 4
struct student
{
    char name[10];
    int num;
    int age;
    char addr[15];
}s [SIZE];
void main()
{
    int i;
    FILE *fp;
    fp=fopen("D:\\FILE\\stulist","rb");  /*注意文件所在的路径*/
    for(i=0;i<SIZE;i++)
    {
        fread(&s[i],sizeof(struct student),1,fp);
        printf("%-10s%4d%4d%10s\n",s[i].name,s[i].num,s[i].age,s[i].addr);
    }
    fclose(fp);
}