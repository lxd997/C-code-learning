#include<stdio.h>   // 标准输入输出库，用于输入输出操作
#include<conio.h>   // 控制台输入输出（用于 getch()，等待用户按键）
#include<stdlib.h>  // 标准库（用于 exit()，退出程序）

// 定义一个结构体 stu，表示学生信息
struct stu
{
    char name[10];  // 学生姓名，最多 10 个字符
    int num;        // 学生学号
}boya[2], boyb[2], *p, *q;  // boya 和 boyb 是存储学生数据的数组，p 和 q 是结构体指针

void main()
{
    FILE *fp;  // 文件指针，用于操作文件
    char ch;    // 用于存储字符输入
    int i;      // 循环计数器

    p = boya;   // 指针 p 指向 boya 数组的起始位置
    q = boyb;   // 指针 q 指向 boyb 数组的起始位置

    // 打开文件 "D:\\FILE\\stu"，以读写二进制方式打开，如果打开失败则退出
    if ((fp = fopen("D:\\FILE\\stu", "wb+")) == NULL)
    {
        printf("Cannot open file, press any key to exit!");  // 打印错误信息
        getch();    // 等待用户按下任意键
        exit(-1);   // 退出程序，返回错误码 -1
    }

    // 输入学生数据，将数据存储到 boya 数组中
    for(i = 0; i < 2; i++, p++)
    {
        printf("\ninput data\n");  // 提示用户输入数据
        scanf("%s%d", p->name, &p->num);  // 输入学生姓名和学号
    }

    p = boya;  // 重置指针 p，指向 boya 数组的起始位置

    // 将学生数据写入文件
    for(i = 0; i < 2; i++, p++)
        fprintf(fp, "%s %d\n", p->name, p->num);  // 将每个学生的姓名和学号写入文件

    rewind(fp);  // 重定位文件指针到文件开始位置

    // 从文件中读取学生数据，存储到 boyb 数组中
    for(i = 0; i < 2; i++, q++)
        fscanf(fp, "%s %d\n", q->name, &q->num);  // 读取学生姓名和学号

    printf("\n\nname\tnumber\n");  // 输出表头

    q = boyb;  // 重置指针 q，指向 boyb 数组的起始位置

    // 输出读取到的学生信息
    for(i = 0; i < 2; i++, q++)
        printf("%s\t%d\t\n", q->name, q->num);  // 格式化输出每个学生的姓名和学号

    fclose(fp);  // 关闭文件
}
/*与【例12-6】相比，本程序中fscanf和fprintf函数每次只能读写一个结构数组的元素，
因此采用了循环语句来读写全部数组元素。还要注意指针变量p和q，循环改变了它们的值，
因此程序在循环后分别对它们重新赋予了数组的首地址*/