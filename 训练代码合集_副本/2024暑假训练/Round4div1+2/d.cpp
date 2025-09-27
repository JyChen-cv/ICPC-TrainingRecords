#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long
const int N = 2e5;
int head[N + 2], ver[N * 2 + 2], nxt[N * 2 + 2], tot;
int v[N + 2], t[N + 2][22], col[N + 2];
std::vector<int> q;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

bool dfs(int x, int fa, int l) {
        bool res = 0;
    for (int i = 1; i <= l; i++) {
        if (!t[x][i]) {
            col[x] = i;
            for (int j = head[x]; j; j = nxt[j]) {
                int y = ver[j];
                if (y == fa) continue;
                t[y][i] = 1;
                res = std::max(res, dfs(y, x, l));
                t[y][i] = 0;
                if (res) break;
            }
            col[x] = 0;
        }
        if (res) break;
    }
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    q.clear();
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            q.push_back(i);
            for (int j = 2; j * i <= n; j++) {
                v[j * i] = 1;
            }
        }
    }
    std::cout << q.size() << " " << n << std::endl;
    tot = 0;
    for (int i = 1; i <= n; i++) {
        head[i] = 0;
        for (int j = 1; j <= 20; j++) {
            t[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : q) {
            if ((i ^ j) < i && (i ^ j) >= 1) {
                add(i ^ j, i), add(i, i ^ j);
                // std::cout << i << " " << (i ^ j) << std::endl;
            }
        }
    }

    int l = 1, r = 10;
    while (l < r) {
        int mid = l + r >> 1;
        if (dfs(1, 0, mid)) {
            r = mid;
        } else
            l = mid + 1;
    }
    std::cout << l << std::endl;
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