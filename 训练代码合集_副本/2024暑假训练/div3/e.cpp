#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
void solve() {
    std::string a;
    std::cin >> a;
    int n = 0, m = a.size();
    for (auto i : a) n *= 10, n += i - '0';
    for (int i = 1; i <= 7; i++) {
        a = a + a;
    }
    std::vector<std::pair<int, int> > ans;
    for (int i = 1; i <= 7; i++) {
        int ls = 0;
        for (int j = 0; j < i; j++) ls *= 10, ls += a[j] - '0';
        // std::cout << ls << std::endl;
        for (int j = 1; j <= 10000; j++) {
            int b = j * n - ls;
            if (b <= 0 || b > 10000) continue;
            if (j * m - b == i) {
                ans.push_back({j, b});
            }
        }
    }
    std::cout << ans.size() << std::endl;
    for (auto i : ans) {
        std::cout << i.first << " " << i.second << std::endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}