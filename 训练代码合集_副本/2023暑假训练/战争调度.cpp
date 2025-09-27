#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define inf 1e8;
const int N = 10;
long long w[1 << (N + 1)][N + 2], f[1 << (N + 1)][N + 2], dp[1 << (N + 1)][1 << (N + 1)];
int n, m;
std::vector<int> q;

void dfs(int x) {
    int c = 1 << (n - 1 - (int)(log(x) / log(2)));
    for (int i = 0; i <= c; i++) dp[x][i] = 0;  // !!!初始化要不然会在不同状态之间产生非法状态
    if (x >= 1 << (n - 1)) {
        dp[x][1] = 0;
        dp[x][0] = 0;
        for (int i = (int)q.size() - 1; i >= 0; i--) {
            dp[x][1] += w[x - (1 << (n - 1)) + 1][n - 1 - i] * q[i];
            dp[x][0] += f[x - (1 << (n - 1)) + 1][n - 1 - i] * (!q[i]);
        }
        return;
    }
    q.push_back(0);
    dfs(x << 1);
    dfs(x << 1 | 1);
    q.pop_back();
    for (int i = 0; i <= c; i++) {
        for (int j = 0; j + i <= c; j++) {
            dp[x][i + j] = std::max(dp[x][i + j], dp[x << 1][i] + dp[x << 1 | 1][j]);
        }
    }
    q.push_back(1);
    dfs(x << 1);
    dfs(x << 1 | 1);
    q.pop_back();
    for (int i = 0; i <= c; i++) {
        for (int j = 0; j + i <= c; j++) {
            dp[x][i + j] = std::max(dp[x][i + j], dp[x << 1][i] + dp[x << 1 | 1][j]);
        }
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= (1 << (n - 1)); i++)
        for (int j = 1; j <= (n - 1); j++)
            std::cin >> w[i][j];
    for (int i = 1; i <= (1 << (n - 1)); i++)
        for (int j = 1; j <= (n - 1); j++)
            std::cin >> f[i][j];
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) dp[i][j] = -inf;
    }
    dfs(1);
    long long ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = std::max(ans, dp[1][i]);
    }
    std::cout << ans << std::endl;
    // for (int i = 1; i <= (1 << n) - 1; i++) {
    //     int c = 1 << (n - 1 - (int)(log(i) / log(2)));
    //     for (int j = 0; j <= c; j++) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return 0;
}