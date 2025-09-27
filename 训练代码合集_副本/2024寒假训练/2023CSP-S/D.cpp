#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long
const int N = 1e5;
struct group {
    int a, b, c, d;
    void in() {
        std::cin >> a >> b >> c;
        b = std::max(b, 1ll);
        if (a % b == 0)
            d = a / b;
        else
            d = a / b + 1;
    }
    bool operator<(const group& t) const {
        return a * t.b < t.a * b;
    }
} mapp[N + 2];
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot, dep[N + 2], v[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

bool cmp(int x, int y) {
    return mapp[y] < mapp[x];
}

void dfs(int x, int fa) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dfs(y, x);
        dep[y] = dep[x] + 1;
    }
}

int dfs2(int x) {
    if (v[x] || x == 1) return x;
    v[x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (dep[y] < dep[x]) {
            return dfs2(y);
        }
    }
}

signed main() {
    freopen("/Users/chenjiayou/Downloads/P9755_1.in", "r", stdin);
    int n;
    std::cin >> n;
    int tag = 1;
    for (int i = 1; i <= n; i++) {
        mapp[i].in();
        if (mapp[i].c != 0) tag = 0;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    if (tag) {
        dep[1] = 1;
        dfs(1, 0);
        std::vector<int> res;
        for (int i = 1; i <= n; i++) {
            res.push_back(i);
        }
        std::sort(res.begin(), res.end(), cmp);
        int t = 1, ans = 0;
        v[1] = 1;
        ans = std::max(ans, mapp[1].d);
        for (auto i : res) {
            if (v[i])
                continue;
            else {
                t += dep[i] - dep[dfs2(i)];
                ans = std::max(ans, t + mapp[i].d);
            }
        }
        std::cout << ans << std::endl;
    } else {
    }
    return 0;
}