#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int N = 3000;
int mapp[N + 2], head[N + 2], ver[N + 2], nxt[N + 2], tot;
int dp[N + 2][3];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    int res = 0, tag = 0;
    dp[x][1] = mapp[x];
    dp[x][0] = 0;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dfs(y, x);
        if (dp[y][2] < dp[y][1])
            res += dp[y][2];
        else {
            tag = 1;
            res += dp[y][1];
        }
    }
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        if (tag == 0) dp[x][2] = std::min(res - dp[y][2] + dp[y][1], dp[x][2]);
        dp[x][1] += std::min(std::min(dp[y][0], dp[y][1]), dp[y][2]);
        dp[x][0] += std::min(dp[y][1], dp[y][2]);
    }
    if (tag) dp[x][2] = res;
    // std::cout << x << " " << dp[x][0] << " " << dp[x][1] << " " << dp[x][2] << std::endl;
}

signed main() {
    memset(dp, 0x3f, sizeof(dp));
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, c;
        std::cin >> a >> mapp[a] >> c;
        for (int j = 1; j <= c; j++) {
            int d;
            std::cin >> d;
            add(a, d);
            add(d, a);
        }
    }
    dfs(1, 0);
    std::cout << std::min(dp[1][1], dp[1][2]) << std::endl;
    return 0;
}