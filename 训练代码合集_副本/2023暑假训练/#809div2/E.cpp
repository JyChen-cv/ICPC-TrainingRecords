#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 1e5;
int ver[N * 2 + 2], fa[N + 2], nxt[N * 2 + 2], head[N + 2], tot, edge[N * 2 + 2], dep[N + 2], f[N + 2][22];
int gen, mx[N + 2][22], n, m, k;

int find(int x) {
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}

void add(int x, int y, int z) {
    tot++;
    edge[tot] = z;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x) {
    for (int i = 1; i <= gen; i++) {
        f[x][i] = f[f[x][i - 1]][i - 1];
        mx[x][i] = std::max(mx[f[x][i - 1]][i - 1], mx[x][i - 1]);
    }
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (dep[y]) continue;
        dep[y] = dep[x] + 1;
        f[y][0] = x;
        mx[y][0] = edge[i];
        dfs(y);
    }
}

int lca(int x, int y) {
    int res = 0;
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = gen; i >= 0; i--) {
        if (dep[f[x][i]] >= dep[y]) {
            res = std::max(res, mx[x][i]);
            x = f[x][i];
        }
    }
    if (x == y) return res;
    for (int i = gen; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            res = std::max(res, std::max(mx[x][i], mx[y][i]));
            x = f[x][i];
            y = f[y][i];
        }
    }
    return std::max(res, std::max(mx[x][0], mx[y][0]));
}

struct node {
    int l, r;
    int v;
} setr[N * 4 + 2];

void pushup(int u) {
    setr[u].v = std::max(setr[u << 1].v, setr[u << 1 | 1].v);
}

void build(int u, int l, int r) {
    setr[u] = {l, r, 0};
    if (l == r) {
        setr[u].v = lca(l, l + 1);
        return;
    }
    int mid = (l + r) / 2;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= setr[u].l && r >= setr[u].r) return setr[u].v;
    int mid = (setr[u].l + setr[u].r) / 2;
    int v = 0;
    if (l <= mid) v = query(u << 1, l, r);
    if (r > mid) v = std::max(v, query(u << 1 | 1, l, r));
    return v;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        for (int i = 1; i <= tot; i++) {
            ver[i] = nxt[i] = edge[i] = 0;
        }
        tot = 0;

        std::cin >> n >> m >> k;
        gen = log(n) / log(2) + 1;
        for (int i = 1; i <= n; i++) {
            dep[i] = head[i] = 0;
            for (int j = 0; j <= gen; j++) {
                f[i][j] = mx[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 1; i <= m; i++) {
            int a, b;
            std::cin >> a >> b;
            if (find(a) != find(b)) {
                fa[find(a)] = find(b);
                add(a, b, i);
                add(b, a, i);
            }
        }
        // 保证图联通吗? 保证吧
        dep[1] = 1;
        dfs(1);
        build(1, 1, n - 1);
        for (int i = 1; i <= k; i++) {
            int a, b;
            std::cin >> a >> b;
            if (b == a)
                std::cout << 0 << std::endl;
            else
                std::cout << query(1, a, b - 1) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}