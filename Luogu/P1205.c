/* P1205 Transformations (USACO 1.2)

    该程序读取正方形网格大小 n，随后读取原始图案和目标图案，各为 n 行每行 n 字符。
    然后检查以下 7 种变换中哪一种能把原图变换为目标图：
      1. 顺时针旋转 90 度
      2. 顺时针旋转 180 度
      3. 顺时针旋转 270 度
      4. 水平反射（左右镜像）
      5. 先水平反射再执行 1-3 中任意一种旋转（组合变换）
      6. 保持不变
      7. 无效（上述都不能得到目标图）

    程序实现思路：实现旋转与反射的辅助函数，分别生成变换后的临时网格，
    与目标网格比较，按照题目要求优先选择序号最小的可行变换并输出对应编号。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 将矩阵 a 顺时针旋转 90 度，结果写入 b
// 位置映射：原来 (i,j) -> 新位置 (j, n-1-i)
//
// 说明参数类型：char **a, char **b
// - 在本程序中，每个网格（矩阵）被存储为 char* 的数组（每个元素为一行字符串），
//   因此矩阵的类型是 char**（指向 char* 的指针）。
// - 具体来说：char **a 表示 a 是一个指针，指向若干个 char*（每个 char* 指向一行字符数组），
//   可以把它想象为二维字符数组的动态表示：a[row][col] 就能访问第 row 行第 col 列。
// - 传参时把原矩阵的数组（例如 char** orig）传入，函数直接在 b（另一个 char**）上写入结果。
//
// 小结：char** 用来表示 "行指针数组"，每个元素是一个以 '\0' 结尾的字符串（即一行）。
void rotate90(char **a, char **b, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[j][n-1-i] = a[i][j];
}

// 将矩阵 a 顺时针旋转 180 度，结果写入 b
// 位置映射：原来 (i,j) -> 新位置 (n-1-i, n-1-j)
void rotate180(char **a, char **b, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[n-1-i][n-1-j] = a[i][j];
}

// 将矩阵 a 顺时针旋转 270 度（等同于逆时针 90 度），结果写入 b
// 位置映射：原来 (i,j) -> 新位置 (n-1-j, i)
void rotate270(char **a, char **b, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[n-1-j][i] = a[i][j];
}

// 对矩阵 a 进行水平反射（左右镜像），结果写入 b
// 位置映射：原来 (i,j) -> 新位置 (i, n-1-j)
void reflect(char **a, char **b, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][n-1-j] = a[i][j];
}

// 判断两个 n x n 网格是否完全相等（逐行比较字符串）
// 这里用 strcmp 比较两行字符串是否相同，strcmp 返回 0 表示相等
int equal_grid(char **a, char **b, int n) {
    for (int i = 0; i < n; ++i)
        if (strcmp(a[i], b[i]) != 0) return 0;
    return 1;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char tmp[32];
    // 为各个网格分配内存（原图、目标图、临时网格1、临时网格2）
    // 说明：char **orig 是一个指针数组，orig[i] 每个元素将指向一个长度为 n+1 的 char 数组
    //       （多出一个字节用于存储字符串终止符 '\0'）。
    // malloc(n * sizeof(char*)) 分配了存放 n 个 char* 指针的空间。
    char **orig = malloc(n * sizeof(char*));
    char **target = malloc(n * sizeof(char*));
    char **tmpg = malloc(n * sizeof(char*));
    char **tmpg2 = malloc(n * sizeof(char*));
    for (int i = 0; i < n; ++i) {
        // 每一行分配 n+1 字节，最后一个字符用于 '\0'，使其作为 C 字符串可以被 strcmp/strncpy 等函数使用
        orig[i] = malloc(n+1);
        target[i] = malloc(n+1);
        tmpg[i] = malloc(n+1);
        tmpg2[i] = malloc(n+1);
    }

    // 读取原始图案
    for (int i = 0; i < n; ++i) {
        // scanf("%s", tmp) 从输入读取一行（至第一个空白），tmp 是临时缓冲
        // strncpy(orig[i], tmp, n) 将读取到的字符串复制到 orig[i]（最多复制 n 个字符）
        // 为了确保字符串以 '\0' 结束，我们显式设置 orig[i][n] = '\0'
        scanf("%s", tmp);
        strncpy(orig[i], tmp, n);
        orig[i][n] = '\0';
    }
    // 读取目标图案
    for (int i = 0; i < n; ++i) {
        // 读取目标网格，处理同上
        scanf("%s", tmp);
        strncpy(target[i], tmp, n);
        target[i][n] = '\0';
    }

    // 1) 顺时针旋转 90 度
    rotate90(orig, tmpg, n);
    // 将 tmpg 的每行都设置末尾 '\0'，因为我们把矩阵作为字符串行来比较
    for (int i = 0; i < n; ++i) tmpg[i][n] = '\0';
    if (equal_grid(tmpg, target, n)) { printf("1\n"); return 0; }

    // 2) 顺时针旋转 180 度
    rotate180(orig, tmpg, n);
    for (int i = 0; i < n; ++i) tmpg[i][n] = '\0';
    if (equal_grid(tmpg, target, n)) { printf("2\n"); return 0; }

    // 3) 顺时针旋转 270 度
    rotate270(orig, tmpg, n);
    for (int i = 0; i < n; ++i) tmpg[i][n] = '\0';
    if (equal_grid(tmpg, target, n)) { printf("3\n"); return 0; }

    // 4) 水平反射（左右镜像）
    reflect(orig, tmpg, n);
    for (int i = 0; i < n; ++i) tmpg[i][n] = '\0';
    if (equal_grid(tmpg, target, n)) { printf("4\n"); return 0; }

    // 5) 先水平反射再做 90/180/270 任意旋转（组合变换）
    // 先已将反射结果放在 tmpg，中间再对 tmpg 旋转并比较
    rotate90(tmpg, tmpg2, n);
    for (int i = 0; i < n; ++i) tmpg2[i][n] = '\0';
    if (equal_grid(tmpg2, target, n)) { printf("5\n"); return 0; }

    rotate180(tmpg, tmpg2, n);
    for (int i = 0; i < n; ++i) tmpg2[i][n] = '\0';
    if (equal_grid(tmpg2, target, n)) { printf("5\n"); return 0; }

    rotate270(tmpg, tmpg2, n);
    for (int i = 0; i < n; ++i) tmpg2[i][n] = '\0';
    if (equal_grid(tmpg2, target, n)) { printf("5\n"); return 0; }

    // 6) 保持不变（原图与目标图相同）
    if (equal_grid(orig, target, n)) { printf("6\n"); return 0; }

    // 7) 无效转换（以上都不符合）
    printf("7\n");

    // free
    for (int i = 0; i < n; ++i) {
        free(orig[i]); free(target[i]); free(tmpg[i]); free(tmpg2[i]);
    }
    free(orig); free(target); free(tmpg); free(tmpg2);
    return 0;
}
