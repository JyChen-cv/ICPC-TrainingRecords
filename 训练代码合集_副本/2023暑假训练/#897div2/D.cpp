#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e5;
int head[N + 2], nxt[N + 2], ver[N + 2], tot, dep[N + 2], tag[N + 2];
int n, k, q;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (i == (fa ^ 1)) {
            continue;
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        tot = 1;
        q = 1;
        for (int i = 1; i <= tot; i++) {
            nxt[i] = ver[i] = 0;
        }

        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            head[i] = dep[i] = tag[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            add(i, a);
        }

        for (int i = 1; i <= n; i++) {
        }
    }
    return 0;
}