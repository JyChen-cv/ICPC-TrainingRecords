#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 5e5;
int cost[N + 2], mapp[N + 2], tot, nxt[N * 2 + 2], head[N + 2], ver[N * 2 + 2];
int f[N + 2][22], g[N + 2][22];
int n, d;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    f[x][0] = g[x][0] = mapp[x] ? cost[x] : 0;
    for (int i = 1; i <= d; i++) {
        f[x][i] = cost[x];
    }
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (fa == y) continue;
        dfs(y, x);
    }
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (fa == y) continue;
        for (int j = 0; j <= d; j++) {
            f[x][j] = std::min(f[x][i] + f[y][i], g[x][i] + f[y][i + 1]);
        }
    }
}

int main() {
    std::cin >> n >> d;
    for (int i = 1; i <= n; i++) scanf("%d", cost + i);
    int m;
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int a;
        scanf("%d", &a);
        mapp[a] = 1;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    return 0;
}