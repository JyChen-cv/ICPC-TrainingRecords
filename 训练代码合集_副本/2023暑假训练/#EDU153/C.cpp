#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 3e5;
int mapp[N + 2], n;
struct node {
    int l, r;
    int v;
} setr[N * 4 + 2];
void pushup(int u) {
    setr[u].v = std::max(setr[u << 1].v, setr[u << 1 | 1].v);
}
int query(int u, int l, int r) {
    if (l <= setr[u].l && r >= setr[u].r) return setr[u].v;
    int mid = (setr[u].l + setr[u].r) / 2;
    int v = 0;
    if (l <= mid) v = query(u << 1, l, r);
    if (r > mid) v = std::max(v, query(u << 1 | 1, l, r));
    return v;
}
void modify(int u, int x, int v) {
    if (setr[u].l == x && setr[u].r == x) {
        setr[u].v = v;
    } else {
        int mid = (setr[u].l + setr[u].r) / 2;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}
void build(int u, int l, int r) {
    setr[u] = {l, r};
    if (l == r) return;
    int mid = (l + r) / 2;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            mapp[i] = 0;
        }
        build(1, 1, n);
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int ls = query(1, 1, mapp[i]);
            modify(1, mapp[i], ls + 1);
            if (ls == 1) ans++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}