#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 5e5;
int n, m;
std::string c;
int tot, head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2];
int sz[N + 2], son[N + 2], dep[N + 2], hh;
int rem[N + 2][30];  // 深度为i，的字母j的数量
int ans[N + 2], oddnumber[N + 2];
std::vector<std::pair<int, int> > q[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    sz[x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dep[y] = dep[x] + 1;
        dfs(y, x);
        sz[x] += sz[y];
        if (sz[y] > sz[son[x]]) son[x] = y;
    }
}

void calc(int x, int fa, bool val) {
    if (val == 1) {
        rem[dep[x]][c[x] - 'a' + 1] ^= 1;  // 因为只是判断奇偶，所以用异或代替加法取余数
        if (rem[dep[x]][c[x] - 'a' + 1])   // 说明是偶数变成了奇数
            oddnumber[dep[x]]++;
        else  // 说明是奇数变成了偶数
            oddnumber[dep[x]]--;
    } else {
        rem[dep[x]][c[x] - 'a' + 1] ^= 1;
        if (rem[dep[x]][c[x] - 'a' + 1])  // 说明是偶数变成了奇数
            oddnumber[dep[x]]++;
        else  // 说明是奇数变成了偶数
            oddnumber[dep[x]]--;
    }
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa || y == hh) continue;
        calc(y, x, val);
    }
}

void dsu(int x, int fa, bool op) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa || y == son[x]) continue;
        dsu(y, x, 0);
    }
    if (son[x]) {
        dsu(son[x], x, 1);
        hh = son[x];
    }
    calc(x, fa, 1);
    hh = 0;
    if (q[x].size()) {
        for (auto i : q[x]) {
            // std::cout << x << " " << fa << " " << oddnumber << " " << i.second << std::endl;
            ans[i.second] = (oddnumber[i.first] <= 1 ? 1 : 0);
        }
    }
    if (!op) {
        calc(x, fa, 0);
    }
}

int main() {
    // freopen("/Users/chenjiayou/Desktop/2024暑假训练/DsuOnTree/okok.in", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int a;
        std::cin >> a;
        add(i, a), add(a, i);
    }
    std::cin >> c, c = ' ' + c;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        q[a].push_back(std::make_pair(b, i));
    }
    dep[1] = 1;
    dfs(1, 0);
    // for (int i = 1; i <= n; i++) {
    //     std::cout << i << ": " << sz[i] << " " << son[i] << " " << dep[i] << std::endl;
    // }
    dsu(1, 0, 0);
    for (int i = 1; i <= m; i++) {
        std::cout << (ans[i] ? "Yes" : "No") << " \n"[i == m];
    }
    return 0;
}