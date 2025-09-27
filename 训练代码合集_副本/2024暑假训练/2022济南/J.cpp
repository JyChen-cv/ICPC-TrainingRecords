#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1000, B = 200;
int a[N + 2][4];
// dp[i][x1][x2][x3]表示当前是第i天，第i个技能已经x_i天没有复习了
int f[2][3][B + 2][B + 2];  // 这里i很明显只和i-1有关，所以第一维可以滚掉
// 这里第三维度和第四维度的定义是相对的，因为三个维度中必然有一个维度是1，所以采用这种方式可以节省空间，又因为时间就是填一遍表，所以进而节省时间。
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> a[i][j];
        }
    }
    memset(f, 0, sizeof f);
    int cur = 0, nxt = 1;
    for (int i = 0; i < n; std::swap(cur, nxt), i++) {
        for (int j = 0; j < 3; j++) {
            for (int x = 0; x < B && x <= i; x++) {
                for (int y = 0; y < B && y <= i; y++) {
                    // 用填表法去更新
                    int nx = x ? x + 1 : 0, ny = y ? y + 1 : 0;  // 如果是0就表示还未开始学习这个技巧
                    if (nx < B && ny < B) {                      // 选自己
                        f[nxt][j][nx][ny] = std::max(f[nxt][j][nx][ny], f[cur][j][x][y] - nx - ny + a[i + 1][j]);
                    }
                    if (ny < B) {  // 选下一个
                        f[nxt][(j + 1) % 3][ny][1] = std::max(f[nxt][(j + 1) % 3][ny][1], f[cur][j][x][y] - ny - 1 + a[i + 1][(j + 1) % 3]);
                    }
                    if (nx < B) {  // 选下两个
                        f[nxt][(j + 2) % 3][1][nx] = std::max(f[nxt][(j + 2) % 3][1][nx], f[cur][j][x][y] - 1 - nx + a[i + 1][(j + 2) % 3]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < 3; j++) {
        for (int x = 0; x < B; x++) {
            for (int y = 0; y < B; y++) {
                ans = std::max(ans, f[cur][j][x][y]);
            }
        }
    }
    std::cout << ans << std::endl;
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}