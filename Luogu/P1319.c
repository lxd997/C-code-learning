/*
  P1319 - 压缩技术

  题目：给定一组压缩码，首个数为 N，后续为交替表示连续 0 与 1 的个数（从 0 开始）。
  将其还原为 N x N 的点阵并输出（每行不带空格）。

  实现：读入所有整数到数组中，N = a[0]，随后按顺序遍历每个计数，交替写入 '0' 和 '1' 到矩阵（行优先）。
*/
/*
  P1319 压缩技术

  说明：程序从一行输入读取压缩码（空格分隔），第一个数字为 N，
  随后的数字交替表示连续的 0 和 1 的个数（第一个表示 0 的个数）。
  本实现使用 fgets 读取一整行并解析整数，这样在交互式终端
  中输入一行并按回车就会立即处理并输出矩阵（无需发送 EOF）。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buf[1<<14];
    if (!fgets(buf, sizeof(buf), stdin)) return 0; // 读取单行输入

    int vals[100000];
    int vcnt = 0;

    // 解析整行中的整数（兼容多个空格和制表符）
    char *p = buf;
    char *tok;
    const char *delim = " \t\r\n";
    tok = strtok(p, delim);
    while (tok) {
        vals[vcnt++] = atoi(tok);
        tok = strtok(NULL, delim);
    }

    if (vcnt == 0) return 0;

    int N = vals[0];
    // 创建并填充矩阵
    char **grid = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; ++i) {
        grid[i] = (char*)malloc(N+1);
        grid[i][N] = '\0';
    }

    int total = N * N;
    int pos = 0; // 已填充的格子数
    char cur = '0'; // 首个计数表示 0 的个数

    for (int i = 1; i < vcnt && pos < total; ++i) {
        int cnt = vals[i];
        for (int t = 0; t < cnt && pos < total; ++t) {
            int r = pos / N;
            int c = pos % N;
            grid[r][c] = cur;
            ++pos;
        }
        // 切换 0/1
        cur = (cur == '0') ? '1' : '0';
    }

    // 输出矩阵
    for (int i = 0; i < N; ++i) {
        printf("%s\n", grid[i]);
        free(grid[i]);
    }
    free(grid);
    return 0;
}
