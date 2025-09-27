#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

int n, m, st;
const int N = 2e5;
int tot, nxt[N + 2], ver[N + 2], head[N + 2], edge[N + 2];
long long d[N + 2];
bool v[N + 2];
std::priority_queue<std::pair<int, long long>> q;

void add(int x, int y, long long z) {
    tot++;
    edge[tot] = z;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dijkstra(int p) {
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[p] = 0;
    q.push(std::make_pair(0, p));
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            long long z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}

int main() {
    std::cin >> n >> m >> st;
    for (int i = 1; i <= m; i++) {
        int a, b;
        long long c;
        scanf("%d%d%lld", &a, &b, &c);
        add(a, b, c);
    }
    dijkstra(st);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", d[i]);
    }
    puts("");

    return 0;
}