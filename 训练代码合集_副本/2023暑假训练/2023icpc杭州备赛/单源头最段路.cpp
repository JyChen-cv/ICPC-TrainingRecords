#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 5e5, M = 1e4;
int tot, nxt[N + 2], ver[N + 2], head[M + 2], edge[N + 2], d[M + 2], v[M + 2];
int n, m, st;

void add(int x, int y, int z) {
    tot++;
    ver[tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

void spfa(int p) {
    for (int i = 1; i <= n; i++) d[i] = (1 << 31) - 1;
    memset(v, 0, sizeof(v));
    d[p] = 0;
    v[p] = 1;
    std::queue<int> q;
    q.push(p);
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = 0;
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            int z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y]) {
                    q.push(y);
                    v[y] = 1;
                }
            }
        }
    }
}

int main() {
    std::cin >> n >> m >> st;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(a, b, c);
        // add(b, a, c);
    }
    spfa(st);
    for (int i = 1; i <= n; i++) {
        std::cout << d[i] << " ";
    }
    puts("");
    return 0;
}