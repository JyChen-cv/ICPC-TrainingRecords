#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 1e5;
int head[N + 2], ver[N * 2 + 2], nxt[N * 2 + 2], tot;
int w[N + 2], minw[N + 2][24], t[N + 2][24], fa[N + 2][24], dep[N + 2];
int dfn[N + 2], total;
std::vector<int> tr[N + 2], cost(N + 2);

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x) {
    dfn[x] = ++total;
    for (int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa[x][0]) continue;
        fa[y][0] = x;
        dep[y] = dep[x] + 1;
        dfs(y);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

int getmin(int x, int y) {
    if (x < y) std::swap(x, y);
    int res = 1e15;
    for (int i = 20; i >= 0; i--) {
        if (t[x][i] >= y) {
            res = std::min(res, minw[x][i]);
            // std::cout << x << " " << t[x][i] << " " << y << " " << i << std::endl;
            x = t[x][i];
        }
    }
    return res;
}

bool cmp(int x, int y) {
    return dfn[x] < dfn[y];
}

int deal(int x) {
    if (!tr[x].size()) {
        return cost[x];
    }
    int res = 0;
    for (int i = 0; i < (int)tr[x].size(); i++) {
        int y = tr[x][i];
        res += deal(y);
    }
    return std::min(res, cost[x]);
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        t[i][0] = i;
        t[i][1] = std::max(1LL * 0, i - 1);
        // std::cout << i << ": " << t[i][0] << " ";
        for (int j = 2; j <= 20; j++) {
            t[i][j] = t[t[i][j - 1]][j - 1];
            // std::cout << t[i][j] << " \n"[j == 20];
        }
        minw[i][0] = w[i];
        // std::cout << i << ": " << minw[i][0] << " ";
        for (int j = 1; j <= 20; j++) {
            minw[i][j] = std::min(minw[i][j - 1], minw[t[i][j - 1]][j - 1]);
            // std::cout << minw[i][j] << " \n"[j == 20];
        }
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dep[1] = 1;
    dfs(1);
    std::vector<int> q[N + 2], ans(N + 2);
    for (int i = 1; i <= n; i++) {
        q[dep[i]].push_back(i);
    }
    for (int i = n; i >= 2; i--) {  // 根节点单独算就行
        if (q[i].size() == 0)
            continue;

        std::sort(q[i].begin(), q[i].end(), cmp);
        std::vector<int> res;
        res.push_back(1), res.push_back(q[i][0]);
        for (int j = 1; j < (int)q[i].size(); j++) {
            res.push_back(q[i][j]);
            res.push_back(lca(q[i][j - 1], q[i][j]));
            // std::cout << q[i][j - 1] << " " << q[i][j] << " " << std::endl;
        }
        std::sort(res.begin(), res.end(), cmp);
        res.erase(unique(res.begin(), res.end()), res.end());
        // std::cout << res.size() << std::endl;
        // for (auto i : res) std::cout << i << std::endl;
        for (int j = 1; j < (int)res.size(); j++) {
            int ls = lca(res[j - 1], res[j]);
            tr[ls].push_back(res[j]);
            cost[res[j]] = getmin(i - dep[ls] - 1, i - dep[res[j]]);
            // std::cout << i << ": " << res[j] << " " << cost[res[j]] << std::endl;
        }
        cost[1] = w[i - 1];
        ans[i] = deal(1);
        for (auto j : res) {
            tr[j].clear();
            cost[j] = 0;
        }
    }
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        answer += ans[i];
        // if (ans[i]) std::cout << ans[i] << " ";
    }
    answer += w[0];
    std::cout << answer << std::endl;
    for (int i = 1; i <= n; i++) {
        head[i] = 0;
    }
    total = 0;
    tot = 0;
}

signed main() {
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
1
4
10 15 40 1
1 2
2 3
2 4

 */