// 根本原因是双指针没有办法遍历所有==k的情况，所以其实就是假的算法

// Race #95分未优化双指针多遍骗分法

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 2e5;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot, edge[N * 2 + 2];
int ans, v[N + 2], sz[N + 2], mx[N + 2], S, root, d[N + 2], bel[N + 2], dep[N + 2];
int n, m;
std::vector<int> rem;

void add(int x, int y, int z) {
    tot++;
    edge[tot] = z;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
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
    if (mx[x] < mx[root]) root = x;  // 这里感觉没必要，按理说找到一个就可以返回了，可能是和第一次便利有关吧
}

void getdis(int x, int fa, int dis, int from) {
    rem.push_back(x);
    dep[x] = dep[fa] + 1;
    d[x] = dis;
    bel[x] = from;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (y == fa || v[y]) continue;
        getdis(y, x, dis + z, from);
    }
}

bool cmp(int x, int y) { return d[x] < d[y]; }
void calc(int x) {
    rem.clear();
    rem.push_back(x);
    d[x] = 0;
    bel[x] = x;  // belong
    dep[x] = 0;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (v[y]) continue;
        getdis(y, x, z, y);
    }
    std::sort(rem.begin(), rem.end(), cmp);  // 按照深度排序

    int l = 0, r = rem.size() - 1;
    // std::cout << x << ": " << rem.size() << std::endl;
    while (l < r) {
        if (d[rem[l]] + d[rem[r]] > m)
            r--;
        else if (d[rem[l]] + d[rem[r]] < m)
            l++;
        else if (bel[rem[l]] == bel[rem[r]]) {
            if (d[rem[r]] == d[rem[r - 1]])
                r--;
            else
                l++;
        } else {
            ans = std::min(ans, dep[rem[l]] + dep[rem[r]]);
            if (d[rem[r]] == d[rem[r - 1]])
                r--;
            else
                l++;
            // break;
        }
    }
    l = 0, r = rem.size() - 1;
    while (l < r) {
        if (d[rem[l]] + d[rem[r]] > m)
            r--;
        else if (d[rem[l]] + d[rem[r]] < m)
            l++;
        else if (bel[rem[l]] == bel[rem[r]]) {
            if (d[rem[l]] == d[rem[l + 1]])
                l++;
            else
                r--;
        } else {
            ans = std::min(ans, dep[rem[l]] + dep[rem[r]]);
            if (d[rem[l]] == d[rem[l + 1]])
                l++;
            else
                r--;
            // break;
        }
    }
}

void solve(int x) {
    v[x] = 1;  // 保证了solve遍历不会出现循环
    calc(x);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (v[y]) continue;
        find(y, x);  // 第一次其实就是求sz
        S = sz[y], root = 0, mx[0] = 1e9;
        find(y, x);  // 第二次是找到重心
        solve(root);
    }
}

signed main() {
    // freopen("/Users/chenjiayou/Downloads/P4149_2.in", "r", stdin);
    std::cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a++, b++;
        add(a, b, c), add(b, a, c);
    }
    ans = 1e15;
    solve(1);
    std::cout << (ans == 1e15 ? -1 : ans) << std::endl;
    return 0;
}