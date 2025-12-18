#include <stdio.h>
#include <stdlib.h>

/* 生成并输出 n x n 的“蛇形”方阵（顺时针螺旋填充）
   要求：每个数字占用 3 个字符宽，前面用空格补齐（printf 的 "%3d" 格式）。
   题目保证 n 不大于 9，这里为了健壮性允许最多分配 100 行。
*/
int main() {
    int n;
    /* 读取输入 n（正整数） */
    if (scanf("%d", &n) != 1) return 0;

    /* 简单的范围检查：
       题目实际限制 n <= 9，但为防误用这里限定最大为 100,
       如果 n 非法（<=0 或 >100），直接退出程序（不输出）。
    */
    if (n <= 0 || n > 100) return 0;

    /* 为矩阵分配内存：
       采用 VLA 风格的指针数组形式 int (*mat)[100],
       使用 calloc 分配 n 行、每行占 sizeof *mat 字节（即 100 个 int 的空间）,
       并对返回值进行显式类型转换以兼容不同编译器和编译模式。
       这样可以直接使用 mat[i][j] 访问元素。
    */
    int (*mat)[100] = (int (*)[100])calloc((size_t)n, sizeof *mat);
    if (!mat) return 0; /* 分配失败直接退出 */

    /* 螺旋填充的边界控制变量：
       top, left 指向当前未填充区域的上边界和左边界（初始为 0）;
       bottom, right 指向下边界和右边界（初始为 n-1）。
       cur 用于记录当前要填入的数字，total 为 n*n（填满时结束）。
    */
    int top = 0, left = 0, bottom = n - 1, right = n - 1;
    int cur = 1, total = n * n;

    /* 循环填充矩阵，按照顺时针方向：向右、向下、向左、向上，
       每次完成一条边后收缩对应的边界，直至填满所有数字。
    */
    while (cur <= total) {
        // 向右填（填入 top 行，从 left 到 right）
        for (int j = left; j <= right && cur <= total; j++) mat[top][j] = cur++;
        top++; // 上边界下移（已填完）

        // 向下填（填入 right 列，从 top 到 bottom）
        for (int i = top; i <= bottom && cur <= total; i++) mat[i][right] = cur++;
        right--; // 右边界左移（已填完）

        // 向左填（填入 bottom 行，从 right 到 left）
        for (int j = right; j >= left && cur <= total; j--) mat[bottom][j] = cur++;
        bottom--; // 下边界上移（已填完）

        // 向上填（填入 left 列，从 bottom 到 top）
        for (int i = bottom; i >= top && cur <= total; i--) mat[i][left] = cur++;
        left++; // 左边界右移（已填完）
    }

    /* 输出矩阵：
       每个数字占 3 个字符宽（前导空格补齐），数字之间没有额外分隔。
       每行输出后换行。
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }

    /* 释放分配的内存并返回 */
    free(mat);
    return 0;
}
