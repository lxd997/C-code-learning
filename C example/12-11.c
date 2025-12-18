/*从键盘输入4个学生的有关数据，把它们转存*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 4
struct student
{
    char name[10];
    int num;
    int age;
    char addr[15];
} stud[SIZE];   /*定义学生结构体*/
void save()     /*自定义文件保存函数，将数据写入文件*/
{
    FILE *fp;
    int i;
    if((fp=fopen("D:\\FILE\\stulist","wb"))==NULL)
    {
        printf("Cannot open file\n");
        exit(0);    /*终止程序*/
    }
    for(i=0;i<SIZE;i++)     /*二进制写*/
        if(fwrite(&stud[i],sizeof(struct student),1,fp)!=1)
            printf("file write error\n");       /*处理出错*/
        fclose(fp);     /*关闭文件*/
}
void main()
{
    int i;
    for(i=0;i<SIZE;i++)     /*从键盘读入学生信息*/
        scanf("%s%d%d%s",stud[i].name,&stud[i].num,&stud[i].age,stud[i].addr);
    save();         /*调用save函数保存学生信息*/
}