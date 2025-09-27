#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1000002, M = 1000002;
int ver[N * 2 + 2], head[N + 2], nxt[N * 2 + 2];
int tot, root[N + 2], total, n, m, mapp[N + 2];
struct group {  // 用来把操作离线
    int x, y, z;
} op[M + 2];
struct node {
    int l_s, r_s;  // 左右儿子
    int dat;
    long long num;  // 最大值 物品类型
} setr[N * 4];
long long ans[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

int build() {
    total++;
    setr[total] = {0, 0, 0, 0};
    return total;
}

void pushup(node &u, node &l, node &r) {
    if (l.dat > r.dat) {
        u.dat = l.dat;
        u.num = l.num;
    } else if (l.dat == r.dat) {
        u.dat = l.dat;
        u.num = l.num + r.num;
    } else {
        u.dat = r.dat;
        u.num = r.num;
    }
}
void pushup(int u) {
    // 用左右儿子向上计算
    pushup(setr[u], setr[setr[u].l_s], setr[setr[u].r_s]);
}

void modify(int u, int l, int r, int val, int delta) {
    if (l == r) {  // 若找到一个点，就更改
        setr[u].dat += delta;
        setr[u].num = val;  // 该点的最大值一定来自自己
        return;
    }
    int mid = (l + r) >> 1;
    if (val <= mid) {
        if (!setr[u].l_s) setr[u].l_s = build();  // 动态开点
        modify(setr[u].l_s, l, mid, val, delta);
    } else {
        if (!setr[u].r_s) setr[u].r_s = build();
        modify(setr[u].r_s, mid + 1, r, val, delta);
    }
    pushup(u);
}

int merge(int p, int q, int l, int r) {
    // std::cout << p << " " << q << " " << l << " " << r << std::endl;
    if (!p) return q;
    if (!q) return p;
    if (l == r) {
        setr[p].dat += setr[q].dat;
        return p;
    }
    int mid = (l + r) >> 1;
    setr[p].l_s = merge(setr[p].l_s, setr[q].l_s, l, mid);
    setr[p].r_s = merge(setr[p].r_s, setr[q].r_s, mid + 1, r);
    pushup(p);
    // ans[p] = setr[p].num;
    return p;
}

void deal(int x, int fa) {
    // std::cout << x << std::endl;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        deal(y, x);
        merge(root[x], root[y], 1, n);  // 把y树加到x树上去

        // std::cout << setr[root[x]].dat << " " << setr[root[x]].num << std::endl;
    }
    ans[x] = setr[root[x]].num;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    // 动态开点
    for (int i = 1; i <= n; i++) root[i] = build();  // root[i]=i
    for (int i = 1; i <= n; i++) {
        modify(root[i], 1, n, mapp[i], 1);
        // std::cout << setr[root[i]].dat << " " << setr[root[i]].num << std::endl;
    }
    // 线段树合并
    deal(1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    std::cout << std::endl;
    return 0;
}