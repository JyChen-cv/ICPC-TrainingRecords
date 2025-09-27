#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
const int N = 1e5;
ll mod, ver[N * 2 + 2], head[N + 2], nxt[N * 2 + 2];
ll w[N + 2], dep[N + 2], mapp[N + 2];
int tot, n, m, root, sz[N + 2], son[N + 2], id[N + 2], top[N + 2], cnt, fa[N + 2];  // sz表示子树大小,son表示重儿子的编号
struct node {
    int l, r;
    ll add, sum;
} setr[N * 4 + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs1(int x) {
    sz[x]++;
    int mason = 0;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa[x]) continue;
        dep[y] = dep[x] + 1;
        fa[y] = x;
        dfs1(y);
        if (sz[y] > mason) {
            mason = sz[y];
            son[x] = y;
        }
        sz[x] += sz[y];
    }
}

void dfs2(int x, int topf) {
    id[x] = ++cnt;
    mapp[cnt] = w[x];
    top[x] = topf;
    if (!son[x]) return;
    dfs2(son[x], topf);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa[x] || y == son[x]) continue;
        dfs2(y, y);
    }
}

void pushup(node &u, node &ls, node &rs) {
    u.sum = (ls.sum + rs.sum) % mod;
}
void pushup(int u) {
    if (setr[u].l == setr[u].r) return;  // 叶子结点直接返回
    pushup(setr[u], setr[u << 1], setr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) {
        setr[u] = {l, r, 0, mapp[l]};  // 这是线段书递归的边界条件
        return;
    }
    setr[u] = {l, r, 0, 0};
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void pushdown(node &u, node &ls, node &rs) {
    ls.sum = (ls.sum + (ls.r - ls.l + 1) * u.add % mod) % mod;
    rs.sum = (rs.sum + (rs.r - rs.l + 1) * u.add % mod) % mod;
    ls.add = (ls.add + u.add) % mod;
    rs.add = (rs.add + u.add) % mod;
    u.add = 0;
}
void pushdown(int u) {
    if (setr[u].l == setr[u].r) return;  // 要是叶子结点直接返回,因为本层一定已经计算完成了
    pushdown(setr[u], setr[u << 1], setr[u << 1 | 1]);
}

node query(int u, int l, int r) {
    if (setr[u].l >= l && setr[u].r <= r) return setr[u];
    pushdown(u);
    int mid = (setr[u].l + setr[u].r) >> 1;
    if (l > mid)
        return query(u << 1 | 1, l, r);  // 这里的是一种避免无效搜索的优化，注意边界条件的等于号放在哪里
    else if (r <= mid)
        return query(u << 1, l, r);
    else {
        node res = {0, 0, 0, 0}, left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
        pushup(res, left, right);  // pushup其实就是合并的过程
        return res;
    }
}

void modify(int u, int l, int r, ll v) {
    if (setr[u].l >= l && setr[u].r <= r) {
        setr[u].sum = (setr[u].sum + (setr[u].r - setr[u].l + 1) * v % mod) % mod;
        setr[u].add += v;  // ad表示的值对本层已经计算完成了
        setr[u].add %= mod;
        return;
    }
    pushdown(u);
    int mid = (setr[u].l + setr[u].r) >> 1;  // 这里判断修改的区间和询问哪里不太一样，注意区别
    if (l <= mid) modify(u << 1, l, r, v);
    if (r > mid) modify(u << 1 | 1, l, r, v);
    pushup(u);
}

void upd_range(int x, int y, ll z) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
        modify(1, id[top[x]], id[x], z);  // 注意id的大小
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) std::swap(x, y);
    modify(1, id[y], id[x], z);  // 注意是y在x的上面，所以id[y]一定小于id[x]
}

ll q_range(int x, int y) {
    ll res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
        res = (res + query(1, id[top[x]], id[x]).sum) % mod;
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) std::swap(x, y);
    res = (res + query(1, id[y], id[x]).sum) % mod;
    return res;
}

void upd_son(int x, ll y) {
    modify(1, id[x], id[x] + sz[x] - 1, y);
}

ll q_son(int x) {
    return query(1, id[x], id[x] + sz[x] - 1).sum;
}

int main() {
    scanf("%d%d%d%lld", &n, &m, &root, &mod);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", w + i);
        w[i] %= mod;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dep[root] = 1;
    dfs1(root);
    dfs2(root, root);
    build(1, 1, cnt);  // cnt==n
    for (int i = 1; i <= m; i++) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            int x, y;
            ll z;
            scanf("%d%d%lld", &x, &y, &z);
            z %= mod;
            upd_range(x, y, z);
        } else if (a == 2) {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", q_range(x, y));
        } else if (a == 3) {
            int x;
            ll y;
            scanf("%d%lld", &x, &y);
            y %= mod;
            upd_son(x, y);
        } else {
            int x;
            scanf("%d", &x);
            printf("%lld\n", q_son(x));
        }
    }
    return 0;
}