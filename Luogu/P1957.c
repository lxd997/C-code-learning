#include <stdio.h> // 标准输入输出头，用于 scanf/printf
#include <string.h> // 字符串操作头（本程序未强依赖，但保留以备扩展）
#include <ctype.h> // 字符分类函数头，用于 isspace/isalpha

int main(void) { // 主函数，程序入口
    int n; // 存放题目数量 i
    if (scanf("%d", &n) != 1) return 0; // 读取题目数量，读取失败则直接退出
    int a = 0, b = 0; // 存放当前题目的两个操作数
    char op = 0; // 存放当前题目的运算类型：'a' 加、'b' 减、'c' 乘
    char line[128]; // 缓冲一行输入的字符数组
    /* consume end of line after the integer */
    fgets(line, sizeof(line), stdin); // 读掉第一行后面的换行，避免后续 fgets 读取到空行

    for (int i = 0; i < n; ++i) { // 遍历每一道题目
        if (!fgets(line, sizeof(line), stdin)) break; // 读取一行输入到 line，失败则退出循环
        /* skip empty lines */
        char *p = line; // 指针 p 用于遍历并跳过行首空白字符
        while (*p && isspace((unsigned char)*p)) ++p; // 跳过空白（空格、制表、回车等）
        if (*p == '\0' || *p == '\n') { --i; continue; } // 如果整行为空则不计入题目，继续读取下一行

        if (isalpha((unsigned char)*p)) { // 如果行首是字母，则本行包含运算类型
            char t; // 临时变量存放读取到的运算类型字符
            int x, y; // 临时变量存放读取到的两个操作数
            if (sscanf(p, "%c %d %d", &t, &x, &y) == 3) { // 按 <char> <int> <int> 格式解析
                op = t; a = x; b = y; // 更新当前运算类型与操作数
            }
        } else { // 否则，本行只有两个数字，运算类型沿用上一题的类型
            int x, y; // 临时变量存放读取到的两个操作数
            if (sscanf(p, "%d %d", &x, &y) == 2) { // 按 <int> <int> 格式解析
                a = x; b = y; // 更新当前操作数
            }
        }

        long long res = 0; // 存放计算结果，使用 long long 防止乘法溢出
        char sym = '?'; // 用于输出的符号：'+','-','*'，初始化为未知
        if (op == 'a') { res = (long long)a + b; sym = '+'; } // 若为 'a'，执行加法并设置符号
        else if (op == 'b') { res = (long long)a - b; sym = '-'; } // 若为 'b'，执行减法并设置符号
        else if (op == 'c') { res = (long long)a * b; sym = '*'; } // 若为 'c'，执行乘法并设置符号

        char out[128]; // 缓冲输出字符串，形如 "a+b=ans"
        int len = snprintf(out, sizeof(out), "%d%c%d=%lld", a, sym, b, res); // 将表达式格式化到 out 中，返回长度
        if (len < 0) len = (int)strlen(out); // 如果 snprintf 返回负数（异常），使用 strlen 作为替代长度

        printf("%s\n%d\n", out, len); // 输出表达式和长度，按题目要求为两行
    } // for 循环结束

    return 0; // 程序正常结束返回 0
} // main 函数结束
