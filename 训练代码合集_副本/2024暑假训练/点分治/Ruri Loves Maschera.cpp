// Ruri Loves Maschera

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 1e5;
int n, l, r;
int head[N * 2 + 2], ver[N * 2 + 2], edge[N * 2 + 2], nxt[N * 2 + 2];
int tr[N + 2], v[N + 2], S, root, sz[N + 2], d[N + 2], val[N + 2], mx[N + 2];
int tot, ans[N + 2];
std::vector<std::pair<int, int>> rem;

int lowbit(int x) {
    return x & (-x);
}
void plus(int p, int x) {
    while (p <= n) {
        tr[p] += x;
        p += lowbit(p);
    }
}
int query(int p) {
    int res = 0;
    while (p) {
        res += tr[p];
        p -= lowbit(p);
    }
    return res;
}
inline int sum(int x, int y) {
    return query(y) - query(x - 1);
}

void add(int x, int y, int z) {
    tot++;
    ver[tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

void find(int x, int fa) {
    sz[x] = 1, mx[x] = 0;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (v[y] || fa == y) continue;
        find(y, x);
        sz[x] += sz[y];
        if (sz[y] > mx[x]) mx[x] = sz[y];
    }
    mx[x] = std::max(mx[x], S - sz[x]);
    if (mx[x] < mx[root]) root = x;
}

void getdis(int x, int fa) {
    rem.push_back({val[x], d[x]});
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (v[y] || y == fa) continue;
        d[y] = d[x] + 1;
        val[y] = std::max(val[x], z);
        getdis(y, x);
    }
}

void bio_count(std::vector<std::pair<int, int>> &p, int &res) {
    // 第一维度用排序（最大值），第二维度用树状数组(长度)
    std::sort(p.begin(), p.end());
    // plus(1, 1);  // 把根节点加入到待数点的序列
    for (int i = 0; i < (int)p.size(); i++) {
        if (p[i].second - 1 > r) continue;
        // std::cout << l - p[i].second << std::endl;
        res += sum(std::max(1LL, l - (p[i].second - 1) + 1), r - (p[i].second - 1) + 1) * p[i].first;  // 这样应该就是不重不漏了，不用把所有当前的第一维都整理完再第二层
        plus(p[i].second, 1);
    }
    for (int i = 0; i < (int)p.size(); i++) {
        plus(p[i].second, -1);
    }
    // plus(1, -1);
}

void calc(int x) {
    // std::cout << x << std::endl;
    std::vector<std::pair<int, int>> res;
    std::vector<int> yy;
    int cntall = 0, ls = 0;
    // 可能需要特殊处理当前节点
    d[x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (v[y]) continue;
        yy.push_back(y);
        rem.clear();
        d[y] = 2;
        val[y] = z;
        getdis(y, x);
        ls = 0;
        // std::cout << y << std::endl;
        bio_count(rem, ls);
        cntall += ls;
        for (auto j : rem) {
            res.push_back(j);
            // std::cout << j.first << " " << j.second << std::endl;
        }
        // std::cout << x << " " << y << ": " << cntall << std::endl;
    }
    ls = 0;
    plus(1, 1);
    bio_count(res, ls);
    plus(1, -1);
    // std::cout << x << ": " << cntall << " " << ls << std::endl;
    ans[x] += (ls - cntall) * 2;
}

void dfs(int x) {
    // std::cout << x << std::endl;
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
    std::cin >> n >> l >> r;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1);
    int anss = 0;
    for (int i = 1; i <= n; i++) {
        anss += ans[i];
        // std::cout << ans[i] << " \n"[i == n];
    }
    std::cout << anss << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    // std::cin>>times;
    while (times--) {
        solve();
    }
    return 0;
}

/*
5 2 3
1 2 2
2 3 2
3 4 4
4 5 5

*/