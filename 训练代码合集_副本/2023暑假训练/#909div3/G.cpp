#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 3e4;
int mapp[N + 2], n, m, head[N + 2], tot, ver[N * 2 + 2], nxt[N * 2 + 2];
std::bitset<N + 2> ff[N + 2];
struct group {
    int l, r;
    std::bitset<N + 2> v;
} setr[N * 4 + 2];

// int lowbit(int x) {
//     return x & (-x);
// }
// void modify(int x, std::bitset<N + 2> y) {
//     while (x <= n) {
//         f[x] |= y;
//         x += lowbit(x);
//     }
// }

// bool ask(int x, int y, int z) {
//     std::bitset<N + 2> a, b;
//     // std::cout << x << " " << y << " ";
//     while (x) {
//         a |= f[x];
//         x -= lowbit(x);
//     }
//     while (y) {
//         b |= f[y];
//         y -= lowbit(y);
//     }
//     // std::cout << a << " " << b << std::endl;
//     a ^= b;
//     return a[z];
// }

void pushup(int u) {
    setr[u].v = setr[u << 1].v | setr[u << 1 | 1].v;
}
void build(int u, int l, int r) {
    setr[u].l = l;
    setr[u].r = r;
    if (l == r) {
        setr[u].v &= 0;
        setr[u].v |= ff[mapp[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

std::bitset<N + 2> query(int u, int l, int r) {
    if (l <= setr[u].l && r >= setr[u].r) return setr[u].v;
    int mid = (setr[u].l + setr[u].r) / 2;
    std::bitset<N + 2> v;
    if (l <= mid) v = query(u << 1, l, r);
    if (r > mid) v |= query(u << 1 | 1, l, r);
    return v;
}

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    // ff[x] &= 0;
    ff[x][x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        ff[y] |= ff[x];
        dfs(y, x);
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        tot = 0;
        for (int i = 1; i <= n; i++) head[i] = 0, ff[i] &= 0;
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
        }
        dfs(1, 0);
        // for (int i = 1; i <= n; i++) {
        //     std::cout << ff[i] << std::endl;
        // }
        // std::cout << std::endl;
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
        }
        build(1, 1, n);
        // for (int i = 1; i <= n; i++) {
        //     std::cout << setr[i].l << " " << setr[i].r << " " << setr[i].v << std::endl;
        // }
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            // std::cout << query(1, a, b) << std::endl;
            printf("%s\n", query(1, a, b)[c] ? "YES" : "NO");
        }
    }
    return 0;
}

/*
1
10 1
2 6
2 7
2 4
1 7
2 8
10 6
8 5
9 4
3 4
10 2 5 9 1 7 6 4 3 8
8 9 8
*/