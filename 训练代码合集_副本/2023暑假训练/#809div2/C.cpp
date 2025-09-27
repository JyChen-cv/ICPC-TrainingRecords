#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;
const int N = 1e5;
ll mapp[N + 2], dp[N + 2][2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i][1] = 1e9;
            std::cin >> mapp[i];
        }
        if (n % 2) {
            ll ans = 0;
            for (int i = 2; i < n; i += 2) {
                ll ls = std::max(mapp[i - 1], mapp[i + 1]) + 1;
                ans += (ls > mapp[i] ? (ls - mapp[i]) : 0);
            }
            std::cout << ans << std::endl;
        } else {
            dp[2][0] = ((std::max(mapp[1], mapp[3]) + 1) > mapp[2] ? ((std::max(mapp[1], mapp[3]) + 1) - mapp[2]) : 0);
            for (int i = 3; i < n; i++) {
                ll ls = std::max(mapp[i - 1], mapp[i + 1]) + 1;
                dp[i][0] = dp[i - 2][0] + (ls > mapp[i] ? (ls - mapp[i]) : 0);
                dp[i][1] = std::min(dp[i - 2][0], std::min(dp[i - 2][1], dp[i - 3][0]) + (ls > mapp[i] ? (ls - mapp[i]) : 0));
                // std::cout << i << " " << dp[i][0] << " " << dp[i][1] << std::endl;
            }
            std::cout << std::min(std::min(dp[n - 1][0], dp[n - 2][0]), dp[n - 1][1]) << std::endl;
            // std::cout << dp[n - 1][1] << std::endl;
        }
    }
    return 0;
}