/*
 * P5734.c
 * Luogu P5734 — 文字处理软件（带详细中文注释的实现）
 *
 * 功能简述：
 *  - 读取初始字符串（题目保证不含空白），初始文档第 0 个字符为开头。
 *  - 支持 4 种操作：
 *      1 str   : 在文档尾部插入 str，并把操作结果缓存（稍后统一输出）
 *      2 a b   : 截取文档，只保留从第 a 个字符起连续的 b 个字符（0-based），并缓存结果
 *      3 a str : 在第 a 个字符前插入 str，并缓存结果
 *      4 str   : 查找子串 str 在文档中首次出现的位置（0-based），找不到则输出 -1（缓存结果）
 *
 * 设计说明与实现细节：
 *  - 为了满足“输入都读完后再统一输出”的要求，程序在处理每个操作时将对应结果保存在
 *    outputs 数组（每个操作一条字符串），读取完所有 q 个操作后统一打印所有结果。
 *  - 题目保证 q <= 100，初始字符串和每次操作的 str 长度 <= 100。为了安全，主文档使用
 *    MAXN 较大缓冲区（10005/20005 都足够），并在每次插入时保证不会超出边界。
 *  - 截取使用 memmove，因为源和目标可能有重叠（截取并覆盖到开头）。
 *  - 查找使用标准库函数 strstr，结果位置以 0 为基准输出。
 *  - 所有读字符串的 scanf 都使用长度限制（例如 "%100s"），防止超出目标缓冲区。
 */

#include <stdio.h>
#include <string.h>

#define MAXN 20005 /* 足够容纳多次插入造成的增长 */

int main(void) {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    static char doc[MAXN];
    if (scanf("%100s", doc) != 1) return 0; /* 读取初始文档 */

    /* 保存每个操作的输出，操作数 q <= 100 */
    static char outputs[105][MAXN];
    int outcnt = 0;

    for (int i = 0; i < q; ++i) {
        int op;
        if (scanf("%d", &op) != 1) break;

        if (op == 1) {
            /* 1 str：在文档尾部插入 str 并保存输出 */
            char t[105];
            scanf("%100s", t);
            int len = (int)strlen(doc);
            int add = (int)strlen(t);
            if (len + add >= MAXN) add = MAXN - 1 - len; /* 剩余空间 */
            if (add > 0) strncat(doc, t, add);
            doc[MAXN - 1] = '\0';
            /* 保存当前文档状态，稍后统一输出 */
            strncpy(outputs[outcnt], doc, MAXN - 1);
            outputs[outcnt][MAXN - 1] = '\0';
            outcnt++;

        } else if (op == 2) {
            /* 2 a b：只保留从第 a 个字符起 b 个字符，并输出（0-based） */
            int a, b;
            scanf("%d %d", &a, &b);
            int len = (int)strlen(doc);
            if (a < 0) a = 0;
            if (a > len) a = len;
            if (b < 0) b = 0;
            if (a + b > len) b = len - a;
            if (b < 0) b = 0;
            memmove(doc, doc + a, b);
            doc[b] = '\0';
            /* 保存当前文档状态，稍后统一输出 */
            strncpy(outputs[outcnt], doc, MAXN - 1);
            outputs[outcnt][MAXN - 1] = '\0';
            outcnt++;

        } else if (op == 3) {
            /* 3 a str：在第 a 个字符前插入 str 并输出 */
            int a;
            char t[105];
            scanf("%d %100s", &a, t);
            int len = (int)strlen(doc);
            if (a < 0) a = 0;
            if (a > len) a = len;
            static char tmp[MAXN];
            if (a > 0) memcpy(tmp, doc, a);
            tmp[a] = '\0';
            int add_space = MAXN - 1 - a; /* tmp 已占 a 个 */
            strncat(tmp, t, add_space);
            strncat(tmp, doc + a, MAXN - 1 - (int)strlen(tmp));
            strncpy(doc, tmp, MAXN - 1);
            doc[MAXN - 1] = '\0';
            /* 保存当前文档状态，稍后统一输出 */
            strncpy(outputs[outcnt], doc, MAXN - 1);
            outputs[outcnt][MAXN - 1] = '\0';
            outcnt++;

        } else if (op == 4) {
            /* 4 str：查找子串，输出最先出现的位置（0-based），找不到输出 -1 */
            char t[105];
            scanf("%100s", t);
            char *p = strstr(doc, t);
            if (p) snprintf(outputs[outcnt], MAXN, "%d", (int)(p - doc));
            else strncpy(outputs[outcnt], "-1", MAXN - 1);
            outputs[outcnt][MAXN - 1] = '\0';
            outcnt++;
        }
    }

    /* 所有操作处理完毕，统一输出结果（每个结果一行） */
    for (int i = 0; i < outcnt; ++i) {
        printf("%s\n", outputs[i]);
    }

    return 0;
}
