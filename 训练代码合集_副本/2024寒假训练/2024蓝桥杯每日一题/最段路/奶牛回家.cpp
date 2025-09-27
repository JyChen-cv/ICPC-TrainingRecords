#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 1e4;
int edge[N + 2], head[N + 2], ver[N + 2], nxt[N + 2], tot;
int d[N + 2], v[N + 2], vv[60];

int deal(char c) {
    if (c <= 'z' && c >= 'a')
        return c - 'a' + 1;
    else
        return c - 'A' + 27;
}

void add(int x, int y, int z) {
    tot++;
    ver[tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

void Dijkstra(int p) {
    std::priority_queue<std::pair<int, int>> q;
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
            int z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        char a, b;
        int d, e, f;
        std::cin >> a >> b >> d;
        e = deal(a), f = deal(b);
        // std::cout << e << " " << f << std::endl;
        vv[e] = 1;
        vv[f] = 1;
        add(e, f, d), add(f, e, d);
    }
    Dijkstra(deal('Z'));
    int ans = 1e9;
    char anss = 0;
    for (int i = 1; i <= 25; i++) {
        int ls = deal((char)('A' + i - 1));
        // std::cout << d[ls] << std::endl;
        if (vv[ls] && d[ls] < ans) {
            ans = d[ls];
            anss = 'A' + i - 1;
        }
    }
    std::cout << anss << " " << ans << std::endl;
    return 0;
}