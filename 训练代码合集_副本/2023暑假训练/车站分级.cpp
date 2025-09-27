#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

// 这题目很重要的一点是利用串虚拟点来简化计算
const int N = 1e3, M = 1e6;
int n, m, ver[M + 2], head[N * 2 + 2], edge[M + 2], nxt[M + 2], tot;
bool v[N + 2];
int q[N * 2 + 2], du[N * 2 + 2], d[N * 2 + 2];

void add(int x, int y, int z) {
    tot++;
    du[y]++;
    ver[tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

void topsort() {
    int hh = 1, tt = 0;
    for (int i = 1; i <= n + m; i++) {
        if (!du[i]) q[++tt] = i;
    }
    while (hh <= tt) {
        int x = q[hh++];
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            if (--du[y] == 0) q[++tt] = y;
        }
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        memset(v, 0, sizeof v);
        int a, mx = 0, mi = n;
        std::cin >> a;
        for (int j = 1; j <= a; j++) {
            int b;
            std::cin >> b;
            mx = std::max(b, mx);
            mi = std::min(b, mi);
            v[b] = 1;
        }
        int tg = n + i;
        for (int j = mi; j <= mx; j++) {
            if (v[j])
                add(tg, j, 1);
            else
                add(j, tg, 0);
        }
    }

    topsort();

    memset(d, 0x3f, sizeof(d));
    for (int i = n * 2; i >= 1; i--) {
        int x = q[i];
        for (int j = head[x]; j; j = nxt[j]) {
            int y = ver[j];
            int z = edge[j];
            if (d[y] > d[x] + z) d[y] = d[x] + z;
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        ans = std::min(ans, d[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}