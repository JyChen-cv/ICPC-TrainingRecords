#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
int n, tot, ver[N * 2 + 2], head[N + 2], nxt[N * 2 + 2];
int dep[N + 2], tag[N + 2], nr[N + 2], dep2[N + 2], fars[N + 2];
int bit_q[N + 2], bit_h[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

int dfs(int x, int fa, int dp) {
    dep[x] = dp;
    int ms = x;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        int ls = dfs(y, x, dp + 1);
        if (dep[ms] < dep[ls]) ms = ls;
    }
    return ms;
}

int dfs2(int x, int tg, int fa) {
    if (x == tg) return tag[x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        if (dfs2(y, tg, x)) {
            tag[x] = 1;
            return 1;
        }
    }
    return 0;
}

void dfss(int x, int fa, int dp, int ner) {
    dep[x] = dp;
    nr[x] = ner;
    fars[ner] = std::max(fars[ner], dp);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dfss(y, x, (!tag[y] && tag[x]) ? 1 : dp + 1, (!tag[y] && tag[x]) ? x : ner);
    }
}

void dfss2(int x, int tg, int fa) {
    dep2[x] = dep2[fa] + 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa || !tag[y]) continue;
        dfss2(y, tg, x);
    }
}

inline int lowbit(int x) {
    return x & (-x);
}

void update_q(int x, int y) {
    while (x <= n) {
        bit_q[x] = std::max(bit_q[x], y);
        x += lowbit(x);
    }
}

void update_h(int x, int y) {
    while (x <= n) {
        bit_h[x] = std::max(bit_h[x], y);
        x += lowbit(x);
    }
}

int query_q(int x, int y) {
    if (y - lowbit(y) + 1 >= x)
        return std::max(bit_q[y], query_q(x, y - lowbit(y)));
    else
        return dep[x] + fars[y];
}

int query_h(int x, int y) {
    if (y - lowbit(y) + 1 >= x)
        return std::max(bit_h[y], query_h(x, y - lowbit(y)));
    else
        return dep2[x] + fars[y];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    int root = dfs(1, 0, 1);
    int end = dfs(root, 0, 1);
    dfs2(root, end, 0);
    dfss(root, 0, 1, root);
    dfss2(end, root, 0);
    for (int i = 1; i <= n; i++) {
        if (i == root)
            update_q(dep[i], dep[i]);
        else if (tag[i])
            update_q(dep[i], dep[i] + fars[i]);
        if (i == end)
            update_h(dep2[i], dep2[i]);
        else if (tag[i])
            update_h(dep2[i], dep2[i] + fars[i]);
    }
    // std::cout << root << " " << end << std::endl;
    // for (int i = 1; i <= n; i++) {
    //     std::cout << tag[i] << " " << dep[i] << " " << nr[i] << " " << dep2[i] << " " << fars[i] << std::endl;
    // }

    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b;
        int ans = 0;
        scanf("%d%d", &a, &b);
        ans = std::max(ans, std::min(dep[tag[a] ? a : nr[a]] - dep[root] + dep[a] * (!tag[a]), dep[tag[b] ? b : nr[b]] - dep[root]) + dep[b] * (!tag[b]));
        ans = std::max(ans, std::min(dep[end] - dep[tag[a] ? a : nr[a]] + dep[a] * (!tag[a]), dep[end] - dep[tag[b] ? b : nr[b]]) + dep[b] * (!tag[b]));
        int len = (tag[a] ? 0 : dep[a]) + (tag[b] ? 0 : dep[b]);
        a = tag[a] ? a : nr[a];
        b = tag[b] ? b : nr[b];
        len += std::abs(dep[a] - dep[b]);
        ans = std::max(ans, len / 2);
        printf("%d\n", ans);
    }
    return 0;
}