/*
 * P5733.c
 * 题目：将输入的字符串全部转换为大写并输出
 * 说明：程序读取一个不含空白的字符串（最多104个字符），使用 toupper 将每个字符转换为大写后输出。
 * 注意：对 toupper 的使用要注意传入参数的类型（见下方讲解）。
 */

#include <stdio.h>
#include <ctype.h> /* 提供 toupper、tolower 等字符分类/转换函数的声明 */

int main(void) {
    char s[105]; /* 预留 104 字符 + 终止 '\0' */

    /* 使用 scanf 读取不含空白的字符串；限定最大读取长度以避免缓冲区溢出 */
    if (scanf("%104s", s) != 1) return 0;

    /* 遍历字符串，将每个字符转换为大写并写回 */
    for (int i = 0; s[i]; ++i) {
        /*
         * toupper 的原型是：int toupper(int c);
         * - 参数 c 的有效取值是 EOF 或能表示为 unsigned char 的值。
         * - 为了避免当 char 为 signed 并且有负值时出现未定义行为，先把 s[i] 强制转换为 (unsigned char)。
         * - toupper 返回的是 int（要么为对应的大写字符的 unsigned char 值，要么原始字符或其他值），
         *   因此赋回到 s[i] 时再强制转换为 (char)。
         */
        s[i] = (char)toupper((unsigned char)s[i]);
    }

    printf("%s\n", s);
    return 0;
}
