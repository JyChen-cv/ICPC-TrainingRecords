#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 2e6;
int head[N + 2], nxt[N + 2], ver[N * 2 + 2], tot, n, k;
int dep[N + 2], fa[N + 2][30], number, dfn[N + 2], sz[N + 2], mn[N + 2], mx[N + 2];
int v[N + 2];
std::vector<std::pair<int, int>> tr[N + 2];
int ans1, ans2, ans3;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x) {
    dfn[x] = ++number;
    for (int i = 1; i <= 25; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa[x][0]) continue;
        dep[y] = dep[x] + 1;
        fa[y][0] = x;
        dfs(y);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 25; i >= 0; i--) {
        if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 25; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}

bool cmp(int x, int y) {
    return dfn[x] < dfn[y];
}

void deal(int x) {
    if (!tr[x].size()) {
        if (v[x]) sz[x]++;
        return;
    }
    std::vector<int> a1, a2;  // 分别存放最小的和最大的链长s
    for (int i = 0; i < (int)tr[x].size(); i++) {
        int y = tr[x][i].first;
        int z = tr[x][i].second;
        deal(y);
        a1.push_back(mn[y] + z), a2.push_back(mx[y] + z);
        ans1 += (k - sz[y]) * sz[y] * z;
        sz[x] += sz[y];
    }
    std::sort(a1.begin(), a1.end());
    std::sort(a2.begin(), a2.end());
    mn[x] = a1[0], mx[x] = a2[a2.size() - 1];
    if (v[x]) {
        sz[x]++;
        ans2 = std::min(ans2, mn[x]);
        ans3 = std::max(ans3, mx[x]);
        mn[x] = 0;
    }
    if (a1.size() >= 2) ans2 = std::min(ans2, a1[0] + a1[1]);
    if (a2.size() >= 2) ans3 = std::max(ans3, a2[a2.size() - 1] + a2[a2.size() - 2]);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dep[1] = 1;
    dfs(1);

    int tim;
    std::cin >> tim;
    while (tim--) {
        std::cin >> k;
        std::vector<int> h, res;
        for (int i = 1; i <= k; i++) {
            int a;
            std::cin >> a;
            v[a] = 1;
            h.push_back(a);
        }
        std::sort(h.begin(), h.end(), cmp);
        res.push_back(h[0]), res.push_back(1);
        for (int i = 1; i < (int)h.size(); i++) {
            res.push_back(h[i]);
            res.push_back(lca(h[i - 1], h[i]));
        }
        std::sort(res.begin(), res.end(), cmp);
        res.erase(unique(res.begin(), res.end()), res.end());
        for (int i = 1; i < (int)res.size(); i++) {
            int ls = lca(res[i], res[i - 1]);
            tr[ls].push_back({res[i], dep[res[i]] - dep[ls]});
            // std::cout << ls << " " << res[i] << " " << dep[res[i]] - dep[ls] << std::endl;
        }
        ans1 = 0, ans2 = 1e15, ans3 = 0;
        deal(1);
        std::cout << ans1 << " " << ans2 << " " << ans3 << std::endl;
        for (int i = 0; i < k; i++) v[h[i]] = 0;
        for (auto i : res) {
            sz[i] = mx[i] = mn[i] = 0;
            tr[i].clear();
        }
    }
    return 0;
}