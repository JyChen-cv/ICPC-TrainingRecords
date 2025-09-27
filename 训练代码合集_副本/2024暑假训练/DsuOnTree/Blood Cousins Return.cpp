// Blood Cousins Return
// https://codeforces.com/problemset/problem/246/E

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

const int N = 1e5;
int tot, head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2];
int sz[N + 2], son[N + 2], fa[N + 2][30], dep[N + 2];
int ans[N + 2], hh;
std::string nm[N + 2];
std::map<std::string, int> rem[N + 2];  // 深度为i的节点的数量
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
        rem[dep[x]][nm[x]] += 1;

    } else {
        rem[dep[x]][nm[x]] -= 1;
        if (rem[dep[x]][nm[x]] == 0) rem[dep[x]].erase(nm[x]);
    }

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
            ans[i.second] = rem[i.first].size();
        }
    }
    if (!op) {
        calc(x, -1);
    }
}

int main() {
    freopen("/Users/chenjiayou/Desktop/2024暑假训练/DsuOnTree/okok.in", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n;
    std::vector<int> root;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> nm[i] >> a;
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
        if (b + dep[a] <= n)  // 有点毒瘤的特判
            q[a].push_back(std::make_pair(b + dep[a], i));
        else
            ans[i] = 0;
    }
    for (auto i : root) {
        dsu(i, 0);
    }
    for (int i = 1; i <= m; i++) {
        std::cout << ans[i] << "\n";
    }
    return 0;
}