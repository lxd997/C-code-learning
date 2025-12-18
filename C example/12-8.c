/*本程序用随机读出的方法读出第2个学生的数据*/
#include<stdio.h>   // 标准输入输出库，用于输入输出操作
#include<conio.h>   // 控制台输入输出（用于 getch()，等待用户按键）
#include<stdlib.h>  // 标准库（用于 exit()，退出程序）

// 定义一个结构体 stu，表示学生信息
struct stu
{
    char name[10];  // 学生姓名，最多 10 个字符
    int num;        // 学生学号
    int age;
    char addr[15];
}boy,*q;
void main()
{
    FILE *fp;
    char ch;
    int i=1;
    q=&boy;
    if ((fp = fopen("D:\\FILE\\stu", "rb")) == NULL)
    {
        printf("Cannot open file, press any key to exit!");  // 打印错误信息
        getch();    // 等待用户按下任意键
        exit(-1);   // 退出程序，返回错误码 -1
    }
    fseek(fp,i*sizeof(struct stu),0);
    fread(q,sizeof(struct stu),1,fp);
    printf("\n\nname\tnumber\tage\taddr\n");
    printf("%s\t%d\t%d\t%s\n",q->name,q->num,q->age,q->addr);
    fclose(fp);
}