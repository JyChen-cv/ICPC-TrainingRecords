#include <algorithm>
#include <cstdio>
#include <iostream>

#define int long long
const int N = 1e5, mod = 1e9 + 7;
int cnt[N + 2], dp[N + 2];

inline int q_pow(int x, int y) {
    if (y == 0) return 1;
    int mid = q_pow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}

signed main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        cnt[a]++;
    }
    for (int i = 1e5; i >= 1; i--) {
        int sum = cnt[i], sub = 0;
        for (int j = 2; j * i <= 1e5; j++) {
            sum += cnt[j * i];
            (sub += dp[j * i]) %= mod;
        }
        dp[i] = (q_pow(2, sum) + (mod - 1)) % mod;
        dp[i] = (dp[i] + mod - sub) % mod;
    }
    std::cout << dp[1] << std::endl;
    return 0;
}