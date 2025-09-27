// Tree

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

const int N = 4e4;
int head[N + 2], nxt[N * 2 + 2], edge[N * 2 + 2], ver[N * 2 + 2], tot;
int n, k, ans, v[N + 2], sz[N + 2], S, mx[N + 2], root, tr[N + 2], d[N + 2], tr0;
std::vector<int> rem;

int lowbit(int x) { return x & (-x); }
void plus(int p, int x) {
    // 这里注意不能给0增加，所以单独开一个节点保存0
    if (p == 0) {
        tr0 += x;
        return;
    }
    while (p <= k) {
        tr[p] += x;
        p += lowbit(p);
    }
}
int query(int x) {
    if (x < 0) return 0;
    int res = 0;
    while (x) {
        res += tr[x];
        x -= lowbit(x);
    }
    return res + tr0;  // 询问是非负整数，也就>=0
}

void add(int x, int y, int z) {
    tot++;
    ver[tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

void find(int x, int fa) {
    // std::cout << x << " " << fa << std::endl;
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

void getdis(int x, int fa) {
    // std::cout << x << " " << fa << std::endl;
    rem.push_back(d[x]);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (y == fa || v[y]) continue;
        d[y] = d[x] + z;
        getdis(y, x);
    }
}

void calc(int x) {
    // std::cout << x << ": " << std::endl;
    std::vector<int> res;
    res.push_back(0);
    plus(0, 1);  // 这里一定要注意在树状数组中特殊处理0的情况
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (v[y]) continue;
        rem.clear();
        d[y] = z;
        getdis(y, x);
        for (auto j : rem) {
            ans += query(k - j);
        }
        for (auto j : rem) {
            res.push_back(j);
            plus(j, 1);
        }
    }
    for (auto i : res) {
        plus(i, -1);
    }
}

void solve(int x) {
    v[x] = 1;
    calc(x);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (v[y]) continue;
        find(y, x);
        root = 0, S = sz[y], mx[root] = 1e9;
        find(y, x);
        solve(y);
    }
}

int main() {
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    std::cin >> k;
    solve(1);
    std::cout << ans << std::endl;
    return 0;
}