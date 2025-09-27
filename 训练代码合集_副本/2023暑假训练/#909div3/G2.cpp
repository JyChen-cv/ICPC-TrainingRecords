#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 1e5;
int n, m, ver[N * 2 + 2], head[N + 2], nxt[N * 2 + 2], tot, total;
int mapp[N + 2], dfn[N + 2], size[N + 2], tim, root[N + 2];
struct node {
    // 这里存的是左右儿子的编号，不是区间的左右端点
    int lc, rc;
    int cnt;
} setr[N * 20 + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    dfn[x] = ++tim;
    size[x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (fa == y) continue;
        dfs(y, x);
        size[x] += size[y];
    }
}

int insert(int now, int l, int r, int x) {
    // std::cout << now << " " << l << " " << r << " " << x << std::endl;
    int p = ++total;
    setr[p] = setr[now];
    if (l == r) {
        setr[p].cnt = 1;
        return p;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        setr[p].lc = insert(setr[now].lc, l, mid, x);
    else
        setr[p].rc = insert(setr[now].rc, mid + 1, r, x);
    setr[p].cnt = setr[setr[p].lc].cnt + setr[setr[p].rc].cnt;
    return p;
}

// int ask(int p, int q, int l, int r, int k) {
//     if (l == r) return l;
//     int mid = (l + r) >> 1;
//     int lcnt = setr[setr[p].lc].cnt - setr[setr[q].lc].cnt;
//     // cnt表示的是当前节点所包含的数字个数，这里作差是同一层但是不同版本的作差，用来求出来题目要求的[l,r]内的数字个数
//     if (k <= lcnt)
//         return ask(setr[p].lc, setr[q].lc, l, mid, k);
//     else
//         return ask(setr[p].rc, setr[q].rc, mid + 1, r, k - lcnt);
// }

int ask(int p, int q, int l, int r, int k1, int k2) {
    // std::cout << p << " " << q << " " << l << " " << r << " " << k1 << " " << k2 << std::endl;
    if (k1 <= l && r <= k2) return setr[p].cnt - setr[q].cnt;
    int mid = (l + r) >> 1;
    int res = 0;
    if (k1 <= mid) res += ask(setr[p].lc, setr[q].lc, l, mid, k1, k2);
    if (k2 > mid) res += ask(setr[p].rc, setr[q].rc, mid + 1, r, k1, k2);
    return res;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        tot = 0;
        tim = 0;
        total = 0;

        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) head[i] = 0;
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
        }
        dfs(1, 0);

        root[0] = ++total;
        // insert(0, 1, n, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
            root[i] = total + 1;
            insert(root[i - 1], 1, n, dfn[mapp[i]]);
        }
        // for (int i = 1; i <= 7; i++) {
        //     std::cout << setr[i].lc << " " << setr[i].rc << " " << setr[i].cnt << " " << std::endl;
        // }
        // for (int i = 1; i <= n; i++) {
        //     std::cout << root[i] << " " << std::endl;
        // }
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            printf("%s\n", ask(root[b], root[a - 1], 1, n, dfn[c], dfn[c] + size[c] - 1) ? "Yes" : "No");
        }
        puts("");
    }
    return 0;
}