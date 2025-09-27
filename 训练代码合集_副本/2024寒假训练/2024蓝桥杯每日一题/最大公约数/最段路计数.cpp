#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#include <queue>

const int N = 2e5;
int nxt[N + 2], ver[N + 2], edge[N + 2], tot, head[N + 2];
int d[N + 2], v[N + 2], cnt[N + 2];

void add(int x, int y, int z) {
    tot++;
    ver[tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

void Dijkstra(int p) {
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    memset(cnt, 0, sizeof(cnt));
    d[p] = 0;
    std::priority_queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, p));
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            int z = edge[i];
            if (d[y] > d[x] + z) {
                cnt[]
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    Dijkstra(1);
    for (int i = 1; i <= n; i++) {
        std::cout << cnt[i] << std::endl;
    }

    return 0;
}