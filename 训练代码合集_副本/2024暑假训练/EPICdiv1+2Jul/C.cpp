#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 1e5;
int mapp[N + 2], dp[N + 2];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    dp[n] = mapp[n];
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = std::max(dp[i + 1] + 1, mapp[i]);
    }
    std::cout << dp[1] << std::endl;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}