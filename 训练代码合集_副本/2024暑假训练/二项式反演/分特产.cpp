#include <cstdio>
#include <iostream>

#define int long long
const int mod = 1e9 + 7;
const int N = 1e6;
int p[N + 2], inp[N + 2], g[N + 2], a[N + 2];

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

    int n, m, sum = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    sum = p[sum];
    for (int i = 1; i <= m; i++) {
        (sum *= inp[a[i]]) %= mod;
    }
    for (int i = 0; i < n; i++) {
        g[i] = C(n, i);
        for (int j = 1; j <= m; j++) {
            g[i] = g[i] * C(a[j] + n - i - 1, a[j]) % mod;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((i - 0) % 2 == 0) {
            ans += C(i, 0) * g[i] % mod;
        } else {
            ans += C(i, 0) * g[i] % mod * (mod - 1) % mod;
        }
        ans %= mod;
    }
    std::cout << ans << std::endl;
    return 0;
}