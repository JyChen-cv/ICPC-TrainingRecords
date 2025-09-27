// 聪聪与可可

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 2e4;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot, edge[N * 2 + 2];
int v[N + 2], d[N + 2], S, sz[N + 2], root, mx[N + 2];
std::vector<int> rem;
int cnt[4], ans;

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
        if (v[y] || y == fa) continue;
        find(y, x);
        sz[x] += sz[y];
        mx[x] = std::max(mx[x], sz[y]);
    }
    mx[x] = std::max(mx[x], S - sz[x]);
    if (mx[x] < mx[root]) root = x;
}

void deal(std::vector<int> &q, int &result) {
    memset(cnt, 0, sizeof cnt);
    for (auto i : q) {
        int ls = i % 3;
        if (ls != 0) ls = 3 - ls;
        result += cnt[ls];
        cnt[i % 3]++;
    }
    // std::cout << result << "?\n";
}

void getdis(int x, int fa) {
    rem.push_back(d[x]);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (v[y] || y == fa) continue;
        d[y] = d[x] + z;
        getdis(y, x);
    }
}

void calc(int x) {
    int cntall = 0, ls = 0;
    std::vector<int> res;
    res.push_back(0);  // 只有这里计算根节点，子树里面本题目不考虑根节点，因为这样情况在本题目中是合法的，不需要被容斥掉
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (v[y]) continue;
        rem.clear();
        d[y] = z;
        getdis(y, x);
        ls = 0;
        // std::cout << rem.size() << std::endl;
        deal(rem, ls);
        cntall += ls;
        for (auto j : rem) res.push_back(j);
        // std::cout << y << ":: " << cntall << std::endl;
    }
    ls = 0;
    deal(res, ls);
    // std::cout << x << ": " << ls << " " << cntall << std::endl;
    ans += ls - cntall;
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

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

signed main() {
    int n;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1);
    ans = ans * 2 + n;
    int ls = gcd(ans, n * n);
    ans /= ls;
    std::cout << ans << "/" << (n * n / ls) << std::endl;
    return 0;
}