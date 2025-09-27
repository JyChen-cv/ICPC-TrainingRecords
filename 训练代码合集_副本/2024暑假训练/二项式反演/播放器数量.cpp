#include <algorithm>
#include <iostream>
const long long mod = 1e9 + 7;
long long p[(long long)1e6 + 2], inp[(long long)1e6 + 2], g[(long long)1e6 + 2];

inline long long q_pow(long long x, long long y) {
    if (y == 0)
        return 1;
    long long mid = q_pow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}
inline long long inv(long long x) { return q_pow(x, mod - 2); }
inline long long C(long long x, long long y) {
    return p[x] * inp[y] % mod * inp[x - y] % mod;
}

long long numMusicPlaylists(long long n, long long goal, long long k) {
    if (n <= k) {
        int res = 1;
        for (int i = 1; i <= goal; i++) {
            res *= (n + 1 - i);
            res %= mod;
        }
        return res;
    }

    p[0] = 1;
    for (long long i = 1; i <= 1e6; i++) {
        p[i] = p[i - 1] * i % mod;
    }
    inp[(long long)1e6] = inv(p[(long long)1e6]);
    for (long long i = 999999; i >= 0; i--) {
        inp[i] = inp[i + 1] * (i + 1) % mod;
    }

    for (long long i = 0; i <= n; i++) {
        long long res = 1;
        long long now = n - i;
        for (long long j = 1; j <= goal; j++) {
            res *= now;
            now = std::max(n - i - k, now - 1);
            res %= mod;
        }
        g[i] = res;
    }

    for (long long i = 0; i <= std::min(n, goal); i++) {
        // std::cout << i << " " << g[i] << std::endl;
        g[i] = g[i] * C(n, i) % mod;
    }
    long long ans = 0;
    for (long long i = 0; i <= std::min(goal, n); i++) {
        if (n - i <= k && n - i < goal) continue;
        if ((i - 0) % 2 == 0) {
            ans += C(i, 0) * g[i] % mod;
        } else {
            ans += C(i, 0) * g[i] % mod * (mod - 1) % mod;
        }
        // ans+=mod;
        ans %= mod;
        // std::cout << i << " " << ans << std::endl;
    }
    return ans;
}
int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;
    std::cout << numMusicPlaylists(a, b, c) << std::endl;
    return 0;
}