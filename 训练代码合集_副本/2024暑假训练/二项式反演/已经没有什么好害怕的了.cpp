#include <algorithm>
#include <cstdio>
#include <iostream>

#define int long long
const int mod = 1e9 + 9;
const int N = 1e6;
int p[N + 2], inp[N + 2], g[N + 2], a[N + 2], b[N + 2], small[N + 2];
int dp[2005][2005];

inline int q_pow(int x, int y) {
    if (y == 0) return 1;
    int mid = q_pow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}
inline int inv(int x) {
    return q_pow(x, mod - 2);
}
inline int C(int x, int y) {
    return p[x] * inp[y] % mod * inp[x - y] % mod;
}

signed main() {
    p[0] = 1;
    for (int i = 1; i <= 1e6; i++) {
        p[i] = p[i - 1] * i % mod;
    }
    inp[(int)1e6] = inv(p[(int)1e6]);
    for (int i = 999999; i >= 0; i--) {
        inp[i] = inp[i + 1] * (i + 1) % mod;
    }

    int n, m, k;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> b[i];
    if ((m + n) % 2) {
        std::cout << 0 << std::endl;
        return 0;
    }

    k = (m + n) >> 1;
    std::sort(a + 1, a + n + 1), std::sort(b + 1, b + n + 1);
    for (int i = 1, j = 0; i <= n; i++) {
        while (b[j + 1] < a[i] && j + 1 <= n) j++;
        small[i] = j;
    }
    // for (int i = 1; i <= n; i++) std::cout << small[i] << " \n"[i == n];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (small[i] - j + 1) % mod) % mod;
            // std::cout << dp[i][j] << " ";
        }
        // std::cout << std::endl;
    }
    // std::cout << dp[n][k] << std::endl;
    for (int i = 0; i <= n; i++) {
        g[i] = p[n - i] * dp[n][i] % mod;
    }
    int ans = 0;
    for (int i = k; i <= n; i++) {
        if ((i - k) % 2 == 0) {
            ans += C(i, k) * g[i] % mod;
        } else {
            ans += C(i, k) * g[i] % mod * (mod - 1) % mod;
        }
        ans %= mod;
    }
    std::cout << ans << std::endl;
    return 0;
}