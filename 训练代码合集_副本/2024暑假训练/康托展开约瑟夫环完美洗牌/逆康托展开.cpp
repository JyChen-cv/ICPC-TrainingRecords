// 其实康托展开的思想最妙的地方是不用把这个具体的算出来，可以在同余意义下解决该问题

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 1e5;
int a[N + 2], k[N + 2];

const int NN = 5e5;
struct group {
    int l, r;
    int tot;  // 修改1
} sgt[NN * 4 + 2];
int mapp[NN + 2];
void pushup(group &u, group &l, group &r) {
    // 修改2
    u.tot = l.tot + r.tot;
}
void pushup(int u) {
    pushup(sgt[u], sgt[u << 1], sgt[u << 1 | 1]);
}
void build(int u, int l, int r) {
    // 重复调用就是刷新！
    if (l == r) {
        sgt[u] = {l, r, 0};  // 修改3
        return;
    }
    sgt[u] = {l, r};
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int v) {
    if (sgt[u].l == x && sgt[u].r == x) {
        sgt[u] = {x, x, v};  // 修改4
        mapp[x] = v;
        return;
    }
    int mid = (sgt[u].l + sgt[u].r) >> 1;
    if (x <= mid)
        modify(u << 1, x, v);
    else
        modify(u << 1 | 1, x, v);
    pushup(u);
}
group query(int u, int l, int r) {
    if (l > r) {
        return {0, 0, 0};
    }  // 回答非法询问
    if (sgt[u].l >= l && sgt[u].r <= r) return sgt[u];
    int mid = (sgt[u].l + sgt[u].r) >> 1;
    if (r <= mid)
        return query(u << 1, l, r);
    else if (l > mid)
        return query(u << 1 | 1, l, r);
    else {
        group res, left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
        pushup(res, left, right);
        return res;
    }
}

// 线段树上二分
int find(const int &u, const int &p) {
    if (sgt[u].l == sgt[u].r) return sgt[u].l;
    auto l = sgt[u << 1], r = sgt[u << 1 | 1];
    if (l.r - l.l + 1 - l.tot >= p)
        return find(u << 1, p);
    else
        return find(u << 1 | 1, p - (l.r - l.l + 1 - l.tot));
}

void solve() {
    int n, derta;
    std::cin >> n >> derta;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        modify(1, a, 1);
        int unused = a - 1 - query(1, 1, a - 1).tot;
        k[n - i] = unused;
    }
    // 这里没有计算rank，直接转换成了坐标计算，因为没有模数，所以不好转换为rank

    // 这里是模拟一下基函数 base[i] = i! 空间内的坐标 k[i] , 进位 carry
    int carry = derta;
    k[0] = 0;
    for (int i = 1; i <= n; i++) {
        carry += k[i];
        k[i] = carry % (i + 1);
        carry /= (i + 1);  // 特别注意这里是 (i + 1)
    }

    build(1, 1, n);
    std::vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        ans.push_back(find(1, k[i] + 1));  // 找的(k[i] + 1)个0的下标
        modify(1, ans.back(), 1);
    }
    for (auto i : ans) std::cout << i << " ";
    puts("");
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    // std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}