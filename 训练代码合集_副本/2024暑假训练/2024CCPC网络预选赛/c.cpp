#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e6;
int n, m;
int nxt[N * 2 + 2], ver[N * 2 + 2], head[N + 2], tot, v[N + 2];
int dp[N + 2][3], root;
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
}
void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        head[i] = 0;
        v[i] = 0;
    }
    tot = 0;
    for (int i = 1; i <= m; i++) {
        int a;
        std::cin >> a;
        if (i == 1) root = a;
        v[a] = 1;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(root, 0);
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}