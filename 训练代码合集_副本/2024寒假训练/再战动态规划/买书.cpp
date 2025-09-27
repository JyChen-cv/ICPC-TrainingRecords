#include <cstdio>
#include <iostream>

const int N = 1000;
const int mapp[5] = {0, 10, 20, 50, 100};
int dp[N + 2];

int main() {
    int n;
    std::cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= mapp[i]) dp[j] += dp[j - mapp[i]];
        }
    }
    std::cout << dp[n] << std::endl;
    return 0;
}