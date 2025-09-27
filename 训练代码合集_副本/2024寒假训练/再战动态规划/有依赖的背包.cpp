#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 100;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot;
int v[N + 2], w[N + 2], root;
int dp[N + 2][N + 2], n, m;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dfs(y, x);
    }
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k <= j; k++) {
                dp[x][j] = std::max(dp[x][j], dp[x][j - k] + dp[y][k]);
            }
        }
    }

    for (int i = m; i >= 0; i--) {
        if (i < w[x])
            dp[x][i] = 0;
        else
            dp[x][i] = dp[x][i - w[x]] + v[x];
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int c;
        std::cin >> w[i] >> v[i] >> c;
        if (c == -1)
            root = i;
        else
            add(i, c), add(c, i);
    }
    dfs(root, 0);
    std::cout << dp[root][m] << std::endl;
    return 0;
}