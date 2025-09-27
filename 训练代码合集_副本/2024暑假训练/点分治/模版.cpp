// 模版例题1 : 点分治 + 桶 / 双指针（见双指针部分）
// https://www.luogu.com.cn/problem/P3806
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e4;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot, edge[N * 2 + 2];
int q[102], ans[N + 2], v[N + 2], sz[N + 2], mx[N + 2], S, root, d[N + 2];
int n, m;
bool t[10000004];
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
    if (mx[x] < mx[root]) root = x;  // 找到树的重心
}

void getdis(int x, int fa) {
    rem.push_back(d[x]);  // 记录下本次根节点的当前子节点搜索的所有深度
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (y == fa || v[y]) continue;
        d[y] = d[x] + z;
        getdis(y, x);
    }
}

void calc(int x) {
    // 这里其实不是向下便利，就只是当前节点的子节点
    std::vector<int> res;  // 记录下当前跟节点下的所有深度信息
    t[0] = 1;
    res.push_back(0);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        int z = edge[i];
        if (v[y]) continue;
        rem.clear();
        d[y] = z;  // 初始化深度
        getdis(y, x);
        for (int j = 0; j < (int)rem.size(); j++) {
            for (int k = 1; k <= m; k++) {
                if (q[k] >= rem[j] && t[q[k] - rem[j]]) ans[k] = 1;
            }
        }
        for (auto i : rem)
            if (i <= 1e7) t[i] = 1, res.push_back(i);
    }
    for (auto i : res) t[i] = 0;  // 其实就是 memset 0，但是这样时间复杂度会爆炸，所以才这样操作。
}

void solve(int x) {
    std::cout << x << std::endl;
    v[x] = 1;  // 保证了solve遍历不会出现循环
    calc(x);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (v[y]) continue;
        find(y, x);  // 第一次其实就是求sz
        S = sz[y], root = 0, mx[0] = 1e9;
        find(y, x);
        solve(root);
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> q[i];
    }
    solve(1);
    for (int i = 1; i <= m; i++) printf(ans[i] ? "AYE\n" : "NAY\n");
    return 0;
}