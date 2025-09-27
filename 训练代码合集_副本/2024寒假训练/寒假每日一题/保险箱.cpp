#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
int mapp[N + 2], tag[N + 2], dp[N + 2][3];
int min(int a1, int a2, int a3) {
    return std::min(std::min(a1, a2), a3);
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        std::cin >> c;
        mapp[i] = c - '0';
        // std::cout << mapp[i];
    }
    for (int i = 1; i <= n; i++) {
        char c;
        std::cin >> c;
        tag[i] = c - '0';
        // std::cout << tag[i];
    }
    dp[n][0] = std::abs(mapp[n] - tag[n]);
    dp[n][1] = -(-10 + mapp[n] - tag[n]);
    dp[n][2] = mapp[n] - tag[n] + 10;
    for (int i = n - 1; i >= 1; i--) {
        dp[i][2] = min(dp[i + 1][0] + std::abs(mapp[i] - tag[i] + 10), dp[i + 1][1] + std::abs(mapp[i] + 1 - tag[i] + 10), dp[i + 1][2] + std::abs(mapp[i] - 1 - tag[i] + 10));
        dp[i][1] = min(dp[i + 1][0] + std::abs(tag[i] - mapp[i] + 10), dp[i + 1][1] + std::abs(tag[i] - (mapp[i] + 1) + 10), dp[i + 1][2] + std::abs(tag[i] - (mapp[i] - 1) + 10));
        dp[i][0] = min(dp[i + 1][0] + std::abs(tag[i] - mapp[i]), dp[i + 1][1] + std::abs(mapp[i] + 1 - tag[i]), dp[i + 1][2] + std::abs(mapp[i] - 1 - tag[i]));
    }
    std::cout << min(dp[1][0], dp[1][1], dp[1][2]) << std::endl;
    return 0;
}