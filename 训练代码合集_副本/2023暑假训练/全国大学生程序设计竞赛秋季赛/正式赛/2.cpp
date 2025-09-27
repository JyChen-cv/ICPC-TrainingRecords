#include <bits/stdc++.h>
using namespace std;
#define re register
#define in inline
#define ll long long
#define get getchar()
in int read() {
    int t = 0;
    char ch = get;
    while (ch < '0' || ch > '9') ch = get;
    while (ch <= '9' && ch >= '0') t = t * 10 + ch - '0', ch = get;
    return t;
}
const int _ = 5e5 + 23;
int n, m, tot, h[_], col[_];
struct edge {
    int to, ne;
} e[_];
in void add(int x, int y) { e[++tot].ne = h[x], e[tot].to = y, h[x] = tot; }
in void dfs(int x, int num) {
    col[x] = num;
    for (re int i = h[x]; i; i = e[i].ne) {
        int v = e[i].to;
        if (col[v]) continue;
        dfs(v, num);
    }
}
int fa[_], sz[_];
in int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
struct yzx {
    int a, b;
} d[_];
in int cmp(yzx x, yzx y) { return x.a == y.a ? x.b < y.b : x.a < y.a; }
int main() {
    n = read(), m = read();
    for (re int i = 1; i <= m; ++i) {
        int a = read(), b = read();
        add(a, b), add(b, a);
    }
    int num = 0;
    for (re int i = 1; i <= n; ++i) {
        fa[i] = i;
        if (!col[i]) dfs(i, ++num);
    }
    int k = read();
    for (re int i = 1; i <= k; ++i) {
        int x = read(), y = read();
        int fx = getfa(x), fy = getfa(y);
        if (fx == fy) continue;
        if (fx > fy) swap(fx, fy);
        fa[fy] = fx;
    }
    int mx = 0, mn = 2 * n;
    for (re int i = 1; i <= n; ++i) {
        getfa(i);
        d[i].a = fa[i], d[i].b = col[i];
    }
    sort(d + 1, d + n + 1, cmp);
    int A = 0, B = 0, sz = 0;
    for (re int i = 1; i <= n; ++i) {
        if (A != d[i].a || B != d[i].b) {
            if (sz) mx = max(mx, sz), mn = min(sz, mn);
            sz = 1, A = d[i].a, B = d[i].b;
            continue;
        }
        sz++;
    }
    if (sz) mx = max(mx, sz), mn = min(sz, mn);
    cout << mx << ' ' << mn << endl;
}