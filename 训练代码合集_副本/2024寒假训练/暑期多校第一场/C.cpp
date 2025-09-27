#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
struct node {
    int l, r;
    double min, add;
} setr[N * 4 + 2];
double mapp[N + 2];
int n, m;
double k;

void pushup(node &u, node &l, node &r) {
    u.min = std::min(l.min, r.min);
}
void pushup(int u) {
    if (setr[u].l == setr[u].r) return;
    pushup(setr[u], setr[u << 1], setr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) {
        setr[u] = {l, r, 0, 0};
    } else {
        setr[u] = (node) { l, r, 0, 0 }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void eva(node &u, double x) {
    if (x > 0)
        u.min += x / k, u.add += x / k;
    else
        u.min += x, u.add += x;
}

void pushdown(node &u, node &l, node &r) {
    // 注意：本层的一定是计算完成的
    eva(l, u.add);
    eva(r, u.add);
    u.add = 0;
}
void pushdown(int u) {
    if (setr[u].l == setr[u].r) return;
    pushdown(setr[u], setr[u << 1], setr[u << 1 | 1]);
}

void modify(int u, int l, int r, double x) {
    if (setr[u].l >= l && setr[u].r <= r) {
        eva(setr[u], x);
    } else {
        pushdown(u);
        int mid = (setr[u].l + setr[u].r) >> 1;
    }
}

int main() {
    std::cin >> n >> m >> k;

    return 0;
}