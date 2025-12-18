#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/* 解析 a 字符串为放大 1e6 的整数 A
   输入 s 是形如 "123.456789"（题目保证小数点后有 6 位）的字符串。
   返回值 A = round(a * 1e6)（这里直接按位构造，避免浮点误差）。
   例如 "1.000000" -> 1000000, "2.500000" -> 2500000。
   处理了可选的 '+' 或 '-' 符号（但题目中 a_i >= 1 都是正数）。
*/
long long parseA(const char *s) {
    long long intpart = 0;   // 整数部分
    long long frac = 0;      // 小数部分，放大到 6 位后存为整数
    const char *p = s;
    int neg = 0;             // 是否为负数标志（题目中不会用到，但健壮性处理）
    if (*p == '+') p++;
    if (*p == '-') { neg = 1; p++; }

    // 解析整数部分（小数点之前的数字）
    while (*p && *p != '.') {
        if (*p >= '0' && *p <= '9') {
            intpart = intpart * 10 + (*p - '0');
        }
        p++;
    }

    // 解析小数部分，题目保证有且恰好 6 位小数，但这里通用处理前 6 位
    if (*p == '.') {
        p++;
        int cnt = 0;
        while (*p && cnt < 6) {
            if (*p >= '0' && *p <= '9') {
                frac = frac * 10 + (*p - '0');
                cnt++;
            }
            p++;
        }
        // 若不足 6 位（保险处理），用乘 10 补齐
        while (cnt < 6) { frac = frac * 10; cnt++; }
        // 若输入有多于6位小数，超出的位被忽略（题目保证不需要此处理）
    } else {
        frac = 0;
    }

    long long A = intpart * 1000000LL + frac; // 合并整数和放大的小数部分
    if (neg) A = -A;
    return A;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0; // 读取操作次数 n，若失败则退出
    const long long Q = 1000000LL;      // 分母 1e6（用于还原小数)

    // 动态分配数组保存所有操作（先读入所有操作以便计算最大影响编号 M）
    long long *As = (long long*)malloc(sizeof(long long) * n);
    long long *ts = (long long*)malloc(sizeof(long long) * n);
    if (!As || !ts) return 0; // 分配失败则退出

    long long maxPos = 0; // 将被按到的最大灯编号（floor(t * a) 的最大值）
    for (int i = 0; i < n; i++) {
        char as[64];
        long long t;
        if (scanf("%s%lld", as, &t) != 2) return 0; // 读取 a 的字符串表示和 t
        long long A = parseA(as); // A = a * 1e6（整数）
        As[i] = A;
        ts[i] = t;
        if (A > 0) {
            // 计算该操作能影响到的最大编号：floor(t * a) = floor(t * A / Q)
            long long pos = (A * t) / Q;
            if (pos > maxPos) maxPos = pos;
        }
    }

    /* 分配 parity 数组，记录每个编号灯被按次数的奇偶性
       下标范围 0..M（题目保证 a_i >= 1，因此实际编号最小为 1，这里保证数组下标充足）。
       使用 unsigned char 节省内存，值为 0 或 1。
    */
    int M = (int)maxPos;
    unsigned char *par = (unsigned char*)calloc((size_t)M + 1, 1);
    if (!par) { free(As); free(ts); return 0; }

    /* 枚举所有操作的所有 j（总次数 T <= 2e6），计算 v = floor(j * a) 并翻转 parity[v]。
       由于题目限制总枚举次数较小，这里直接枚举最简单、直观且高效。
       注意使用整数乘除：v = (j * A) / Q。
    */
    for (int i = 0; i < n; i++) {
        long long A = As[i];
        long long t = ts[i];
        if (A == 0) continue; // 若 a == 0，则 floor(j*a) == 0，不会改变有效编号（题目中 a>=1，此分支一般不会执行）
        for (long long j = 1; j <= t; j++) {
            long long v = (j * A) / Q; // v = floor(j * a)
            if (v >= 0 && v <= M) {
                par[v] ^= 1; // 翻转该编号灯的奇偶性（0->1 或 1->0）
            }
            // 理论上 v>=1（因为 a>=1），但我们仍然检查范围以防万一
        }
    }

    /* 在 parity 数组中查找唯一为 1 的下标并输出。
       题目保证最终恰有且只有一盏灯是开的，因此可以直接输出第一个为 1 的下标。
    */
    for (int i = 0; i <= M; i++) {
        if (par[i]) {
            printf("%d\n", i);
            break;
        }
    }

    // 释放分配的内存并退出
    free(As);
    free(ts);
    free(par);
    return 0;
}