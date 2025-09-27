// 好巧妙的代码
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 5e4;
int head[1002], nxt[N + 2], ver[N + 2], tot;
int visit[1002], match[1002];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

bool dfs(int x) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (visit[y]) continue;
        visit[y] = 1;
        if (!match[y] || dfs(match[y])) {
            match[y] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int a, b;
        std::cin >> a >> b;
        b += n;
        add(a, b);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(visit, 0, sizeof visit);
        if (dfs(i)) ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}