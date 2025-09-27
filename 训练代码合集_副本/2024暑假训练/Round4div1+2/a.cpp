#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long
void solve() {
    int n, ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        if (((i - 1) % 2 == 0 || (n - i) % 2 == 0) && a > ans) ans = a;
    }
    std::cout << ans << std::endl;
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