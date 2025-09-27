// Blood Cousins
// https://codeforces.com/problemset/problem/208/E
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e5;
int tot, head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2];
int sz[N + 2], son[N + 2], fa[N + 2][30], dep[N + 2];
int ans[N + 2], hh, rem[N + 2];  // 深度为i的节点的数量
std::vector<std::pair<int, int>> q[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x) {
    sz[x] = 1;
    for (int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa[x][0]) continue;
        fa[y][0] = x;
        dep[y] = dep[x] + 1;
        dfs(y);
        sz[x] += sz[y];
        if (sz[y] > sz[son[x]]) son[x] = y;
    }
}

void calc(int x, int val) {
    if (val == 1) {
        rem[dep[x]]++;

    } else
        rem[dep[x]]--;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa[x][0] || y == hh) continue;
        calc(y, val);
    }
}

void dsu(int x, int op) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa[x][0] || y == son[x]) continue;
        dsu(y, 0);
    }
    if (son[x]) {
        dsu(son[x], 1);
        hh = son[x];
    }
    calc(x, 1);
    hh = 0;
    if (q[x].size()) {
        for (auto i : q[x]) {
            ans[i.second] = rem[i.first] - 1;
        }
    }
    if (!op) {
        calc(x, -1);
        // ilnum = 0;
    }
}

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> root;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        if (a)
            add(a, i), add(i, a);
        else
            root.push_back(i);
    }
    for (auto i : root) {
        dep[i] = 1;
        dfs(i);
    }

    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        int bb = b;
        for (int i = 20; i >= 0; i--) {
            if (bb >= (1 << i)) {
                bb -= (1 << i);
                a = fa[a][i];
            }
        }
        // std::cout << a << " " << b << std::endl;
        if (a == 0) {
            ans[i] = 0;
            continue;
        }
        q[a].push_back(std::make_pair(b + dep[a], i));  // kanyixia +-1
    }
    for (auto i : root) {
        dsu(i, 0);
    }
    for (int i = 1; i <= m; i++) {
        std::cout << ans[i] << " \n"[i == m];
    }
    return 0;
}