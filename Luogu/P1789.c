/*
  P1789 【Mc生存】插火把

  题意简述：给定 n x n 方格，m 个火把和 k 个萤石的位置。
  火把会照亮曼哈顿距离 <= 2 的格子（|dx|+|dy| <= 2），
  萤石会照亮切比雪夫距离 <= 2 的格子（max(|dx|,|dy|) <= 2，即 5x5 方块）。
  如果某格既没有光照且没有物品（火把或萤石），则会生成怪物。
  统计会生成怪物的格子个数。

  解法：直接模拟。建立两个 n x n 布尔矩阵：
    - lit[i][j] 表示格子被照亮
    - occ[i][j] 表示格子放了火把或萤石（有物品）
  先标记所有物品位置为 occ，然后根据每个火把/萤石分别把周围被照亮的格子标记为 lit。
  最后遍历所有格子，统计 lit==false 且 occ==false 的格子数。

  复杂度：n<=100, m+k<=25，暴力更新 (每个物品最多处理 25 个格子) 足够。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) != 3) return 0;

    /* 使用 0-based 索引 */
    int maxn = n;
    // lit 和 occ 初始化为 0
    int lit[105][105] = {0};
    int occ[105][105] = {0};

    // 读取火把位置，先记录位置以便后面点亮
    int torx[30], tory[30];
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        // 转为 0-based
        --x; --y;
        torx[i] = x; tory[i] = y;
        if (x >= 0 && x < n && y >= 0 && y < n) occ[x][y] = 1;
    }

    // 读取萤石位置
    int gx[10], gy[10];
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x; --y;
        gx[i] = x; gy[i] = y;
        if (x >= 0 && x < n && y >= 0 && y < n) occ[x][y] = 1;
    }

    // 对每个火把，标记曼哈顿距离 <= 2 的格子为被照亮
    for (int t = 0; t < m; ++t) {
        int cx = torx[t], cy = tory[t];
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (abs(dx) + abs(dy) <= 2) {
                    int nx = cx + dx, ny = cy + dy;
                    if (0 <= nx && nx < n && 0 <= ny && ny < n) lit[nx][ny] = 1;
                }
            }
        }
    }

    // 对每个萤石，标记切比雪夫距离 <= 2（即 5x5）为被照亮
    for (int t = 0; t < k; ++t) {
        int cx = gx[t], cy = gy[t];
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nx = cx + dx, ny = cy + dy;
                if (0 <= nx && nx < n && 0 <= ny && ny < n) lit[nx][ny] = 1;
            }
        }
    }

    // 统计既没有光又没有物品的位置
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!lit[i][j] && !occ[i][j]) ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}
