#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

typedef long long ll;
const int N = 10000;
int head[N + 2], nxt[N + 2], ver[N + 2], tot;
ll edge[N + 2];

void add(int x, int y, ll z) {
    tot++;
    ver[tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

int main() {
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        int a, b;
        ll c;
        add(b, a, c);
    }

    for (int i = 1; i <= m2; i++) {
        add()
    }

    return 0;
}