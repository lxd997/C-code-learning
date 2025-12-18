/*
  P1320 压缩技术（续集版）

  读取一个 N x N 的 01 点阵（每行不带空格），输出压缩码：
  首个数字为 N，其后交替表示 0 和 1 的连续个数（从 0 开始计数）。

  处理细节：程序从 stdin 读取若干行（直到 EOF），忽略空行；
  第一行的长度决定 N，随后共有 N 行（若输入行数不等于 N 也按读取的行数处理）。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[1024];
    char grid[205][205];
    int n = 0;
    int N = 0;

    while (fgets(line, sizeof(line), stdin)) {
        // 去掉末尾换行和回车
        int L = strlen(line);
        while (L > 0 && (line[L-1] == '\n' || line[L-1] == '\r')) { line[--L] = '\0'; }
        if (L == 0) continue; // 忽略空行
        if (n == 0) {
            N = L;
            if (N > 200) N = 200;
        }
        // 只拷贝最多 N 字符
        int copylen = (L < N) ? L : N;
        for (int i = 0; i < copylen; ++i) grid[n][i] = line[i];
        // 如果行短，则用 '0' 填充（但通常不会出现）
        for (int i = copylen; i < N; ++i) grid[n][i] = '0';
        grid[n][N] = '\0';
        n++;
        if (n >= N) break; // 已读够 N 行可以停止
    }

    // 如果没有读取到任何行，直接退出
    if (n == 0) return 0;

    // 若读到的行数少于 N，使用已有的 n 作为 N
    if (n < N) N = n;

    // 输出：首个数为 N
    printf("%d", N);

    int total = N * N;
    int pos = 0;
    int bit = 0; // 0 表示当前计数的是 '0'
    int curcnt = 0;
    while (pos < total) {
        int r = pos / N;
        int c = pos % N;
        char ch = grid[r][c];
        int val = (ch == '1') ? 1 : 0;
        if (val == bit) {
            curcnt++;
        } else {
            // 输出当前计数
            printf(" %d", curcnt);
            curcnt = 1; // start new count for the other bit
            bit ^= 1;
        }
        pos++;
    }
    // 输出最后一段计数
    printf(" %d\n", curcnt);

    return 0;
}
