#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int N = 2e5;
int mapp[N + 2], d[N + 2];
int tot, head[N + 2], nxt[N + 2], ver[N + 2], ans = -1e15;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs1(int x, int fa) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dfs1(y, x);
        if (d[y] > 0) d[x] += d[y];
    }
    d[x] += mapp[x];
    ans = std::max(ans, d[x]);
    // std::cout << x << " " << d[x] << std::endl;
}

signed main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs1(1, 0);
    std::cout << ans << std::endl;
    return 0;
}