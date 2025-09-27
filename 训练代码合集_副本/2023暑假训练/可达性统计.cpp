#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 30000;

int ver[N + 2], nxt[N + 2], head[N + 2], tot;
int n, m, du[N + 2], q[N + 2];
std::bitset<N + 2> f[N + 2];

void add(int x, int y) {
    tot++;
    du[y]++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void topsort() {
    int hh = 1, tt = 0;
    for (int i = 1; i <= n; i++) {
        if (!du[i]) q[++tt] = i;
    }

    while (hh <= tt) {
        int x = q[hh++];
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            if (--du[y] == 0) {
                q[++tt] = y;
            }
        }
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    topsort();
    for (int i = n; i >= 1; i--) {
        int x = q[i];
        f[x][x] = 1;
        for (int j = head[x]; j; j = nxt[j]) {
            int y = ver[j];
            f[x] |= f[y];  // 更新方式有点奇怪
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%zu\n", f[i].count());
    }
    return 0;
}