#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

#define int long long
const int N = 2e5;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot;
int a[N + 2];
void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
int dfs(int x, int fa) {
    int res = a[x], ls = 1e15;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        ls = std::min(ls, dfs(y, x));
    }
    if (x == 1) {
        return res + ls;
    } else if (ls == 1e15)
        return res;
    else {
        if (ls >= res)
            return (res + ls) / 2;
        else
            return ls;
    }
}
void solve() {
    int n;
    std::cin >> n;
    tot = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int a;
        std::cin >> a;
        add(a, i), add(i, a);
    }
    std::cout << dfs(1, 0) << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}