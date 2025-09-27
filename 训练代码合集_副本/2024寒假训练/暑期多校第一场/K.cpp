#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

#define int long long
#define x first
#define y second
const int N = 2e5, M = 2e5;
int nxt[M * 2 + 2], head[N + 2], ver[M * 2 + 2], tot;
int d[N + 2], son[N + 2], tag[M * 2 + 2], num[M * 2 + 2], du[N + 2];
std::pair<int, int> mapp[M + 2];

void add(int x, int y, int i) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    num[tot] = i;
    du[y]++;
}

void bfs(int p) {
    std::queue<int> q;
    q.push(p);
    d[p] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            if (d[y]) continue;
            d[y] = d[x] + 1;
            tag[num[i]] = 1;
            son[x] = 1;
            q.push(y);
        }
    }
}

signed main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b, i);
        add(b, a, i);
        mapp[i] = std::make_pair(a, b);
    }

    bfs(1);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (d[mapp[i].x] > d[mapp[i].y]) std::swap(mapp[i].x, mapp[i].y);
        if (tag[i]) {
            if (d[mapp[i].y] - 1 <= k) {
                ans++;
                if (du[mapp[i].y] == 1) ans += k + 1 - d[mapp[i].y];
            }
        } else {
            if (d[mapp[i].x] == 0 || d[mapp[i].y] == 0) continue;
            if (d[mapp[i].x] - 1 <= k) ans += k + 1 - d[mapp[i].x];
            if (d[mapp[i].y] - 1 <= k) ans += k + 1 - d[mapp[i].y];
            // std::cout << i << " " << ans << std::endl;
        }
    }
    std::cout << ans + 1 << std::endl;
    return 0;
}

/*
5 10 2
1 2 1 3 1 4 1 5
2 3 2 4 2 5
3 4 3 5
4 5
*/