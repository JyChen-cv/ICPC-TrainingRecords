// 消息传递

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e5;
int head[N + 2], ver[N * 2 + 2], nxt[N * 2 + 2], tot;
int v[N + 2], sz[N + 2], mx[N + 2], S, root, d[N + 2];
int t[N + 2], n, m, ans[N + 2];
std::vector<int> rem;
std::vector<std::pair<int, int> > q[N + 2], pq;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void getdis(int x, int fa) {
    rem.push_back(d[x]);
    for (auto i : q[x]) {
        if (i.first < (d[x] - 1)) continue;
        pq.push_back({i.first - (d[x] - 1), i.second});  // 要的就是更改之后的d
    }
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa || v[y]) continue;
        d[y] = d[x] + 1;
        getdis(y, x);
    }
}

void calc(int x) {
    // std::cout << x << ": " << std::endl;
    std::vector<int> res, yy;
    d[x] = 1;
    // res.push_back(1);
    // t[1] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (v[y]) continue;
        yy.push_back(y);
        rem.clear();
        pq.clear();
        d[y] = d[x] + 1;
        getdis(y, x);
        for (auto j : pq) {
            ans[j.second] += t[j.first + 1];
        }
        for (auto j : rem) {
            t[j] += 1;
            res.push_back(j);
        }
    }
    // std::cout << d[2] << " " << d[6] << std::endl;
    // for (auto i : pq) {
    //     std::cout << i.first << " " << i.second << std::endl;
    // }
    for (auto i : res) t[i] = 0;
    res.clear();
    d[x] = 1;
    res.push_back(1);
    t[1] = 1;
    for (int i = yy.size() - 1; i >= 0; i--) {
        int y = yy[i];
        rem.clear();
        pq.clear();
        d[y] = d[x] + 1;
        getdis(y, x);
        for (auto j : pq) {
            ans[j.second] += t[j.first + 1];
        }
        for (auto j : rem) {
            t[j] += 1;
            res.push_back(j);
        }
    }
    for (auto i : q[x]) {
        // std::cout << i.first << " :b " << i.second << " " << t[i.first + 1] << " " << ans[i.second] << std::endl;
        ans[i.second] += t[i.first + 1];
    }
    for (auto i : res) t[i] = 0;
}

void find(int x, int fa) {
    sz[x] = 1, mx[x] = 0;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa || v[y]) continue;
        find(y, x);
        sz[x] += sz[y];
        mx[x] = std::max(mx[x], sz[y]);
    }
    mx[x] = std::max(mx[x], S - sz[x]);
    if (mx[x] < mx[root]) root = x;
}

void dfs(int x) {
    v[x] = 1;
    calc(x);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (v[y]) continue;
        find(y, x);
        S = sz[y], root = 0, mx[0] = 1e9;
        find(y, x);
        dfs(root);
    }
}

void solve() {
    tot = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) head[i] = 0, q[i].clear(), v[i] = 0;
    for (int i = 1; i <= m; i++) ans[i] = 0;
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b), add(b, a);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        q[a].push_back({b, i});
    }
    dfs(1);
    for (int i = 1; i <= m; i++) {
        std::cout << ans[i] << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int times;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}

/*
2
4 2
1 2
2 3
3 4
1 1
2 2

6 2
1 2
2 3
2 4
2 5
5 6
2 0
6 0

*/