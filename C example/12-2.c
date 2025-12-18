#include<stdio.h>   // 标准输入输出头文件
#include<conio.h>   // 控制台输入输出（用于 getch()）
#include<stdlib.h>  // 标准库（用于 exit()）

void main()  // 主函数
{
    FILE *fp;  // 定义文件指针
    char ch;   // 定义字符变量

    // 以 "w+" 方式打开文件，"w+" 表示可读可写，文件不存在则创建，存在则清空
    if((fp = fopen("D:\\FILE\\test2.txt", "w+")) == NULL)    
    {
        printf("Cannot open file, press any key to exit!");  // 打开失败，提示信息
        getch();  // 等待用户按键
        exit(-1); // 退出程序，返回错误码 -1
    }

    printf("input a string:\n");  // 提示用户输入字符串
    ch = getchar();  // 读取一个字符
    while (ch != '\n')  // 直到遇到换行符结束
    {
        fputc(ch, fp);  // 将字符写入文件
        ch = getchar();  // 继续读取下一个字符
    }

    rewind(fp);  // 重新定位文件内部位置指针到文件开头
    ch = fgetc(fp);  // 读取文件中的第一个字符
    while (ch != EOF)  // 直到文件结束 (EOF)
    {
        putchar(ch);  // 输出字符到屏幕
        ch = fgetc(fp);  // 继续读取下一个字符
    }

    printf("\n");  // 输出换行
    fclose(fp);  // 关闭文件
}
