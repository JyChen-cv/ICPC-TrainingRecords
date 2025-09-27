#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define int long long
const int N = 1e6;
struct node {
    int a, b;
    bool operator<(const node &t) const {
        int ls1 = a - b, ls2 = t.a - t.b;
        if (ls1 < ls2)
            return 1;
        else if (ls1 == ls2)
            return a < t.a;
        else
            return 0;
    }
} mapp[N + 2];
int c[N + 2];
std::vector<node> q;
std::map<int, int> val;

bool cmp(int x, int y) {
    return x > y;
}

int find(int x, int l, int r) {
    // int l = 0, r = q.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (q[mid].a <= x)
            r = mid;
        else
            l = mid + 1;
    }
    if (x >= q[l].a)
        return l;
    else
        return q.size();
}

int dfs(int x, int l, int r) {
    if (val[x]) {
        return val[x];
    }
    int ls = find(x, l, r);
    if (ls == (int)q.size()) return 0;
    int div = q[ls].a - q[ls].b;
    int res = (x - q[ls].a) / div + 1;
    return val[x] = res + dfs(x - res * div, l + 1, r);
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i].a;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i].b;
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> c[i];
    }
    std::sort(mapp + 1, mapp + n + 1);
    for (int i = 1; i <= n; i++) {
        if (q.size() == 0)
            q.push_back(mapp[i]);
        else {
            if (q[q.size() - 1].a <= mapp[i].a)
                continue;
            else
                q.push_back(mapp[i]);
        }
    }
    std::sort(c + 1, c + m + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dfs(c[i], 0, q.size() - 1);
    }
    std::cout << ans * 2 << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
