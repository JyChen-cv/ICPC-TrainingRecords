#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 6e5;
int head[N + 2], tot, ver[N + 2], edge[N + 2], w[N + 2], nxt[N + 2], ans[N + 2], du[N + 2];
std::vector<int> son[N + 2];

int read() {
    int t = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch <= '9' && ch >= '0') t = t * 10 + ch - '0', ch = getchar();
    return t;
}

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    du[y]++, du[x]++;
}

void dfs(int x) {
    // std::cout << x << std::endl;
    if (du[x] == 1 && x != 1) {  // 别干这种傻事，每一个特判都想想会不会把特殊情况搞错
        if (w[x])
            ans[x] = 0;
        return;
    }
    int sum = 0;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        // if (y == fa) continue;
        // std::cout << x << " " << y << std::endl;
        dfs(y);
        sum += ans[y];
    }
    for (int i = 0; i < (int)son[x].size(); i++) {
        int y = son[x][i];
        ans[x] = std::min(ans[x], ans[y] + 1);
    }
    ans[x] = std::min(ans[x], sum);
}

signed main() {
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // std::cout.tie(0);
    int t = read();
    while (t--) {
        int n = read(), m = read(), k = read();
        for (int i = 1; i <= tot; i++) {
            edge[i] = 0;
            ver[i] = nxt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            head[i] = 0;
            ans[i] = 1e9;
            w[i] = 0;
            du[i] = 0;
            son[i].clear();
        }
        tot = 0;
        for (int i = 1; i <= n; i++) {
            int num;
            num = read();
            for (int j = 1; j <= num; j++) {
                int a;
                a = read();
                // std::cout << i << " " << a << std::endl;
                add(i, a);
            }
        }
        for (int i = 1; i <= m; i++) {
            int a = read(), b = read();
            son[a].push_back(b);
            son[b].push_back(a);
        }
        for (int i = 1; i <= k; i++) {
            int a;
            std::cin >> a;
            w[a] = 1;
        }

        dfs(1);
        // for (int i = 1; i <= n; i++) {
        //     std::cout << ans[i] << " ";
        // }
        std::cout << (ans[1] > n ? (-1) : ans[1]) << std::endl;
    }
    return 0;
}

/*
1
16 7 6
2 2 3
2 4 5
2 6 7
4 8 9 10 11
1 16
2 12 13
2 14 15
0
0
0
0
0
0
0
0
0
1 2
1 3
2 4
4 9
4 10
7 14
6 12
8 9 10 12 14 16

2
16 7 6
2 2 3
2 4 5
2 6 7
4 8 9 10 11
1 16
2 12 13
2 14 15
0
0
0
0
0
0
0
0
0
1 2
1 3
2 4
4 9
4 10
7 14
6 12
8 9 10 12 14 16
15 5 5
2 2 3
2 4 5
2 6 7
4 8 9 10 11
0
2 12 13
2 14 15
0
0
0
0
0
0
0
0
2 4
4 9
4 10
7 14
6 12
8 9 10 12 14
*/