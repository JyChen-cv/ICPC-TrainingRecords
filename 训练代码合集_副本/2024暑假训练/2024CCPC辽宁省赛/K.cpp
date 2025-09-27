#include <algorithm>
#include <bitset>
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

const int N = 5e3, F = 5e5 + 5;
struct group {
    int l, r;
    std::vector<int> p;
} sgt[N * 4 + 2];
std::vector<int> op, ans;
std::vector<PII> itv;
std::map<int, std::vector<int>> mp;

void build(int u, int l, int r) {
    if (l == r) {
        sgt[u] = {l, r};  // 修改3
        return;
    }
    sgt[u] = {l, r};
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void deal(int u, int x, int l, int r) {
    if (sgt[u].l >= l && sgt[u].r <= r) {
        sgt[u].p.push_back(x);
        return;
    }
    int mid = (sgt[u].l + sgt[u].r) >> 1;
    if (l <= mid) deal(u << 1, x, l, r);
    if (r > mid) deal(u << 1 | 1, x, l, r);
}

void dfs(int u, std::bitset<F> d) {
    for (auto i : sgt[u].p) {
        d |= (d << i);
    }
    if (sgt[u].l == sgt[u].r) {
        ans.push_back(d.count() - 1);  // 去掉0
        return;
    }
    dfs(u << 1, d), dfs(u << 1 | 1, d);
}

void solve() {
    int n;
    mp.clear(), op.clear(), itv.clear(), ans.clear();
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int o, x;
        std::cin >> o >> x;
        if (o == 1) {
            op.push_back(x);
            mp[x].push_back(op.size() - 1);
            itv.push_back({i, n});
        } else {
            itv[mp[x].back()].second = i - 1;
            mp[x].pop_back();
        }
    }
    build(1, 1, n);
    for (int i = 0; i < (int)op.size(); i++) {
        deal(1, op[i], itv[i].first, itv[i].second);
    }
    std::bitset<F> ini;
    ini[0] = 1;
    dfs(1, ini);
    for (auto i : ans) std::cout << i << std::endl;
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

/*
4
1 100
1 999
1 10
2 100

7
1 1
1 2
1 1
1 4
1 5
2 1
2 4

*/