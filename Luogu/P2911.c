#include <stdio.h>

int main()
{
    int s1, s2, s3; // 定义三个骰子的最大点数
    int i, j, k; // 定义循环变量
    int arr[85] = {0}; // 定义数组用于统计点数和出现的次数，初始化为0
    int sum, max = 0; // 定义点数和变量sum和最大出现次数变量max
    int ans; // 定义最终答案变量

    scanf("%d%d%d", &s1, &s2, &s3); // 输入三个骰子的最大点数

    // 三重循环，枚举三个骰子的所有点数组合
    for (i = 1; i <= s1; i++)
        for (j = 1; j <= s2; j++)
            for (k = 1; k <= s3; k++)
            {
                sum = i + j + k; // 计算当前点数和
                arr[sum]++; // 对应点数和的计数加1
            }

    // 遍历所有可能的点数和，找到出现次数最多的点数和
    for (sum = 3; sum <= s1 + s2 + s3; sum++)
    {
        if (arr[sum] > max) // 如果当前点数和的出现次数大于最大值
        {
            max = arr[sum]; // 更新最大值
            ans = sum; // 更新答案为当前点数和
        }
    }

    printf("%d", ans); // 输出出现次数最多的点数和
    return 0; // 程序结束
}