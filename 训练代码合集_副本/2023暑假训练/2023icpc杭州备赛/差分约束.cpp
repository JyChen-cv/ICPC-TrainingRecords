#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int N = 1e5;
int tot, ver[N + 2], head[N + 2], nxt[N + 2], edge[N + 2];
int v[N + 2], d[N + 2], cnt[N + 2];
int n, m;

void add(int x, int y, int z) {
    tot++;
    ver[tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

int spfa() {
    std::queue<int> q;
    v[0] = 1;
    q.push(0);
    memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    while (q.size()) {
        int x = q.front();
        v[x] = 0;
        q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            int z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= n + 1) return 0;  // 这里一定要注意，有虚根0后，总个数是n+1个点
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
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(b, a, c);
        add(0, i, 0);  // 构建一个以0为根结点的虚根
    }
    int tag = spfa();
    if (tag) {
        for (int i = 1; i <= n; i++) {
            std::cout << d[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}