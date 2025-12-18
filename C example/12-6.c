#include<stdio.h>   // 标准输入输出库
#include<conio.h>   // 控制台输入输出（用于 getch()）
#include<stdlib.h>  // 标准库（用于 exit()）

// 定义结构体 struct stu，用于存储学生信息
struct stu
{
    char name[10];   // 学生姓名，最多 9 个字符（第 10 个存 `\0`）
    int num;         // 学号
    int age;         // 年龄
    char addr[15];   // 地址，最多 14 个字符（第 15 个存 `\0`）
} boya[2], boyb[2], *p, *q;  // 定义两个数组存储学生信息，并定义指针

void main()
{
    FILE *fp;     // 定义文件指针
    char ch;      // 备用字符变量（未使用）
    int i;
    p = boya;     // 指针 `p` 指向 `boya`（用于写入）
    q = boyb;     // 指针 `q` 指向 `boyb`（用于读取）

    // 以二进制可读写模式 "wb+" 打开 `stu` 文件
    if ((fp = fopen("D:\\FILE\\stu", "wb+")) == NULL)
    {
        printf("Cannot open file, press any key to exit!");
        getch();    // 等待用户按键
        exit(-1);   // 退出程序，返回错误码 -1
    }

    printf("\ninput data\n");  // 提示用户输入
    for (i = 0; i < 2; i++, p++)  
        scanf("%s%d%d%s", p->name, &p->num, &p->age, p->addr);
    // 依次输入 name（字符串）、num（整数）、age（整数）、addr（字符串）

    p = boya;  // 复位指针 `p`，让它重新指向 `boya[0]`
    fwrite(p, sizeof(struct stu), 2, fp);  // 把 `boya` 中的两个学生数据写入文件

    rewind(fp);  // 文件指针重新指向文件开头
    fread(q, sizeof(struct stu), 2, fp);   // 从文件读取两个 `struct stu` 存入 `boyb`

    // 输出数据
    printf("\n\nname\tnumber    age    addr\n");
    for (i = 0; i < 2; i++, q++)
        printf("%s\t%5d%7d\t%s\n", q->name, q->num, q->age, q->addr);

    fclose(fp);  // 关闭文件
}
