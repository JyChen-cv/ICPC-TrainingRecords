#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
void solve() {
    int m, n;
    std::cin >> m >> n;
    int sum = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        if (a > mx) {
            sum += (mx - 1) * 2 + 1;
            mx = a;
        } else
            sum += (a - 1) * 2 + 1;
    }
    std::cout << sum + 1 << std::endl;
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