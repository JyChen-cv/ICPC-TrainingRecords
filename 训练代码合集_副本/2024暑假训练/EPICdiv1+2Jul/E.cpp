#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
#define inf 1e15 + 7
const int N = 5000;
int mapp[N + 2], nxt[N * 2 + 2], head[N + 2], ver[N * 2 + 2];
int tot, n, ans, dx[N + 2], deep[N + 2], rem[N + 2][N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void merge(int x[], int y[]) {
    for (int i = 1; i <= n; i++) {
        x[i] += y[i];
    }
}

void calc(int x[], int dep, int &val) {
    val = -val;
    for (int i = dep + 1; i <= n; i++) {
        if (val <= x[i]) {
            ans += (i - dep) * val;
            x[i] -= val;
            val = 0;
            break;
        } else {
            ans += (i - dep) * x[i];
            val -= x[i];
            x[i] = 0;
        }
        if (!val) break;
    }
}

void dfs(int x, int fa) {
    int sum = 0, leaf = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        leaf = 0;
        deep[y] = deep[x] + 1;
        dfs(y, x);
        merge(rem[x], rem[y]);
        sum += mapp[y];
    }
    if (leaf) {
        dx[x] = 0;
        rem[x][deep[x]] += inf;
        return;
    }
    dx[x] = sum - mapp[x];
    if (dx[x] >= 0) {
        rem[x][deep[x]] += dx[x];
    } else {
        calc(rem[x], deep[x], dx[x]);
    }
}

void solve() {
    for (int i = 1; i <= tot; i++) {
        head[i] = 0;
    }
    tot = 0;
    ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
        for (int j = 1; j <= n; j++) rem[i][j] = 0;
    }
    for (int i = 2; i <= n; i++) {
        int a;
        std::cin >> a;
        add(i, a), add(a, i);
    }
    deep[1] = 1;
    dfs(1, 0);
    std::cout << ans << std::endl;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}