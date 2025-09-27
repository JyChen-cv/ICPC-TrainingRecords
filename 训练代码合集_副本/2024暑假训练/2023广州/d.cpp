#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second - a.first > b.second - b.first;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    int deal = m - n;
    int ans = 0;
    std::vector<std::pair<int, int> > q, rem;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        rem.push_back({a, b});
        if (a >= b)
            ans += a;
        else {
            q.push_back({a, b});
            ans += a;
        }
    }
    if (n == 1) {
        std::cout << rem[0].second << std::endl;
        return;
    }
    std::sort(q.begin(), q.end(), cmp);
    deal = std::min((int)q.size(), deal);
    if (deal == n - 1) {
        deal--;
        for (int i = 0; i < deal; i++) {
            ans += q[i].second - q[i].first;
        }
        int ls = 0;
        for (int i = 0; i < n; i++) {
            ls += rem[i].second;
        }
        ans = std::max(ans, ls);
    } else
        for (int i = 0; i < deal; i++) {
            // std::cout << q[i].first << " " << q[i].second << std::endl;
            ans += q[i].second - q[i].first;
        }
    std::cout << ans << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int times;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}