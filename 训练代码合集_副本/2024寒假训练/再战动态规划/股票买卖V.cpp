#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
int mapp[N + 2], dp[N + 2][3];
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }

    dp[0][0] = dp[0][1] = -1e9;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] + mapp[i];
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][2] - mapp[i]);
        dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][2]);
    }

    int ans = std::max(dp[n][0], dp[n][2]);
    std::cout << ans << std::endl;
    return 0;
}