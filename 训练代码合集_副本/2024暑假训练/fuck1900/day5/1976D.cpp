// https://codeforces.com/problemset/problem/1976/D

// 数形结合明显更简单
// 感觉应该有更快的方法，但是确实想不到了,st表可以单log
// 条件1: 反转的数列必须是偶数长度 cnt值是偶数
// 条件2: 考虑倒序cnt的最小值不会小于cnt[i]

// 最后感觉有好多性质没有用到，标程是O(n)的
// 有一个显然的性质是pre和nxt数组显然是错了一个位
// 还有check那里的二倍其实是一个式子的转换，推出来后感觉太不直观了，甚至想不明白转化后怎么解释。。。但是确实是对的

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

const int N = 4e5;
int pre[N + 2], nxt[N + 2];
std::map<int, int> cnt;

const int NN = 5e5;
struct group {
    int l, r;
    int mn;  // 修改1
} sgt[NN * 4 + 2];
int mapp[NN + 2];
void pushup(group &u, group &l, group &r) {
    // 修改2
    u.mn = std::min(l.mn, r.mn);
}
void pushup(int u) {
    pushup(sgt[u], sgt[u << 1], sgt[u << 1 | 1]);
}
void build(int u, int l, int r) {
    if (l == r) {
        sgt[u] = {l, r, nxt[l]};  // 修改3
        return;
    }
    sgt[u] = {l, r};
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int v) {  // 直接覆盖
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

inline bool check(int x, int i) {
    return 2 * pre[i] - query(1, x, i).mn <= 0;
}

int count = 0;
void solve() {
    count++;
    std::string a;
    cnt.clear();
    std::cin >> a;
    // if (count == 192) std::cout << a << std::endl;
    // if (count > 5) return ;
    int n = a.length();
    for (int i = 0; i <= n + 1; i++) pre[i] = nxt[i] = 0;
    a = '0' + a;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (a[i] == '(')
            pre[i]--;
        else
            pre[i]++;
    }
    for (int i = n; i >= 1; i--) {
        nxt[i] = nxt[i + 1];
        if (a[i] == '(')
            nxt[i]++;
        else
            nxt[i]--;
    }

    // for (int i = 1; i <= n; i++) {
    // 	std::cout << pre[i] << " " << nxt[i] << std::endl;
    // }

    build(1, 1, n);
    std::vector<int> que[n + 1];

    struct group {
        int l, r, as;
    };
    std::vector<group> ans;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, i))
                r = mid;
            else
                l = mid + 1;
        }
        // std::cout << query(1, l, i).mn << std::endl;
        // std::cout << l << " " << i << std::endl;
        if (l == i) continue;
        ans.push_back((group){l, i, 0});  // 预留一个位置
        que[l].push_back(ans.size() - 1);
        que[i].push_back(ans.size() - 1);  // 最多有n个问题
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (auto j : que[i]) {
            ans[j].as = cnt[pre[ans[j].r]] - ans[j].as;
            // if (ans[j]) std::cout << ans[j] << " ?" << i << std::endl;
        }
        cnt[pre[i]]++;
    }
    for (int i = 0; i < (int)ans.size(); i++) result += ans[i].as;
    std::cout << result << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}