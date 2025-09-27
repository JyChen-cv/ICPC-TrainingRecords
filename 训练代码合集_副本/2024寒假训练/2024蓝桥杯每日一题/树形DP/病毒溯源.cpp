// 没写完

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e4;
int tot, nxt[N * 2 + 2], ver[N + 2], head[N + 2];
int d1[N + 2], d2[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (fa == y) continue;
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        for (int j = 1; j <= a; j++) {
            int b;
            std::cin >> b;
            b++;
            add(i, b);
            add(b, i);
        }
    }

    dfs(1, 0);
    return 0;
}