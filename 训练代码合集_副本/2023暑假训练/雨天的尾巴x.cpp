#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e5, M = 1e5;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], total, tot, f[N + 2][30], dep[N + 2], t;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
struct group {  // 用来把操作离线
    int x, y, z;
} op[M + 2];
struct node {
    int l_s, r_s;  // 左右儿子
    int dat, num;  // 最大值 物品类型
} setr[N * 4];

void dfs(int x, int fa) {
    for (int i = 1; i <= t; i++) {
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        f[y][0] = x;
        dep[y] = dep[x] + 1;
        dfs(y, x);
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) std::swap(x, y);
    for (int i = t; i >= 0; i--) {
        if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    }
    if (x == y) return x;
    for (int i = y; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i], y = f[y][i];
        }
    }
    return f[x][0];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dep[1] = 1;
    dfs(1, 0);
    int t = (int)log(n) / log(2) + 1;

    std::vector<int> l;
    for (int i = 1; i <= m; i++) {
        std::cin >> op[i].x >> op[i].y >> op[i].z;
        l.push_back(op[i].z);
    }
    std::sort(l.begin(), l.end());
    l.erase(unique(l.begin(), l.end()), l.end());
    for (int i = 1; i <= m; i++) {
        op[i].z = std::lower_bound(l.begin(), l.end(), op[i].z) - l.begin();
    }

    return 0;
}