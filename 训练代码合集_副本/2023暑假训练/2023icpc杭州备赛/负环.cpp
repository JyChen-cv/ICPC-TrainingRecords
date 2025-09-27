#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int N = 3e3;
int nxt[N * 2 + 2], tot, head[N + 2], ver[N * 2 + 2], edge[N * 2 + 2], v[N + 2];
int n, m, cnt[N + 2];
long long d[N + 2];

void add(int x, int y, long long z) {
    tot++;
    ver[tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

int spfa(int p) {
    v[p] = 1;
    d[p] = 0;
    std::queue<int> q;
    q.push(p);
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = 0;
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            long long z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= n) return 0;
                if (!v[y]) {
                    q.push(y);
                    v[y] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            tot = 0;
            head[i] = 0;
            v[i] = 0;
            cnt[i] = 0;
            d[i] = (long long)1e15;
        }
        for (int i = 1; i <= m; i++) {
            int a, b;
            long long c;
            scanf("%d%d%lld", &a, &b, &c);
            if (c >= 0)
                add(a, b, c), add(b, a, c);
            else
                add(a, b, c);
        }

        std::cout << (spfa(1) ? "NO" : "YES") << std::endl;
    }
    return 0;
}